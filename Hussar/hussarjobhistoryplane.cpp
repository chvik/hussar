#include <QtDebug>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include <QStyle>
#include "hussarjobhistoryplane.h"
#include "hussarjobview.h"

HussarJobHistoryPlane::HussarJobHistoryPlane(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    layout->addStretch();
    setLayout(layout);
}

void HussarJobHistoryPlane::resizeEvent(QResizeEvent *event)
{
    qDebug() << "resize" << size();
    emit resized();
}

/** this is required for the stylesheet support */
void HussarJobHistoryPlane::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void HussarJobHistoryPlane::addJobView(HussarJobView *jobView)
{
    layout()->addWidget(jobView);
}
