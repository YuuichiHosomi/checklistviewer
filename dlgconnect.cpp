#include "defines.h"
#include "dlgconnect.h"
#include "defedit.h"
#include "inifile.h"
#include "webclient.h"
#include "jsonparser.h"
#include "dlgtasks.h"
#include "dlglogininfo.h"

#include <QtWidgets>

const char* sampleJsonLoginResponse = "\
{\
    \"response\" : 200,\
    \"responsedetails\" : 0,\
    \"session\" : \"b0a674d8-1381-41d7-8b2e-c991095795a5\",\
    \"ws_session\" : \"dd1cea90-9d73-4218-90b3-6678ff263a09\",\
    \"eventsession\" : \"bc34447b-2ce9-4db9-9021-aa0effa09efa\",\
    \"userinfo\" : {\
        \"id\" : 2444663,\
        \"username\" : \"kscheck002@mailinator.com\",\
        \"firstname\" : \"\",\
        \"lastname\" : \"\",\
        \"registration_datetime\" : \"1446107953.16882\",\
        \"confirmed\" : true,\
        \"trial\" : true,\
        \"extra_devices\" : 0,\
        \"banned\" : false,\
        \"ban_reason\" : null,\
        \"balance_paid\" : 0,\
        \"balance_rewards\" : 0,\
        \"subscription\" : \"weekly\",\
        \"avatar\" : null,\
        \"need_confirmation\" : false,\
        \"confirmation_datetime\" : null,\
        \"lastlogin\" : \"1449570961.76016\",\
        \"firstlogin\" : false,\
        \"name\" : \"kscheck002@mailinator.com\",\
        \"login_type\" : \"native\",\
        \"autologin_url\" : \"https://dev-my.keepsolid.com/auth/b0a674d8_1381_41d7_8b2e_c991095795a5/2ed1597593869f578f1488e42f5e4fc65345af79dae830fcdd1a3b7303e18d56/ba6db3504977a8dbc4f21ad1ab2beb82344765d3cc5afb5e02d02ce8be1fcb13\",\
        \"invites_available\" : true\
    },\
    \"cryptokeys\": {\
        \"id\" : 4333780,\
        \"username\" : \"kscheck002@mailinator.com\",\
        \"type\" : \"native\",\
        \"login\" : \"kscheck002@mailinator.com\",\
        \"public_key\" : \"-----BEGIN PUBLIC KEY-----\nMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA24mEVZTZ57lckPcMhPQz\nDoUE1F31Jjjk0Ysi6ZICfzcqA2R9TBUwB6s+StXJAoPhzunTT4D2ev7e2AEyoERG\nJrHYuh6v2S0IxCIGMK6aX4gUZTKVZxJRa+J3CnJ05hQs0fHDeIttdNKuL++cNMkC\nRMZMHNHbHLIMrdSz/+uMEGwvBdi4FN3wnGYj90kI4RT3UdVDxF3HPIz82Di2Yeb8\naizGzwh8qDBVct95uRpN/Y62hnk3tS1n4PuASkgpLxARh8/xoSvO+dJqv7vYlGWd\n7XG8RlSORnzYT92UrWCn6xM6ius9UJhEBskoHe0yT2JohxhJcpSmVbe8KGXA3RO4\nOQIDAQAB\n-----END PUBLIC KEY-----\n\",\
        \"private_key\" : \"-----BEGIN ENCRYPTED PRIVATE KEY-----\nMIIFDjBABgkqhkiG9w0BBQ0wMzAbBgkqhkiG9w0BBQwwDgQI0/e9ypgWJvECAggA\nMBQGCCqGSIb3DQMHBAjV+B1hbVekEQSCBMjXxeP9NiJzZreDQ0Lz4pPqr6jy67O6\nVQDCg093aQjxFYoPNvnxpbXTM4D6m6OPNCZY4lQoJIceibNhhZ70+QAtXwkBkN9Q\nDwC0GVU60D46Gm5GEDG8/YfKH9N+nX+5lM1bRvZvbL3Lm2TcMczQWnDN27mO0U45\ntR0/qJz1r6l6Ws8A092MctWlnGG5GK0DM98JWOg2YDHH8Ku2S/hDYSVsavyV4h6t\nDY2m009nDeRugZ4RK22qxcRh6OCIfJeLK1lwegK1e+dMmklgyaFPcf+dMmCZcCqa\nBdaFdv5iiUppTkQOwLt5fM+bUC7IPUSZa9d/XJoxv93GNzj99wzxJ4x/jdq7SjD8\n6ijnZkpGkHp3yPaPJSqiG/4EpO75yrd0i3P9d8DpBPsyMUq5NygdaiXNfo5ibp1I\n2CMSRjhosuIb8YwyeCG8qM3EvavsmVHjJybsFT8foVyrI44WhWa36tF4yHueh4qx\nIcg9bKEEYtMhkhqkv1suqy6hIfpkkg0109MZ+0sXeSVTtPKvEEzhluJUkO7Uuo/F\nCstjyASAks78DBq/PuOoScmmPD0Gvr9KwaV7busEV9+hTH3kfSHg7o2haz+A3Cw1\nddx8aBbCui6r3uIELJBxzHxaFZ2Nm/t34OYfNuMNki0kzNO9tU6V0uIbLuKO2O9t\n9Jr3XTSTcewVpGyfvKR9py8e4fHaWhgKAWfdQIzUvQpH3BlD6oJc7lbyWe5zniT9\nUB2ips4RLceBw4OGmkZprmuDbxrzgx8IOcfc69AzEUiDj0D+4pZ/JnDU/rRZjvxb\nQvcpeAemIbz7iyO0/uhVZCVaziW2GrLC3zrwowOMv6QPEKn5VH9WMdYmZqsyzhJA\nrNVJwqgfgW5vD/eTi7+U0UcdmbtMS7aoQ7lf8DtALrA2A82oNUg/GuKbnlVmH6NI\n1ZvQ3Aktc8ozDi+C2ryinfJm7DHz6OE8iyIg8B28H2Ed8eLRLCRsHAMJXsKeqfQ5\nj2aRFArS4nVbbSteXi1yTFp7l6tk3NAYum7A2EnlLX3sdh5GsRSKiN1N71pDcJlz\nI9q4ukuDPHX7i3Jm2GXqmqe7oAWhcBbQqxl+lV55qUWSoVvh8GC37Pik6C0eIav2\n47ujM8oaG7s7safMyHXRSMgvrKo4ZK98sD+4RWQi4pJq/O3t3dp1Xfa5Umq32VL2\nA8E6GoGVL1Bba1/e6oUNCIbZ/p1sh9GPXwD3jx0VLQeG0PYg9jEE397rNka5YklL\nPmNRZP+ZamSD3jLiIxGA40oxJao+C4ErHfBwYXS9ZFMFeh+WbFeao+Cant1dMDrD\nX/4JJztTolycwRLMP96jAisuAih1+o1cHKaiT9xIMBkVjlQI8AWxdcFO2lyF0PUc\nViQY5mHzAin256TR9C4KsDGIv1CPhGo1AOkM6EUZJc1vF1/N1oC3iStVwId3NYyf\nScMPcxjRXap/BWwjJv+n6kYO/0E7W+Wjnrk6XhDegvS4ok+KZ8P1t+At+iNcty1r\nQJSK4JJX2Cpp0UAYZ//ZuSqYKyZmwtQ8Nwcnixlm3d3N+6IozUD3oE/mzlK6YXLg\nzbbS4Zebn4skF7loykZD4ffWwEhZ7werP6u5reQp2uPiYN988n49AGEq/0LG5NUY\nxp8=\n-----END ENCRYPTED PRIVATE KEY-----\n\",\
        \"private_key_salt\" : \"sha256$32768$zJsbUh9D4gOTJ+J988p0YsDrFLA+SThi/lFhDF5xMXY=\",\
        \"active\" : true\
    }\
}\
";

ConnectDialog::ConnectDialog(QIniFile& ini) 
    : ini_(ini)
{
    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->addWidget( createLoginGroup() );
    vlayout->addWidget( createSettingsGroup() );

    QObject::connect(loginButton_ = new QPushButton(tr("Login")), SIGNAL(clicked()), this, SLOT(onLogin()));
    loginButton_->setFixedWidth(width()/5);
    vlayout->addWidget(loginButton_);
    setLayout(vlayout);

    setWindowTitle(tr("Checklist Login"));
}

ConnectDialog::~ConnectDialog()
{
    // flush settings before destroying
    ini_.setValue(QIniFile::Host,        host_->text());
    ini_.setValue(QIniFile::Service,     service_->text());
    ini_.setValue(QIniFile::Login,       login_->text());
    ini_.setValue(QIniFile::Password,    password_->text());
    ini_.setValue(QIniFile::Device,      devicename_->text());
    ini_.setValue(QIniFile::DeviceId,    deviceid_->text());
    ini_.setValue(QIniFile::Platform,    platform_->text());
    ini_.setValue(QIniFile::PlatformVer, platformversion_->text());
    ini_.setValue(QIniFile::AppVer,      appversion_->text());
    ini_.setValue(QIniFile::Locale,      locale_->text());
    ini_.setValue(QIniFile::Timezone,    timezone_->text());

    // non-configurable from UI
    ini_.refresh(QIniFile::Timeout);
    ini_.refresh(QIniFile::RPCHost);
    ini_.refresh(QIniFile::RPCPort);
}

QWidget* ConnectDialog::createLoginGroup()
{
    QGroupBox* groupBox = new QGroupBox(tr("Login"));
    QHBoxLayout* layout;
    groupBox->setLayout(layout = new QHBoxLayout());
    layout->addWidget( login_ = new QDefEdit(this, ini_.value(QIniFile::Login), tr("Login")) );
    layout->addWidget( password_ = new QDefEdit(this, ini_.value(QIniFile::Password), tr("Password")) );
    password_->setEchoMode(QLineEdit::Password);

    return groupBox;
}

QWidget* ConnectDialog::createSettingsGroup()
{
    QGroupBox* groupBox = new QGroupBox(tr("Settings"));
    QVBoxLayout* layout = new QVBoxLayout();
    groupBox->setLayout(layout);
    layout->addWidget( host_ = new QDefEdit(this, ini_.value(QIniFile::Host), tr("Service Host")) );
    layout->addWidget( service_ = new QDefEdit(this, ini_.value(QIniFile::Service), tr("Service URI")) );
    layout->addWidget( devicename_ = new QDefEdit(this, ini_.value(QIniFile::Device), tr("Device Name")) );
    layout->addWidget( deviceid_ = new QDefEdit(this, ini_.value(QIniFile::DeviceId), tr("Device ID")) );
    layout->addWidget( platform_ = new QDefEdit(this, ini_.value(QIniFile::Platform), tr("Platform")) );
    layout->addWidget( platformversion_ = new QDefEdit(this, ini_.value(QIniFile::PlatformVer), tr("Platform Version")) );
    layout->addWidget( appversion_ = new QDefEdit(this, ini_.value(QIniFile::AppVer), tr("Application Version")) );
    layout->addWidget( locale_ = new QDefEdit(this, ini_.value(QIniFile::Locale), tr("Locale (eg: \"en_US\")")) );
    layout->addWidget( timezone_ = new QDefEdit(this, ini_.value(QIniFile::Timezone), tr("Timezone (eg: \"+0200\")")) );
    return groupBox;
}

void ConnectDialog::cancelLogin()
{
    if( !connection_.isNull() )
        connection_->abort();
}

void ConnectDialog::onLogin()
{
    if( !QSslSocket::supportsSsl() ) {
        QMessageBox::information(NULL, "SSL", "OpenSSL libraries not found!");
        close();
        return;
    }

    connection_.reset(new WebClient(this, host_->text()));

    WebClient::ParamsT parameters;
    parameters.insert("action",                         "login");
    parameters.insert(ini_.key(QIniFile::Service),      service_->text());
    parameters.insert(ini_.key(QIniFile::Login),        login_->text());
    parameters.insert(ini_.key(QIniFile::Password),     password_->text());
    parameters.insert(ini_.key(QIniFile::Device),       devicename_->text());
    parameters.insert(ini_.key(QIniFile::DeviceId),     deviceid_->text());
    parameters.insert(ini_.key(QIniFile::Platform),     platform_->text());
    parameters.insert(ini_.key(QIniFile::PlatformVer),  platformversion_->text());
    parameters.insert(ini_.key(QIniFile::AppVer),       appversion_->text());
    parameters.insert(ini_.key(QIniFile::Locale),       locale_->text());
    parameters.insert(ini_.key(QIniFile::Timezone),     timezone_->text());

/*
    JsonParser parser(QByteArray(sampleJsonLoginResponse, strlen(sampleJsonLoginResponse)));
    if( parser.hasError() ) {
        QMessageBox::information(NULL, tr("Parse error"), tr("%1").arg(parser.getParseError()));
        return;
    }
    if( LoginInfoDialog(this).exec(parser.createLoginResponseDocument()) )
        TasksDialog(this, ini_, "session12345").exec();
*/
    connection_->postLogon(parameters);

    qint32 timeout = ini_.value(QIniFile::Timeout).toInt() * 1000;
    qDebug() << "ConnectDialog::onLogin, timeout " << timeout;
    if( !connection_->wait(100) )
        QMessageBox::information( 
            NULL, tr("Network error"), tr("Request is timed out (%1 ms)").arg(timeout) );
}

void ConnectDialog::onStateChanged(ConnectionState state)
{
    if( state == InProgress ) {
        QCursor* ovrCur = QApplication::overrideCursor();
        if( ovrCur == NULL || ovrCur->shape() != Qt::WaitCursor )
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        QObject::disconnect(loginButton_, SIGNAL(clicked()), this, SLOT(onLogin()));
        QObject::connect(loginButton_, SIGNAL(clicked()), this, SLOT(cancelLogin()));
        loginButton_->setText("Abort");
    }
    else {
        QApplication::restoreOverrideCursor();
        QObject::disconnect(loginButton_, SIGNAL(clicked()), this, SLOT(cancelLogin()));
        QObject::connect(loginButton_, SIGNAL(clicked()), this, SLOT(onLogin()));
        loginButton_->setText("Login");
    }
    loginButton_->update();
}

void ConnectDialog::onFinished(const QString& status)
{
    if( status.toInt() < 100 ) {
        QMessageBox::information( 
            NULL, tr("Network"), tr("Request failed: %1").arg(errorString()) );
    }
    else if( status.toInt() > 399) {
        QMessageBox::information( 
            NULL, tr("Network"), tr("Request failed (%1): %2").arg(status, errorString()) );
    }
    else if( status.toInt() > 299 ) {
        QMessageBox::information( 
            NULL, tr("Network"), tr("Request redirect (%1): %2").arg(status, redirectInfo()) );
    }
}

void ConnectDialog::onReadyRead()
{
    const QByteArray* data = getDataReceived();
    if( data == NULL ) 
        return;

    JsonParser parser(*data);
    if( parser.hasError() ) {
        QMessageBox::information(NULL, tr("Parse error"), tr("%1").arg(parser.getParseError()));
        return;
    }

    LoginResponseDocument doc = parser.createLoginResponseDocument();
    if( LoginInfoDialog(this).exec(doc) )
        TasksDialog(this, ini_, doc.session).exec();
}

QString ConnectDialog::errorString() const
{
    return connection_.isNull() ? "" : connection_->errorString();
}

QString ConnectDialog::redirectInfo() const
{
    return connection_.isNull() ? "" : connection_->redirectInfo();
}

const QByteArray* ConnectDialog::getDataReceived() const
{
    return connection_.isNull() ? NULL : connection_->getDataReceived();
}
