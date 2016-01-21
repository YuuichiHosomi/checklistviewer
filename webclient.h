#ifndef __webclient_h__
#define __webclient_h__

#include "requesthandler.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QThread>
#include <QMutex>
#include <QSharedPointer>

/////////////////////////////////////////////////////////
class WebClient : public QThread, public RequestHandler
{
    Q_OBJECT

public:
    typedef QMap<QString,QString> ParamsT;

    WebClient(RequestHandler* handler, const QUrl& url);
    void postLogon(const ParamsT& params);

    void abort();

    QString errorString() const;
    QString redirectInfo() const;

    const QByteArray* getDataReceived() const
    { return dataReceived_.data(); }

protected:
    void run();
    void onFinished(const QString& status);
    void onReadyRead();
    void onStateChanged(ConnectionState state);

protected Q_SLOTS:
    void readyRead();
    void finished();
    void connectionError(QNetworkReply::NetworkError);

private:
    QByteArray createContentBase64(const ParamsT& params);

    QNetworkAccessManager netmgr_;
    QUrl url_;

    QMutex threadSafe_;
    RequestHandler* handler_;

    QSharedPointer<QNetworkReply> reply_;
    QSharedPointer<QByteArray> dataReceived_;

    ConnectionState state_;
};

#endif /* __webclient_h__ */
