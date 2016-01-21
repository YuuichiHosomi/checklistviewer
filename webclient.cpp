#include "defines.h"
#include "webclient.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMutexLocker>
#include <QMessageBox>

///////////////////////////////////////////////////////////////////////////////////
WebClient::WebClient(RequestHandler* handler, const QUrl& url) 
    : handler_(handler), 
    url_(url), 
    state_(Initial)
{}

void WebClient::postLogon(const ParamsT& params)
{
    QNetworkRequest request;
    request.setUrl(url_.toString() + params["service"] );
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray content = createContentBase64(params);
    qDebug() << "POST Sending: " << content;

    reply_.reset( netmgr_.post(request, content) );
    connect(reply_.data(), SIGNAL(finished()),
            this, SLOT(finished()));
    connect(reply_.data(), SIGNAL(readyRead()),
            this, SLOT(readyRead()));
    connect(reply_.data(), SIGNAL(error(NetworkError)),
            this, SLOT(connectionError(NetworkError)));

    QMutexLocker guard(&threadSafe_);
    handler_->onStateChanged(state_ = InProgress);
}

void WebClient::run()
{
    qDebug() << "WebClient thread has start.";

    QMutexLocker guard(&threadSafe_);
    if( state_ == InProgress )
        handler_->onStateChanged(state_ = Established);
}

void WebClient::abort()
{
    {
        QMutexLocker guard(&threadSafe_);
        handler_->onStateChanged(state_ = Canceled);
    }
    reply_->abort();
    start();
}

void WebClient::finished()
{
    {
        QMutexLocker guard(&threadSafe_);
        QVariant status = reply_->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        handler_->onFinished( status.toString() );

        if( state_ == InProgress )
            start();
        else
            return;
    }

    dataReceived_.reset(new QByteArray());
    QByteArray bytes = reply_->readAll();
    if( bytes.size() ) {
        qDebug() << "Reply received: " << QString::fromLocal8Bit(bytes); 
        dataReceived_->swap(bytes);
        handler_->onReadyRead();
    }
}

void WebClient::connectionError(QNetworkReply::NetworkError err)
{
    Q_UNUSED(err);
    abort();
}

void WebClient::readyRead()
{}

QString WebClient::errorString() const
{
    return reply_.isNull() ? "" : reply_->errorString();
}

QString WebClient::redirectInfo() const
{
    return reply_.isNull() ? "" : reply_->attribute(QNetworkRequest::RedirectionTargetAttribute).toString();
}

QByteArray WebClient::createContentBase64(const ParamsT& params)
{
    QByteArray content;
    ParamsT::const_iterator It = params.cbegin();
    for(; It != params.cend(); ++It ) {
        content += It.key().toLocal8Bit() + "=" + It.value().toLocal8Bit().toBase64();
        if( It+1 != params.cend() )
            content += "&";
    }
    return content;
}

void WebClient::onReadyRead()
{
}

void WebClient::onFinished(const QString& status) 
{ Q_UNUSED(status); }

void WebClient::onStateChanged(ConnectionState state)
{ Q_UNUSED(state); }

