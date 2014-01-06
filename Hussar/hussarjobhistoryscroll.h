#ifndef HUSSARJOBHISTORYSCROLL_H
#define HUSSARJOBHISTORYSCROLL_H

#include <QScrollArea>
#include "hussarsession.h"

class HussarJobHistoryPlane;

class HussarJobHistoryScroll : public QScrollArea
{
    Q_OBJECT
public:
    explicit HussarJobHistoryScroll(HussarSession *session, QWidget *parent = 0);

signals:

public slots:

private slots:
    void onJobCreated(const QString &);
    void onContentResized();
    void onScrollRangeChanged(int min, int max);

private:
    HussarSession *session;
    HussarJobHistoryPlane *historyPlane;
};

#endif // HUSSARJOBHISTORYSCROLL_H
