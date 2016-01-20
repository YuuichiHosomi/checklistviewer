#ifndef __dlgtasks_h__
#define __dlgtasks_h__

#include "requesthandler.h"

#include <QDialog>

class SslClient;
class HtmReport;

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class QIniFile;

class TasksDialog : public QDialog, public RequestHandler
{
    Q_OBJECT

public:
    TasksDialog(QWidget* parent, const QIniFile& ini_, const QString& sessionId);
    ~TasksDialog();

protected:
    void onFinished(const QString& status);
    void onStateChanged(ConnectionState state);

    QString errorString() const;
    QString redirectInfo() const;
    const QByteArray* getDataReceived() const;

protected Q_SLOTS:
    void onReadyRead();
    void establish();
    void disconnect();

private:
    void adjustConnectionButton(ConnectionState state);
    void updateStatus(QString info);

    QString sessionId_;
    const QIniFile& ini_;
    QLabel* status_;
    QPushButton* disconnectButton_;

    QSharedPointer<SslClient> connection_;
    ConnectionState state_;
    HtmReport* report_;
};

#endif /* __dlgtasks_h__ */
