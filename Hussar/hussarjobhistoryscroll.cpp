#include <QVBoxLayout>
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
    connect(session, SIGNAL(jobCreated(QString)), this, SLOT(onJobCreated(QString)));
    scrollContent = new HussarJobHistoryPlane();
    // TODO: HussarJobHistoryPlane manages its own layout
    QVBoxLayout *layout = new QVBoxLayout;
    scrollContent->setLayout(layout);
    qDebug() << "content size" << scrollContent->size() << scrollContent->sizeHint();
    layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    setWidget(scrollContent);
    setAlignment(Qt::AlignBottom);
    setWidgetResizable(true);
    connect(scrollContent, SIGNAL(resized()), this, SLOT(onContentResized()));
    connect(verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(onScrollRangeChanged(int,int)));
}

void HussarJobHistoryScroll::onJobCreated(const QString &str)
{
    HussarJobView *jobView = new HussarJobView();
    jobView->setContent(str);
    // TODO: HussarJobHistoryPlane manages job view addition
    scrollContent->layout()->addWidget(jobView);
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
