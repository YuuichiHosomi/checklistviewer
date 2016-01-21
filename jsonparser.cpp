#include "jsonparser.h"

#include <QVariant>
#include <QJsonObject>
#include <stdio.h>

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
        const QJsonValue& refVal = It.value();
        if( It.key() == "title" )
            task.title = refVal.toString();
        else if( It.key() == "alias" )
            task.alias = refVal.toString();
        else if( It.key() == "notes" )
            task.notes = refVal.toString();
        else if( It.key() == "invitee" )
            task.invitee =  refVal.toString();
        else if( It.key() == "version" )
            task.version = refVal.toString();
        else if( It.key() == "remindOnDate" )
            task.remindOnDate = refVal.toInt();
        else if( It.key() == "completed" )
            task.completed = refVal.toBool();
        else if( It.key() == "creationDate" )
            task.creationDate = refVal.toVariant().toLongLong();
        else if( It.key() == "remindOnLocation" && refVal.toVariant().type() == QVariant::Map )
        {
            QVariantMap locMap = refVal.toVariant().toMap();
            QVariantMap::const_iterator locIt = locMap.cbegin();
            for(; locIt != locMap.cend(); ++locIt)
            {
                const QVariant& refLoc = locIt.value();
                if( locIt.key() == "description" )
                    task.remindOnLocation_description = refLoc.toString();
                else if( locIt.key() == "onEnter" )
                    task.remindOnLocation_onEnter = refLoc.toBool();
                else if( locIt.key() == "radius" )
                    task.remindOnLocation_radius = refLoc.toInt();
                else if( locIt.key() == "coordinates" && refLoc.type() == QVariant::Map )
                {
                    QVariantMap coordMap = refLoc.toMap();
                    QVariantMap::const_iterator coordIt = coordMap.cbegin();
                    for(; coordIt != coordMap.cend(); ++coordIt)
                    {
                        char frounded[30];
                        if( coordIt.key() == "longitude" ) {
                            sprintf(frounded,"%f",coordIt->toReal());
                            task.remindOnLocation_coordinates_x = frounded;
                        }
                        else if( coordIt.key() == "latitude" ) {
                            sprintf(frounded,"%f",coordIt->toReal());
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
        const QJsonValue& refVal = It.value();
        if( It.key() == "title" )
            list.title = refVal.toString();
        else if( It.key() == "alias" )
            list.alias = refVal.toString();
        else if( It.key() == "tasks" && refVal.isArray() )
        {
            QVariantList tsList = refVal.toVariant().toList();
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
        const QJsonValue& refVal = It.value();
        if( It.key() == "response" )
            response.response = refVal.toInt();
        if( It.key() == "responsedetails" )
            response.responsedetails = refVal.toInt();
        else if( It.key() == "session" )
            response.session = refVal.toString();
        else if( It.key() == "ws_session" )
            response.ws_session = refVal.toString();
        else if( It.key() == "eventsession" )
            response.eventsession = refVal.toString();
        else if( It.key() == "userinfo" && refVal.toVariant().type() == QVariant::Map )
        {
            QVariantMap userinfo = refVal.toVariant().toMap();
            QVariantMap::const_iterator uiIt = userinfo.cbegin();
            for(; uiIt != userinfo.cend(); ++uiIt)
            {
                const QVariant& refUi = uiIt.value();
                if( uiIt.key() == "id" )
                    response.userinfo_id = refUi.toInt();
                else if( uiIt.key() == "username" )
                    response.userinfo_username = refUi.toString();
                else if( uiIt.key() == "firstname" )
                    response.userinfo_firstname = refUi.toString();
                else if( uiIt.key() == "lastname" )
                    response.userinfo_lastname = refUi.toString();
                else if( uiIt.key() == "registration_datetime" )
                    response.userinfo_registration_datetime = refUi.toString();
                else if( uiIt.key() == "confirmed" )
                    response.userinfo_confirmed = refUi.toBool();
                else if( uiIt.key() == "trial" )
                    response.userinfo_trial = refUi.toBool();
                else if( uiIt.key() == "extra_devices" )
                    response.userinfo_extra_devices = refUi.toInt();
                else if( uiIt.key() == "banned" )
                    response.userinfo_banned = refUi.toBool();
                else if( uiIt.key() == "ban_reason" )
                    response.userinfo_ban_reason = refUi.toString();
                else if( uiIt.key() == "balance_paid" ) {
                    char fbuf[20];
                    sprintf(fbuf,"%.2f",refUi.toReal());
                    response.userinfo_balance_paid = fbuf;
                }
                else if( uiIt.key() == "balance_rewards" ) {
                    char fbuf[20];
                    sprintf(fbuf,"%.2f",refUi.toReal());
                    response.userinfo_balance_rewards = fbuf;
                }
                else if( uiIt.key() == "subscription" )
                    response.userinfo_subscription = refUi.toString();
                else if( uiIt.key() == "need_confirmation" )
                    response.userinfo_need_confirmation = refUi.toBool();
                else if( uiIt.key() == "confirmation_datetime" )
                    response.userinfo_confirmation_datetime = refUi.toString();
                else if( uiIt.key() == "lastlogin" )
                    response.userinfo_lastlogin = refUi.toString();
                else if( uiIt.key() == "firstlogin" )
                    response.userinfo_firstlogin = refUi.toBool();
                else if( uiIt.key() == "name" )
                    response.userinfo_name = refUi.toString();
                else if( uiIt.key() == "login_type" )
                    response.userinfo_login_type = refUi.toString();
                else if( uiIt.key() == "autologin_url" )
                    response.userinfo_autologin_url = refUi.toString();
                else if( uiIt.key() == "invites_available" )
                    response.userinfo_invites_available = refUi.toBool();
            }
        } 
        else if( It.key() == "cryptokeys" && refVal.toVariant().type() == QVariant::Map )
        {
            QVariantMap cryptokeys = refVal.toVariant().toMap();
            QVariantMap::const_iterator ckIt = cryptokeys.cbegin();
            for(; ckIt != cryptokeys.cend(); ++ckIt)
            {
                const QVariant& refCk = ckIt.value();
                if( ckIt.key() == "id" )
                    response.cryptokeys_id = refCk.toInt();
                else if( ckIt.key() == "username" )
                    response.cryptokeys_username = refCk.toString();
                else if( ckIt.key() == "type" )
                    response.cryptokeys_type = refCk.toString();
                else if( ckIt.key() == "login" )
                    response.cryptokeys_login = refCk.toString();
                else if( ckIt.key() == "public_key" )
                    response.cryptokeys_public_key = refCk.toString();
                else if( ckIt.key() == "private_key" )
                    response.cryptokeys_private_key = refCk.toString();
                else if( ckIt.key() == "private_key_salt" )
                    response.cryptokeys_private_key_salt = refCk.toString();
                else if( ckIt.key() == "active" )
                    response.cryptokeys_type = refCk.toBool();
            }
        }
    }
    return response;
}
