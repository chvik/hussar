#include <QLayout>
#include <QVBoxLayout>
#include <QtDebug>

#include "hussarjobview.h"

HussarJobView::HussarJobView(QWidget *parent) :
    QWidget(parent),
    content(new QLabel(this))
{
    QLayout *layout = new QVBoxLayout;
    setLayout(layout);
    layout->addWidget(content);
    setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setStyleSheet("* { background: white; border: 1px solid black }");
}

void HussarJobView::setContent(const QString &text)
{
    content->setText(text);
}

void HussarJobView::resizeEvent(QResizeEvent *event)
{
    qDebug() << "HussarJobView resize" << size();
}
