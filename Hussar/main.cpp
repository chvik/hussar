#include <QApplication>
#include <QFile>
#include "hussarwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile stylesheetFile(":/hussar.qss");
    if (stylesheetFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        a.setStyleSheet(stylesheetFile.readAll());
        stylesheetFile.close();
    }

    HussarWindow w;
    w.setObjectName("mainWindow");
    w.show();

    return a.exec();
}
