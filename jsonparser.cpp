#include "jsonparser.h"

#include <QVariant>
#include <QJsonObject>

QJsonParseError JsonParser::parserError_;

///////////////////////////////////////////////////////////////////////////////////
JsonParser::JsonParser(const QByteArray& data) 
{
    parserError_ = QJsonParseError();
    *static_cast<QJsonDocument*>(this) = fromJson(data, &parserError_);
}

JsonParser& JsonParser::operator=(const QByteArray& data)
{
    parserError_ = QJsonParseError();
    *static_cast<QJsonDocument*>(this) = fromJson(data, &parserError_);
    return *this;
}

bool JsonParser::hasError() const
{
    return parserError_.error != QJsonParseError::NoError;
}

QString JsonParser::getParseError() const
{
    return parserError_.errorString();
}

#ifdef WIN32
#pragma warning(disable:4996)
#endif
TaskDocument JsonParser::createTaskDocument() const
{
    TaskDocument task;

    QJsonObject doc = object();
    QJsonObject::iterator It = doc.begin();
    for(; It != doc.end(); ++It ) 
    {
        if( It.key() == "title" )
            task.title = It.value().toString();
        else if( It.key() == "alias" )
            task.alias = It.value().toString();
        else if( It.key() == "notes" )
            task.notes = It.value().toString();
        else if( It.key() == "invitee" )
            task.invitee = It.value().toString();
        else if( It.key() == "version" )
            task.version = It.value().toString();
        else if( It.key() == "remindOnDate" )
            task.remindOnDate = It.value().toInt();
        else if( It.key() == "completed" )
            task.completed = It.value().toBool();
        else if( It.key() == "creationDate" )
            task.creationDate = It.value().toVariant().toLongLong();
        else if( It.key() == "remindOnLocation" && It.value().toVariant().type() == QVariant::Map )
        {
            QVariantMap locMap = It.value().toVariant().toMap();
            QVariantMap::const_iterator locIt = locMap.cbegin();
            for(; locIt != locMap.cend(); ++locIt)
            {
                if( locIt.key() == "description" )
                    task.remindOnLocation_description = locIt.value().toString();
                else if( locIt.key() == "onEnter" )
                    task.remindOnLocation_onEnter = locIt.value().toBool();
                else if( locIt.key() == "radius" )
                    task.remindOnLocation_radius = locIt.value().toInt();
                else if( locIt.key() == "coordinates" && locIt.value().type() == QVariant::Map )
                {
                    QVariantMap coordMap = locIt.value().toMap();
                    QVariantMap::const_iterator coordIt = coordMap.cbegin();
                    for(; coordIt != coordMap.cend(); ++coordIt)
                    {
                        char frounded[30];
                        if( coordIt.key() == "longitude" ) {
                            sprintf(frounded,"%f",coordIt.value().toReal());
                            task.remindOnLocation_coordinates_x = frounded;
                        }
                        else if( coordIt.key() == "latitude" ) {
                            sprintf(frounded,"%f",coordIt.value().toReal());
                            task.remindOnLocation_coordinates_y = frounded;
                        }
                    }
                }
            }
        }
    }
    return task;
}

TasksListDocument JsonParser::createTasksListDocument() const
{
    TasksListDocument list;
    QJsonObject doc = object();
    QJsonObject::iterator It = doc.begin();
    for(; It != doc.end(); ++It ) {
        if( It.key() == "title" )
            list.title = It.value().toString();
        else if( It.key() == "alias" )
            list.alias = It.value().toString();
        else if( It.key() == "tasks" && It.value().isArray() ) 
        {
            QVariantList tsList = It.value().toVariant().toList();
            QVariantList::const_iterator tsIt = tsList.cbegin();
            for(; tsIt != tsList.cend(); ++tsIt)
                list.tasks.push_back(tsIt->toString());
        }
    }
    return list;
}

LoginResponseDocument JsonParser::createLoginResponseDocument() const
{
    LoginResponseDocument response;
    QJsonObject doc = object();
    QJsonObject::iterator It = doc.begin();
    for(; It != doc.end(); ++It) 
    {
        if( It.key() == "response" )
            response.response = It.value().toInt();
        if( It.key() == "responsedetails" )
            response.responsedetails = It.value().toInt();
        else if( It.key() == "session" )
            response.session = It.value().toString();
        else if( It.key() == "ws_session" )
            response.ws_session = It.value().toString();
        else if( It.key() == "eventsession" )
            response.eventsession = It.value().toString();
        else if( It.key() == "userinfo" && It.value().toVariant().type() == QVariant::Map )
        {
            QVariantMap userinfo = It.value().toVariant().toMap();
            QVariantMap::const_iterator uiIt = userinfo.cbegin();
            for(; uiIt != userinfo.cend(); ++uiIt)
            {
                if( uiIt.key() == "id" )
                    response.userinfo_id = uiIt.value().toInt();
                else if( uiIt.key() == "username" )
                    response.userinfo_username = uiIt.value().toString();
                else if( uiIt.key() == "firstname" )
                    response.userinfo_firstname = uiIt.value().toString();
                else if( uiIt.key() == "lastname" )
                    response.userinfo_lastname = uiIt.value().toString();
                else if( uiIt.key() == "registration_datetime" )
                    response.userinfo_registration_datetime = uiIt.value().toString();
                else if( uiIt.key() == "confirmed" )
                    response.userinfo_confirmed = uiIt.value().toBool();
                else if( uiIt.key() == "trial" )
                    response.userinfo_trial = uiIt.value().toBool();
                else if( uiIt.key() == "extra_devices" )
                    response.userinfo_extra_devices = uiIt.value().toInt();
                else if( uiIt.key() == "banned" )
                    response.userinfo_banned = uiIt.value().toBool();
                else if( uiIt.key() == "ban_reason" )
                    response.userinfo_ban_reason = uiIt.value().toString();
                else if( uiIt.key() == "balance_paid" ) {
                    char fbuf[20];
                    sprintf(fbuf,"%.2f",uiIt.value().toReal());
                    response.userinfo_balance_paid = fbuf;
                }
                else if( uiIt.key() == "balance_rewards" ) {
                    char fbuf[20];
                    sprintf(fbuf,"%.2f",uiIt.value().toReal());
                    response.userinfo_balance_rewards = fbuf;
                }
                else if( uiIt.key() == "subscription" )
                    response.userinfo_subscription = uiIt.value().toString();
                else if( uiIt.key() == "need_confirmation" )
                    response.userinfo_need_confirmation = uiIt.value().toBool();
                else if( uiIt.key() == "confirmation_datetime" )
                    response.userinfo_confirmation_datetime = uiIt.value().toString();
                else if( uiIt.key() == "lastlogin" )
                    response.userinfo_lastlogin = uiIt.value().toString();
                else if( uiIt.key() == "firstlogin" )
                    response.userinfo_firstlogin = uiIt.value().toBool();
                else if( uiIt.key() == "name" )
                    response.userinfo_name = uiIt.value().toString();
                else if( uiIt.key() == "login_type" )
                    response.userinfo_login_type = uiIt.value().toString();
                else if( uiIt.key() == "autologin_url" )
                    response.userinfo_autologin_url = uiIt.value().toString();
                else if( uiIt.key() == "invites_available" )
                    response.userinfo_invites_available = uiIt.value().toBool();
            }
        } 
        else if( It.key() == "cryptokeys" && It.value().toVariant().type() == QVariant::Map )
        {
            QVariantMap cryptokeys = It.value().toVariant().toMap();
            QVariantMap::const_iterator ckIt = cryptokeys.cbegin();
            for(; ckIt != cryptokeys.cend(); ++ckIt)
            {
                if( ckIt.key() == "id" )
                    response.cryptokeys_id = ckIt.value().toInt();
                else if( ckIt.key() == "username" )
                    response.cryptokeys_username = ckIt.value().toString();
                else if( ckIt.key() == "type" )
                    response.cryptokeys_type = ckIt.value().toString();
                else if( ckIt.key() == "login" )
                    response.cryptokeys_login = ckIt.value().toString();
                else if( ckIt.key() == "public_key" )
                    response.cryptokeys_public_key = ckIt.value().toString();
                else if( ckIt.key() == "private_key" )
                    response.cryptokeys_private_key = ckIt.value().toString();
                else if( ckIt.key() == "private_key_salt" )
                    response.cryptokeys_private_key_salt = ckIt.value().toString();
                else if( ckIt.key() == "active" )
                    response.cryptokeys_type = ckIt.value().toBool();
            }
        }
    }
    return response;
}
