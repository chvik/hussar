#ifndef HUSSARJOBHISTORYPLANE_H
#define HUSSARJOBHISTORYPLANE_H

#include <QWidget>

class HussarJobHistoryPlane : public QWidget
{
    Q_OBJECT

public:
    HussarJobHistoryPlane(QWidget *parent=0);

signals:
    void resized();

protected:
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // HUSSARJOBHISTORYPLANE_H
