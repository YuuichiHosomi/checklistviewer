#ifndef __inifile_h__
#define __inifile_h__

#include <QSettings>
#include <QString>

class QIniFile : public QSettings
{
public:
    enum ServiceParam {
        Host = 0,
        Service,
        Login,
        Password,
        Device,
        DeviceId,
        Platform,
        PlatformVer,
        AppVer,
        Locale,
        Timezone,
        Timeout,
        RPCHost,
        RPCPort,
    };

    // 
public:
    QIniFile();
    void Save();

    QString key(ServiceParam key) const;
    QString value(ServiceParam key) const;
    void setValue(ServiceParam key, const QString& value);
    void refresh(ServiceParam key);

protected:
    void Load();

public:
    static QString getLocaleDefault();
    static QString getTimezoneDefault();
};

#define NUM_OF_PARAMETERS 14
extern const QString IniParams[NUM_OF_PARAMETERS];
extern const QString IniDefaults[NUM_OF_PARAMETERS];

#endif /* __inifile_h__ */
