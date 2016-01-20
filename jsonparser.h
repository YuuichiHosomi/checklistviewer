#ifndef __jsonparser_h__
#define __jsonparser_h__

#include <QJsonDocument>
#include <QPoint>
#include <QList>

/*
{
    "response" : 200,
    "responsedetails" : 0,
    "session" : "b0a674d8-1381-41d7-8b2e-c991095795a5",
    "ws_session" : "dd1cea90-9d73-4218-90b3-6678ff263a09",
    "eventsession" : "bc34447b-2ce9-4db9-9021-aa0effa09efa",
    "userinfo" : { 
        "id" : 2444663,
        "username" : "kscheck002@mailinator.com",
        "firstname" : "",
        "lastname" : "",
        "registration_datetime" : "1446107953.16882",
        "confirmed" : true, 
        "trial" : true,
        "extra_devices" : 0,
        "banned" : false,
        "ban_reason" : null,
        "balance_paid" : 0,
        "balance_rewards" : 0,
        "subscription" : "weekly",
        "avatar" : null,
        "need_confirmation" : false,
        "confirmation_datetime" : null,
        "lastlogin" : "1449570961.76016",
        "firstlogin" : false,
        "name" : "kscheck002@mailinator.com",
        "login_type" : "native",
        "autologin_url" : "https:\/\/dev-my.keepsolid.com\/auth\/b0a674d8_1381_41d7_8b2e_c991095795a5\/2ed1597593869f578f1488e42f5e4fc65345af79dae830fcdd1a3b7303e18d56\/ba6db3504977a8dbc4f21ad1ab2beb82344765d3cc5afb5e02d02ce8be1fcb13",
        "invites_available" : true
    },
    "cryptokeys": {
        "id" : 4333780,
        "username" : "kscheck002@mailinator.com",
        "type" : "native",
        "login" : "kscheck002@mailinator.com",
        "public_key" : "-----BEGIN PUBLIC KEY-----\nMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA24mEVZTZ57lckPcMhPQz\nDoUE1F31Jjjk0Ysi6ZICfzcqA2R9TBUwB6s+StXJAoPhzunTT4D2ev7e2AEyoERG\nJrHYuh6v2S0IxCIGMK6aX4gUZTKVZxJRa+J3CnJ05hQs0fHDeIttdNKuL++cNMkC\nRMZMHNHbHLIMrdSz\/+uMEGwvBdi4FN3wnGYj90kI4RT3UdVDxF3HPIz82Di2Yeb8\naizGzwh8qDBVct95uRpN\/Y62hnk3tS1n4PuASkgpLxARh8\/xoSvO+dJqv7vYlGWd\n7XG8RlSORnzYT92UrWCn6xM6ius9UJhEBskoHe0yT2JohxhJcpSmVbe8KGXA3RO4\nOQIDAQAB\n-----END PUBLIC KEY-----\n",
        "private_key" : "-----BEGIN ENCRYPTED PRIVATE KEY-----\nMIIFDjBABgkqhkiG9w0BBQ0wMzAbBgkqhkiG9w0BBQwwDgQI0\/e9ypgWJvECAggA\nMBQGCCqGSIb3DQMHBAjV+B1hbVekEQSCBMjXxeP9NiJzZreDQ0Lz4pPqr6jy67O6\nVQDCg093aQjxFYoPNvnxpbXTM4D6m6OPNCZY4lQoJIceibNhhZ70+QAtXwkBkN9Q\nDwC0GVU60D46Gm5GEDG8\/YfKH9N+nX+5lM1bRvZvbL3Lm2TcMczQWnDN27mO0U45\ntR0\/qJz1r6l6Ws8A092MctWlnGG5GK0DM98JWOg2YDHH8Ku2S\/hDYSVsavyV4h6t\nDY2m009nDeRugZ4RK22qxcRh6OCIfJeLK1lwegK1e+dMmklgyaFPcf+dMmCZcCqa\nBdaFdv5iiUppTkQOwLt5fM+bUC7IPUSZa9d\/XJoxv93GNzj99wzxJ4x\/jdq7SjD8\n6ijnZkpGkHp3yPaPJSqiG\/4EpO75yrd0i3P9d8DpBPsyMUq5NygdaiXNfo5ibp1I\n2CMSRjhosuIb8YwyeCG8qM3EvavsmVHjJybsFT8foVyrI44WhWa36tF4yHueh4qx\nIcg9bKEEYtMhkhqkv1suqy6hIfpkkg0109MZ+0sXeSVTtPKvEEzhluJUkO7Uuo\/F\nCstjyASAks78DBq\/PuOoScmmPD0Gvr9KwaV7busEV9+hTH3kfSHg7o2haz+A3Cw1\nddx8aBbCui6r3uIELJBxzHxaFZ2Nm\/t34OYfNuMNki0kzNO9tU6V0uIbLuKO2O9t\n9Jr3XTSTcewVpGyfvKR9py8e4fHaWhgKAWfdQIzUvQpH3BlD6oJc7lbyWe5zniT9\nUB2ips4RLceBw4OGmkZprmuDbxrzgx8IOcfc69AzEUiDj0D+4pZ\/JnDU\/rRZjvxb\nQvcpeAemIbz7iyO0\/uhVZCVaziW2GrLC3zrwowOMv6QPEKn5VH9WMdYmZqsyzhJA\nrNVJwqgfgW5vD\/eTi7+U0UcdmbtMS7aoQ7lf8DtALrA2A82oNUg\/GuKbnlVmH6NI\n1ZvQ3Aktc8ozDi+C2ryinfJm7DHz6OE8iyIg8B28H2Ed8eLRLCRsHAMJXsKeqfQ5\nj2aRFArS4nVbbSteXi1yTFp7l6tk3NAYum7A2EnlLX3sdh5GsRSKiN1N71pDcJlz\nI9q4ukuDPHX7i3Jm2GXqmqe7oAWhcBbQqxl+lV55qUWSoVvh8GC37Pik6C0eIav2\n47ujM8oaG7s7safMyHXRSMgvrKo4ZK98sD+4RWQi4pJq\/O3t3dp1Xfa5Umq32VL2\nA8E6GoGVL1Bba1\/e6oUNCIbZ\/p1sh9GPXwD3jx0VLQeG0PYg9jEE397rNka5YklL\nPmNRZP+ZamSD3jLiIxGA40oxJao+C4ErHfBwYXS9ZFMFeh+WbFeao+Cant1dMDrD\nX\/4JJztTolycwRLMP96jAisuAih1+o1cHKaiT9xIMBkVjlQI8AWxdcFO2lyF0PUc\nViQY5mHzAin256TR9C4KsDGIv1CPhGo1AOkM6EUZJc1vF1\/N1oC3iStVwId3NYyf\nScMPcxjRXap\/BWwjJv+n6kYO\/0E7W+Wjnrk6XhDegvS4ok+KZ8P1t+At+iNcty1r\nQJSK4JJX2Cpp0UAYZ\/\/ZuSqYKyZmwtQ8Nwcnixlm3d3N+6IozUD3oE\/mzlK6YXLg\nzbbS4Zebn4skF7loykZD4ffWwEhZ7werP6u5reQp2uPiYN988n49AGEq\/0LG5NUY\nxp8=\n-----END ENCRYPTED PRIVATE KEY-----\n",
        "private_key_salt" : "sha256$32768$zJsbUh9D4gOTJ+J988p0YsDrFLA+SThi\/lFhDF5xMXY=",
        "active" : true 
    }
}
*/
struct LoginResponseDocument
{
    qint32  response;
    qint32  responsedetails;
    QString session;
    QString ws_session;
    QString eventsession;

    qint32  userinfo_id;
    QString userinfo_username;
    QString userinfo_firstname;
    QString userinfo_lastname;
    QString userinfo_registration_datetime;
    bool    userinfo_confirmed;
    bool    userinfo_trial;
    qint32  userinfo_extra_devices;
    bool    userinfo_banned;
    QString userinfo_ban_reason;
    QString userinfo_balance_paid;
    QString userinfo_balance_rewards;
    QString userinfo_subscription;
    bool    userinfo_need_confirmation;
    QString userinfo_confirmation_datetime;
    QString userinfo_lastlogin;
    bool    userinfo_firstlogin;
    QString userinfo_name;
    QString userinfo_login_type;
    QString userinfo_autologin_url;
    bool    userinfo_invites_available;

    qint32  cryptokeys_id;
    QString cryptokeys_username;
    QString cryptokeys_type;
    QString cryptokeys_login;
    QString cryptokeys_public_key;
    QString cryptokeys_private_key;
    QString cryptokeys_private_key_salt;
    bool    cryptokeys_active;
};

/*
{
    "tasks" : [
        "task-ca0320c5-e160-40ec-8653-4e92efbebfd7",
        "task-cbddb181-a86e-4aaa-9187-1eaf513b1579",
        "task-f3e90530-3f58-4642-80d7-bddb2ce55230"
    ],
    "title" : "Home tasks",
    "alias" : "list-0e0b3cab-c65a-42e6-b6b6-825a3492db46"
}
*/
struct TasksListDocument 
{
    QString  title;
    QString  alias;
    QList<QString> tasks;
};

/*
{
   "notes" : "",
   "remindOnDate" : 0,
   "invitee" : "",
   "remindOnLocation" : {
     "coordinates" : {
       "longitude" : -94.45029699999999,
       "latitude" : 39.229199
     },
     "onEnter" : true,
     "description" : "1307 Amesbury Avenue, Liberty, MO 64068, USA",
     "radius" : 100
   },
   "alias" : "task-d780df97-a304-469b-aafc-1a32a1813d3a",
   "version" : "1.3",
   "creationDate" : 1407248877,
   "completed" : false,
   "title" : "Buy more coffee"
 } 
*/
struct TaskDocument 
{
    QString  title;
    QString  alias;
    QString  notes;
    QString  invitee;
    QString  version;
    qint64   creationDate;
    qint32   remindOnDate;
    bool     completed;

    QString  remindOnLocation_description;
    qint32   remindOnLocation_radius;
    bool     remindOnLocation_onEnter;

    QString  remindOnLocation_coordinates_x;
    QString  remindOnLocation_coordinates_y;
};

class JsonParser : public QJsonDocument
{
public:
    JsonParser(const QByteArray& data);
    JsonParser& operator=(const QByteArray& data);

    bool hasError() const;
    QString getParseError() const;

    TaskDocument createTaskDocument() const;
    TasksListDocument createTasksListDocument() const;
    LoginResponseDocument createLoginResponseDocument() const;

protected:

private:
    static QJsonParseError parserError_;
};

#endif /* __jsonparser_h__ */
