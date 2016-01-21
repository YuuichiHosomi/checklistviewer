#ifndef __protobuf_h__
#define __protobuf_h__


#include <QSharedPointer>
#include <QString>
#include <QByteArray>

#include "defines.h"
#include "message.pb.h"
#include "message_common.pb.h"
#include "message_type.pb.h"
#include "message_workgroup.pb.h"

using namespace rpc;

/////////////////////
struct PbHeader {
    qint64 seqNum;
    qint32 bufsize;
    qint32 flags;
};

/////////////////////
class PbSession
{
public:
    enum WorkGroupType 
    {
        TaskType      = 1001,
        TasksListType = 1002,
    };

    // use parseError() when returns false (error will be empty if buffer is not completed)
    bool parse(PbHeader& header) const;
    bool parse(Response& response) const;

    // metadata accessing
    typedef QMap<QByteArray, WorkGroupType> MetaListT;

    inline int metadataElementsCount() const
    { return metadataList_.count(); }

    const QByteArray* metadataElement(int index, WorkGroupType* type) const;

protected:
    PbSession();
    virtual ~PbSession() {};

    const QByteArray* createRequest(const QString& alias);

    // use parseError() when returns false (error will be empty if buffer is not completed)
    bool cacheIt(const QByteArray& data);

    // validate structures in the cache
    // use parseError() when returns false (error will be empty if buffer is not completed)
    bool validate(const WorkGroupInfo& ginfo) const;
    bool validate(const WorkGroupsListResponse& wglist) const;
    
    inline void clearCache()
    { cache_->clear(); }

    inline const QString& parseError() const
    { return error_; }

private:
    qint64 seqNum_;
    QSharedPointer<QByteArray> cache_;
    mutable QString error_;
    MetaListT metadataList_;
};

#endif /* __protobuf_h__ */
