#ifndef __dlgconnect_h__
#define __dlgconnect_h__

#include "requesthandler.h"
#include <QDialog>

class QDefEdit;
class QIniFile;
class WebClient;

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

class ConnectDialog : public QDialog, public RequestHandler
{
    Q_OBJECT

public:
    ConnectDialog(QIniFile& ini);
    ~ConnectDialog();

protected:
    QWidget* createLoginGroup();
    QWidget* createSettingsGroup();

    // implements RequestHandler
    void onReadyRead();
    void onFinished(const QString& status);
    void onStateChanged(ConnectionState state);

    QString errorString() const;
    QString redirectInfo() const;
    const QByteArray* getDataReceived() const;

    // UI slots
protected Q_SLOTS:
    void onLogin();
    void cancelLogin();
    
private:
    QDefEdit* login_;
    QDefEdit* password_;
    QDefEdit* host_;
    QDefEdit* service_;
    QDefEdit* devicename_;
    QDefEdit* deviceid_;
    QDefEdit* platform_;
    QDefEdit* platformversion_;
    QDefEdit* appversion_;
    QDefEdit* locale_;
    QDefEdit* timezone_;

    QPushButton*  loginButton_;

    QIniFile&     ini_;
    QSharedPointer<WebClient> connection_;
};

#endif /* __dlgconnect_h__ */
