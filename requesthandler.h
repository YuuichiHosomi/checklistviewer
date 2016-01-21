#ifndef __requesthandler_h__
#define __requesthandler_h__

#include <QString>
#include <QByteArray>

///////////////////////////
class RequestHandler
{
public:
    enum ConnectionState {
        Initial = 0,
        InProgress,
        Established,
        Canceled,
    };

    virtual ~RequestHandler() {};

    virtual void onReadyRead() = 0;
    virtual void onFinished(const QString& status) = 0;
    virtual void onStateChanged(ConnectionState state) = 0;

    virtual QString errorString() const = 0;
    virtual QString redirectInfo() const = 0;
    virtual const QByteArray* getDataReceived() const = 0;
};

#endif /* __requesthandler_h__ */
