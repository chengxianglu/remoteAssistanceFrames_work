#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>

#include <QFont>

#include "mainwindow.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
//    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    QFont font("Microsoft YaHei", 12, 75);
    a.setFont(font);
//    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setTheme("light");
//    a.setOrganizationName("deepin");
//    a.setApplicationName("远程协助");
//    a.setApplicationVersion("1.0");
//    a.setProductIcon(QIcon(":/images/logo.svg"));
//    a.setProductName("Dtk Application");
//    a.setApplicationDescription("This is a dtk template application.");

    MainWindow w;
    w.setWindowFlags(w.windowFlags()&~Qt::WindowMaximizeButtonHint);
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
