#ifndef __sslclient_h__
#define __sslclient_h__

#include "defines.h"
#include "protobuf.h"

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>

class RequestHandler;
class PbSession;

//////////////
class SslClient : public QSslSocket, public PbSession
{
    Q_OBJECT

    friend class QSharedPointer<SslClient>;
public:
    SslClient(RequestHandler* handler);
    virtual ~SslClient();

    void establish(const QString& host, quint16 port);

    inline void setIOError(const QString& error) const { 
        qDebug() << "SslClient::setIOError " << error;
        const_cast<SslClient*>(this)->setErrorString(error); 
    }

    inline QString lastError() const 
    { return errorString(); }


public Q_SLOTS:
    void sendRequest(const QString& alias);

private Q_SLOTS:
    void socketStateChanged(QAbstractSocket::SocketState state);
    void socketEncrypted();
    void socketReadyRead();
    void socketError(QAbstractSocket::SocketError error);
    void sslErrors(const QList<QSslError> &errors);

private:
    RequestHandler* handler_;

public:
    static QString InfoEstablished;
    static QString InfoConnecting;
    static QString InfoCanceled;
    static QString InfoReady;
    static QString InfoError;
};


#endif /* __sslclient_h__ */
