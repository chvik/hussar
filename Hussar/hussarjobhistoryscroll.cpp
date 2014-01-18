#include <QLabel>
#include <QScrollBar>
#include <QtDebug>
#include "hussarjobhistoryscroll.h"
#include "hussarjobhistoryplane.h"
#include "hussarjobview.h"

HussarJobHistoryScroll::HussarJobHistoryScroll(HussarSession *session, QWidget *parent) :
    QScrollArea(parent),
    session(session)
{
    connect(session, SIGNAL(jobCreated(QString,QProcess *)), this, SLOT(onJobCreated(QString, QProcess*)));
    historyPlane = new HussarJobHistoryPlane();
    setWidget(historyPlane);
    setAlignment(Qt::AlignBottom);
    setWidgetResizable(true);
    connect(historyPlane, SIGNAL(resized()), this, SLOT(onContentResized()));
    connect(verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(onScrollRangeChanged(int,int)));
}

void HussarJobHistoryScroll::onJobCreated(const QString &command, QProcess *process)
{
    HussarJobView *jobView = new HussarJobView();
    jobView->setCommandLine(command);
    jobView->setProcess(process);
    historyPlane->addJobView(jobView);
    qDebug() << "max" << verticalScrollBar()->maximum();
    verticalScrollBar()->setValue(verticalScrollBar()->maximum());
}

void HussarJobHistoryScroll::onContentResized()
{
    qDebug() << "max2" << verticalScrollBar()->maximum();
    verticalScrollBar()->setValue(verticalScrollBar()->maximum());
}

void HussarJobHistoryScroll::onScrollRangeChanged(int min, int max)
{
    qDebug() << "scroll range" << min << max;
}
