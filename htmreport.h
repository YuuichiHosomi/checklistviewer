#ifndef __htmreport_h__
#define __htmreport_h__

#include "jsonparser.h"

#include <QTextEdit>

class HtmReport : public QTextEdit
{
    Q_OBJECT

public:
    HtmReport(QWidget* parent);
    ~HtmReport();


    void addTask(const TaskDocument& doc);
    void addTasksList(const TasksListDocument& doc);
    void applyLoginInfo(const LoginResponseDocument& doc);
    void refresh();
    void clear();

    static QString statusHTTPToString(qint32 status);

protected:
    
private:
    QString html_;
};

#endif /* __htmreport_h__ */
