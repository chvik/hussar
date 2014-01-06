#include <QApplication>
#include "hussarwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HussarWindow w;
    w.setObjectName("mainWindow");
    w.show();

    return a.exec();
}
