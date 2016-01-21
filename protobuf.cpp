#include "protobuf.h"

/////////////
PbSession::PbSession()
    : seqNum_(-1)
{}

const QByteArray* PbSession::createRequest(const QString& alias)
{
    seqNum_++;

    WorkGroupsListRequest* wglist = WorkGroupsListRequest().New();
    wglist->set_session_id(alias.toStdString());
    wglist->set_filter(ALL_ENTRIES);

    Request sampleReq;
    sampleReq.set_allocated_workgroups_list(wglist);
    sampleReq.set_message_type(RPC_WORKGROUPS_LIST);
    sampleReq.set_service_type(1);
    sampleReq.set_is_debug(true);

    std::string stdString;
    sampleReq.SerializeToString(&stdString);

    PbHeader hdr = {seqNum_++, sampleReq.ByteSize(), 0};
    cache_.reset( new QByteArray((const char*)&hdr.seqNum, sizeof(hdr)) );
    cache_->append(stdString.c_str());

    // release and check the memory integrity
    sampleReq.release_workgroups_list();
    return cache_.data();
}

bool PbSession::cacheIt(const QByteArray& data)
{
    cache_->append(data);
    FILE* f = fopen("proto.incoming", "a+");
    fprintf(f,"\nREAD DATA:\n");
    fwrite(data.data(), 1, data.size(), f);
    fclose(f);

    // parse both header and body, validate fields, obtain metadata
    Response response;
    return parse(response); 
}

bool PbSession::parse(PbHeader& header) const
{
    if( cache_->size() < sizeof(PbHeader)+sizeof(Response) )
        return false;

    const PbHeader* cptr = reinterpret_cast<const PbHeader*>(cache_->data());
    if( cptr->seqNum != seqNum_ ) {
        error_ = QString("Invalid sequence number of protobuf header: expected=%1, ").arg(seqNum_) + 
                 QString("received=%1").arg(cptr->seqNum);
        return false;
    }

    header.seqNum  = cptr->seqNum;
    header.flags   = cptr->flags;
    header.bufsize = cptr->bufsize;
    return (cache_->size() >= header.bufsize+16);
}

bool PbSession::parse(Response& response) const
{
    error_.clear();

    PbHeader hdr;
    if( !parse(hdr) )
        return false;

    if( !response.ParseFromArray(cache_->data()+sizeof(hdr), hdr.bufsize) ) {
        error_ = "Protobuf parsing error (analysis under debug only).";
        qDebug() << "Protobuf parsing error: " << response.DebugString().c_str();
        return false;
    }

    qint32 error_code = response.has_error_code() ? response.error_code() : 0;
    if( error_code >= 300 ) {
        error_ = "Error in protobuf response: ";
        if( error_code )
            error_ += QString(" code=%1 ").arg(error_code);
        for(int c=0; c<response.error_message_size(); ++c)
            error_ += QString(" error%1=").arg(c) + QString::fromStdString(response.error_message(c)) + " ";
        error_ = error_.trimmed();
        return false;
    }

    if( !response.has_message_type() ) {
        error_ = QString("Error in protobuf response: 'message_type' is absent.");
        return false;
    }
    else if( response.message_type() != RPC_WORKGROUPS_LIST && response.message_type() != RPC_UNKNOWN ) {
        error_ = QString("Error in protobuf response: 'message_type=%1'.").arg( response.message_type() );
        return false;
    }

    return validate( response.workgroups_list() );
}

bool PbSession::validate(const WorkGroupInfo& info) const
{
    if( !info.has_workgroup_type() ) {
        error_ = "Error in protobuf WorkGroupInfo: 'workgroup_type' is absent.";
        return false;
    }

    qint32 type = info.workgroup_type();
    if( type != TaskType && type != TasksListType ) {
        error_ = QString("Error in protobuf WorkGroupInfo: undefined 'workgroup_type=%1')").arg(type);
        return false;
    }

    if( !info.has_workgroup_metadata() ) {
        error_ = "Error in protobuf WorkGroupInfo: 'workgroup_metadata' is absent.";
        return false;
    }

    QByteArray metadata( info.workgroup_metadata().c_str() );
    const_cast<MetaListT*>(&metadataList_)->insert(metadata, (WorkGroupType)type);
    return true;
}

bool PbSession::validate(const WorkGroupsListResponse& wglist) const
{
    if( wglist.has_error_code() && wglist.error_code() >= 300 ) {
        error_ = QString("Error in protobuf WorkGroupListResponse: error_code=%1").arg(wglist.error_code());
        return false;
    }

    const_cast<MetaListT*>(&metadataList_)->clear();
    for(int c=0; c<wglist.workgroup_info_list_size();++c)
        if( !validate( wglist.workgroup_info_list(c) ) )
            return false;

    return true;
}

const QByteArray* PbSession::metadataElement(int index, WorkGroupType* type) const
{ 
    const QByteArray* metadata = NULL;
    MetaListT::const_iterator It = metadataList_.cbegin();
    for(int count = 0;  It != metadataList_.cend(); ++It, ++count ) 
    {
        *type = It.value();
        const QByteArray& ref = It.key();
        metadata = &ref;
        if( count == index )
            break;
    }
    return (It == metadataList_.cend() ? NULL :  metadata);
}
