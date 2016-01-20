#include "inifile.h"
#include "dlgconnect.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QIniFile ini;
    ConnectDialog loginDlg(ini);
    loginDlg.show();
    app.exec();
    return 0;
}
