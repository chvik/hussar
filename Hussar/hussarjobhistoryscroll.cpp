#include <QLabel>
#include <QScrollBar>
#include <QtDebug>
#include <QTimer>
#include "hussarjobhistoryscroll.h"
#include "hussarjobhistoryplane.h"
#include "hussarjobview.h"

#define ENSURE_VISIBLE_DELAY 100

HussarJobHistoryScroll::HussarJobHistoryScroll(HussarSession *session, QWidget *parent) :
    QScrollArea(parent),
    session(session),
    maximizedJobView(0)
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
    jobView->setMaximized(true);
    jobView->setMaximumHeight(height());
    minimizeAllExcept(jobView);
    connect(jobView, SIGNAL(maximizeRequested()), this, SLOT(onMaximizeRequested()));
    historyPlane->addJobView(jobView);
    jobViews.append(jobView);
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

void HussarJobHistoryScroll::onMaximizeRequested()
{
    HussarJobView *newMaximizedJobView = qobject_cast<HussarJobView *>(QObject::sender());
    if (newMaximizedJobView) {
        minimizeAllExcept(newMaximizedJobView);
        updateScrollPositionToShowMaximizedJobView();
        maximizedJobView = newMaximizedJobView;
    }
}

void HussarJobHistoryScroll::onMinimizeRequested()
{
    HussarJobView *minimizedJobView = qobject_cast<HussarJobView *>(QObject::sender());
    if (minimizedJobView == maximizedJobView) {
        maximizedJobView = 0;
    }
}

void HussarJobHistoryScroll::minimizeAllExcept(HussarJobView *exceptJobView)
{
    foreach (HussarJobView *jobView, jobViews) {
        if (jobView != exceptJobView) {
            jobView->setMaximized(false);
        }
    }
}

void HussarJobHistoryScroll::updateScrollPositionToShowMaximizedJobView()
{
    QTimer::singleShot(ENSURE_VISIBLE_DELAY, this, SLOT(delayedEnsureVisibleMaximizedJobView()));
}

void HussarJobHistoryScroll::delayedEnsureVisibleMaximizedJobView()
{
    ensureWidgetVisible(maximizedJobView);
}
