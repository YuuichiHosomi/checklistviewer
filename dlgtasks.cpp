#include "dlgtasks.h"
#include "inifile.h"
#include "sslclient.h"
#include "htmreport.h"

#include <QtWidgets>
#include <QThread>
#include <QtGui>

const char* sampleJsonTask = "\
{\
   \"notes\" : \"\",\
   \"remindOnDate\" : 1,\
   \"invitee\" : \"\",\
   \"remindOnLocation\" : {\
     \"coordinates\" : {\
       \"longitude\" : -94.45029699999999,\
       \"latitude\" : 39.229199\
     },\
     \"onEnter\" : true,\
     \"description\" : \"1307 Amesbury Avenue, Liberty, MO 64068, USA\",\
     \"radius\" : 100\
   },\
   \"alias\" : \"task-d780df97-a304-469b-aafc-1a32a1813d3a\",\
   \"version\" : \"1.3\",\
   \"creationDate\" : 1407248877,\
   \"completed\" : false,\
   \"title\" : \"Buy more coffee\"\
}\
";

const char* sampleJsonTasksList = "\
{\
    \"tasks\" : [\
        \"task-ca0320c5-e160-40ec-8653-4e92efbebfd7\",\
        \"task-cbddb181-a86e-4aaa-9187-1eaf513b1579\",\
        \"task-f3e90530-3f58-4642-80d7-bddb2ce55230\"\
    ],\
    \"title\" : \"Home tasks\",\
    \"alias\" : \"list-0e0b3cab-c65a-42e6-b6b6-825a3492db46\"\
}\
";

TasksDialog::TasksDialog(QWidget* parent, const QIniFile& ini, const QString& sessionId) 
    : QDialog(parent), 
    ini_(ini), 
    sessionId_(sessionId),
    state_(Initial),
    report_(NULL)
{
    QFont bold = font();
    bold.setBold(true);

    // adjust minimum width by sample text
    QString sample = tr("This is sample to set the minimal window's width with sample.url.text:port");
    QRect adjustRc = QFontMetrics(bold).boundingRect(sample);
    if( adjustRc.width() )
        setMinimumWidth(adjustRc.width());

    QVBoxLayout* vlayout = new QVBoxLayout();
    QGroupBox* groupBox = new QGroupBox(this);

    QHBoxLayout* hlayout = new QHBoxLayout();
    groupBox->setLayout(hlayout);
    groupBox->setContentsMargins(0,0,0,0);

    hlayout->addWidget( status_ = new QLabel(this) );
    status_->setFont(bold);
    hlayout->addWidget( disconnectButton_ = new QPushButton(tr("Abort")));
    disconnectButton_->hide();

    vlayout->addWidget(groupBox);
    vlayout->setAlignment(groupBox, Qt::AlignTop);
    setLayout(vlayout);

    QTimer::singleShot(0, this, SLOT(establish()));
    setWindowTitle(tr("Session {") + sessionId + "}");
}

TasksDialog::~TasksDialog()
{}

void TasksDialog::establish()
{
    connection_.reset(new SslClient(this));
    connection_->establish(ini_.value(QIniFile::RPCHost), ini_.value(QIniFile::RPCPort).toInt() );
}

void TasksDialog::disconnect()
{
    if( !connection_.isNull() )
    {
        connection_->close();
        connection_.reset();
    }
    onStateChanged(Canceled);
}

// implements RequestHandler
void TasksDialog::onReadyRead()
{
    if( connection_.isNull() )
        return;
    
    if( report_ )
        report_->clear();

    int count = connection_->metadataElementsCount();
    for(int c=count; c; c--)
    {
        SslClient::WorkGroupType type;
        const QByteArray* rawData = connection_->metadataElement(c-1, &type);
        if( rawData == NULL ) continue;
        if( report_ == NULL )
        {
            QVBoxLayout* vlayout = qobject_cast<QVBoxLayout*>(layout());
            report_ = new HtmReport(this);
            vlayout->addWidget(report_);
        }

        JsonParser parser(*rawData);
        if( parser.hasError() ) {
            QMessageBox::information( NULL, tr("Parse error"), tr("%1").arg( parser.getParseError() ));
            continue;
        }
        
        if( type == SslClient::TaskType )
            report_->addTask( parser.createTaskDocument() );
        else if( type == SslClient::TasksListType )
            report_->addTasksList( parser.createTasksListDocument() );
        else
            continue;
    }

    if( report_ )
        report_->refresh();
}

void TasksDialog::onFinished(const QString& status)
{
    if( connection_.isNull() )
        return;

    if( status == SslClient::InfoReady || status == SslClient::InfoError )
    {
        updateStatus(status);
        emit onReadyRead();
    }
    else if( status == SslClient::InfoEstablished )
    {
        emit connection_->sendRequest(sessionId_);
    }
}

QString TasksDialog::errorString() const
{
    return connection_.isNull() ? "" : connection_->lastError();
}

QString TasksDialog::redirectInfo() const
{ return ""; }

const QByteArray* TasksDialog::getDataReceived() const
{
    return NULL;
}

void TasksDialog::onStateChanged(ConnectionState state)
{
    if(state_ != Canceled && state_ == state)
        return;
    state_ = state;

    if( state == Initial )
        updateStatus(SslClient::InfoReady);
    else if( state == Established ) 
    {
        //updateStatus(SslClient::InfoEstablished);
        onFinished(SslClient::InfoEstablished);
    }
    else if( state == InProgress )
        updateStatus(SslClient::InfoConnecting);
    else if( state == Canceled )
        updateStatus(errorString().isEmpty() ? SslClient::InfoCanceled : SslClient::InfoError);
}

void TasksDialog::updateStatus(QString info)
{
    QString stylesheet;
    ConnectionState state = Initial;
    if( info == SslClient::InfoConnecting ) 
    {
        info += " " + ini_.value(QIniFile::RPCHost) + ":" + ini_.value(QIniFile::RPCPort);
        stylesheet = "QLabel {color: #009922}";
        QCursor* ovrCur = QApplication::overrideCursor();
        if( ovrCur == NULL || ovrCur->shape() != Qt::WaitCursor )
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        state = InProgress;
    }
    else if( info == SslClient::InfoCanceled ) 
    {
        stylesheet = "QLabel {color: #444400}";
        QApplication::restoreOverrideCursor();
        state = Canceled;
    }
    else if( info == SslClient::InfoError ) 
    {
        info = (errorString().isEmpty() ? "" : errorString());
        stylesheet = "QLabel {color: #990000}";
        QApplication::restoreOverrideCursor();
        state = Canceled;

        QRect adjustRc = QFontMetrics(font()).boundingRect(info);
        int w = status_->width() - 75;
        if(adjustRc.width() && adjustRc.width() > w ) {
            resize( width()+adjustRc.width()-w , height() );
            updateGeometry();
        }
    }
    else {
        stylesheet = "QLabel {color: 0}";
        QApplication::restoreOverrideCursor();
        state = Established;
    }

    status_->setText(info);
    status_->setStyleSheet(stylesheet);
    status_->update();

    adjustConnectionButton(state);
}

void TasksDialog::adjustConnectionButton(ConnectionState state)
{
    QString label;
    if( state == Canceled || state == Initial ) {
        label = tr("Connect");
        QObject::disconnect(disconnectButton_, SIGNAL(clicked()), this, SLOT(disconnect()));
        QObject::connect(disconnectButton_, SIGNAL(clicked()), this, SLOT(establish()));
    }
    else if( state == InProgress ) {
        label = tr("Abort");
        QObject::disconnect(disconnectButton_, SIGNAL(clicked()), this, SLOT(establish()));
        QObject::connect(disconnectButton_, SIGNAL(clicked()), this, SLOT(disconnect()));
    }

    disconnectButton_->setFixedWidth(label.length()*10);
    disconnectButton_->setText(label);
    disconnectButton_->setVisible(state != Established);
}
