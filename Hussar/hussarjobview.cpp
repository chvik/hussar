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
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setStyleSheet("* { background: white; border: 1px solid black }");
}

void HussarJobView::setContent(const QString &text)
{
    QString buf;
    buf.append(text);
    for (int i = 1; i < text.size(); ++i) {
        buf.append("\n");
        buf.append(text);
    }
    content->setText(buf);
}

void HussarJobView::resizeEvent(QResizeEvent *event)
{
    qDebug() << "HussarJobView resize" << size();
}
