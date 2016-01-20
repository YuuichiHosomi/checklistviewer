#include "defines.h"
#include "inifile.h"


///////////////////////////////////////////////////////////////////////////////////
const QString IniParams[NUM_OF_PARAMETERS] = {
    "Host",
    "service", 
    "login" , 
    "password" ,
    "device", 
    "deviceid", 
    "platform", 
    "platformversion", 
    "appversion", 
    "locale", 
    "timezone",
    "Timeout",
    "RPC.Host",
    "RPC.Port",
};

///////////////////////////////////////////////////////////////////////////////////
const QString IniDefaults[NUM_OF_PARAMETERS] = {
    "https://dev-auth.simplexsolutionsinc.com/",
    "com.braininstock.ToDoChecklist",
    "",
    "",
    "DEV",
    "11",
    "Android",
    "4.3",
    MAKE_VERSION_STRING(VERSION_MAJOR,VERSION_MINOR),
    QIniFile::getLocaleDefault(),
    QIniFile::getTimezoneDefault(),
    "20" /*sec*/,
    "rpc.v1.keepsolid.com",
    "443",
};

///////////////////////////////////////////////////////////////////////////////////
QIniFile::QIniFile()
    : QSettings(DEF_INI_NAME, QSettings::IniFormat)
{
}

void QIniFile::Save()
{
}

QString QIniFile::key(ServiceParam key) const
{
    return IniParams[key];
}

QString QIniFile::value(ServiceParam key) const
{

    QString getVal = QSettings::value(IniParams[key]).toString();
    return getVal.isEmpty() ? IniDefaults[key] : getVal;
}

void QIniFile::setValue(ServiceParam key, const QString& value)
{
    QSettings::setValue(IniParams[key], value);
}

void QIniFile::refresh(ServiceParam key)
{
    // refresh default value when setting not exists
    setValue(key, value(key));
}

QString QIniFile::getLocaleDefault()
{
    return "en_US";
}

QString QIniFile::getTimezoneDefault()
{
    return "+0200";
}
