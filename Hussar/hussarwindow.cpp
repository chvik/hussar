#include <QGridLayout>
#include <QDesktopWidget>
#include <QtDebug>

#include "hussarwindow.h"
#include "hussarcommandlineedit.h"
#include "hussarjobhistoryscroll.h"

HussarWindow::HussarWindow(QWidget *parent) :
    QMainWindow(parent),
    session(new HussarSession())
{
    QDesktopWidget dw;
    preferredSize = QSize(dw.width() * 0.5, dw.height() * 0.8);

    HussarCommandLineEdit *cmdEdit = new HussarCommandLineEdit(session);
    HussarJobHistoryScroll *historyPlane = new HussarJobHistoryScroll(session);
    QWidget *content = new QWidget;
    setCentralWidget(content);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(historyPlane, 0, 0);
    layout->addWidget(cmdEdit, 1, 0, 1, 2);
    content->setLayout(layout);
}

QSize HussarWindow::sizeHint() const
{
    return preferredSize;
}
