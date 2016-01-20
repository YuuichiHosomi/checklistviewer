#include "sslclient.h"
#include "requesthandler.h"

#include <QtWidgets/QMessageBox>
#include <QtNetwork/QSslCipher>

////////////////
QString SslClient::InfoEstablished = tr("Established"); // success connection
QString SslClient::InfoReady = tr("Ready"); // data available for reading
QString SslClient::InfoConnecting = tr("Connecting"); // request or connection in progress
QString SslClient::InfoCanceled = tr("Canceled"); // interrupted by user choice
QString SslClient::InfoError = tr("Error"); // error was during a last operation

////////////////
SslClient::SslClient(RequestHandler* handler) 
    : handler_(handler)
{
    connect(this, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));
    connect(this, SIGNAL(encrypted()), this, SLOT(socketEncrypted()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(sslErrors(QList<QSslError>)));
    connect(this, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
    connect(this, SIGNAL(readChannelFinished()), this, SLOT(socketReadyRead()));
}

SslClient::~SslClient()
{
}

void SslClient::establish(const QString& host, quint16 port)
{
    handler_->onStateChanged(RequestHandler::InProgress);
    connectToHostEncrypted(host, port);
}

void SslClient::sendRequest(const QString& alias)
{
    handler_->onStateChanged(RequestHandler::InProgress);
    write( *createRequest(alias) );
    clearCache();
}

void SslClient::socketStateChanged(QAbstractSocket::SocketState state)
{
    qDebug() << "SslClient::socketStateChanged " << state;

    RequestHandler::ConnectionState uiState = RequestHandler::Initial;
    switch(state)
    {
    case UnconnectedState:
    case ClosingState:
        uiState = RequestHandler::Canceled;
        break;
    case HostLookupState:
    case ConnectingState:
        uiState = RequestHandler::InProgress;
        break;
    case ConnectedState:
    case BoundState:
    case ListeningState:
        uiState = RequestHandler::Established;
        break;
    }

    handler_->onStateChanged(uiState);
}

void SslClient::socketEncrypted()
{
    QSslCipher ciph = sessionCipher();
    QString cipher = QString("%1, %2 (%3/%4)").arg(ciph.authenticationMethod())
                     .arg(ciph.name()).arg(ciph.usedBits()).arg(ciph.supportedBits());
}

void SslClient::socketReadyRead()
{
    if( !bytesAvailable() )
        return;
    
    if( !cacheIt( readAll() ) ) {
        setIOError(parseError());
        handler_->onStateChanged(parseError().isEmpty() ? RequestHandler::InProgress : RequestHandler::Canceled);
    }
    else 
        handler_->onFinished(InfoReady);
    flush();
}

void SslClient::socketError(QAbstractSocket::SocketError err)
{
    if( lastError().isEmpty() ) {
        QString output;
        QDebug dbg(&output);
        dbg << err;
        setIOError(output);
    }

    handler_->onFinished(InfoError);
}

void SslClient::sslErrors(const QList<QSslError>& errors)
{
    Q_UNUSED(errors);

    ignoreSslErrors();
    if( state() != QAbstractSocket::ConnectedState )
        socketStateChanged(state());
}
