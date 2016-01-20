#include "dlglogininfo.h"
#include "htmreport.h"

#include <QtWidgets>
#include <QtGui>

LoginInfoDialog::LoginInfoDialog(QWidget* parent) 
    : QDialog(parent),
    status_(0)
{
    QString sample = tr("This is sample to set the minimal window's width with sample login information bla-bla-bla-bla-bla");
    QRect adjustRc = QFontMetrics(font()).boundingRect(sample);
    if( adjustRc.width() )
        setMinimumWidth(adjustRc.width());

    setWindowTitle(tr("Login Response"));
}

int LoginInfoDialog::exec(const LoginResponseDocument& doc)
{
    QVBoxLayout* vlayout = new QVBoxLayout();
    HtmReport* report = new HtmReport(this);
    
    status_ = doc.response;

    if( status_ < 300 )
        setMinimumHeight(width());

    QString caption = (status_ < 300 ? tr("Continue") : tr("Close") );
    QPushButton* btn = new QPushButton(caption);
    btn->setFixedWidth(caption.length()*10);

    QObject::connect(btn, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout* hlayout = new QHBoxLayout();
    hlayout->addWidget( btn );

    vlayout->addWidget( report );
    vlayout->addLayout( hlayout );
    vlayout->setAlignment( hlayout, Qt::AlignRight );
    setLayout(vlayout);

    report->applyLoginInfo(doc);
    report->refresh();
    return QDialog::exec();
}

bool LoginInfoDialog::event(QEvent* e)
{
    if( e->type() == QEvent::Close && !e->spontaneous() && status_ < 300)
        accept();
    return QDialog::event(e);
}
