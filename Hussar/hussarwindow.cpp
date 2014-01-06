#include <QGridLayout>

#include "hussarwindow.h"
#include "hussarcommandlineedit.h"
#include "hussarjobhistoryscroll.h"

HussarWindow::HussarWindow(QWidget *parent) :
    QMainWindow(parent),
    session(new HussarSession())
{
    HussarCommandLineEdit *cmdEdit = new HussarCommandLineEdit(session);
    HussarJobHistoryScroll *historyPlane = new HussarJobHistoryScroll(session);
    QWidget *content = new QWidget;
    setCentralWidget(content);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(historyPlane, 0, 0);
    layout->addWidget(cmdEdit, 1, 0, 1, 2);
    content->setLayout(layout);
}
