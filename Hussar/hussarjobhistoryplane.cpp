#include <QtDebug>
#include "hussarjobhistoryplane.h"

HussarJobHistoryPlane::HussarJobHistoryPlane(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("* { background: yellow }");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void HussarJobHistoryPlane::resizeEvent(QResizeEvent *event)
{
    qDebug() << "resize" << size();
    emit resized();
}
