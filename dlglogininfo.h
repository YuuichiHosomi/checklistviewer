#ifndef __dlglogininfo_h__
#define __dlglogininfo_h__

#include "jsonparser.h"
#include <QDialog>

class LoginInfoDialog : public QDialog
{
public:
    LoginInfoDialog(QWidget* parent);
    int exec(const LoginResponseDocument& doc);

protected:
    bool event(QEvent* e);
    void setupInfo(const LoginResponseDocument& doc);

private:
    qint32 status_;
};

#endif /* __dlglogininfo_h__ */
