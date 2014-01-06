#include <QtDebug>
#include <QVBoxLayout>
#include "hussarjobhistoryplane.h"
#include "hussarjobview.h"

HussarJobHistoryPlane::HussarJobHistoryPlane(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("* { background: yellow }");
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

void HussarJobHistoryPlane::addJobView(HussarJobView *jobView)
{
    layout()->addWidget(jobView);
}
