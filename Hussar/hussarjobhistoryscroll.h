#ifndef HUSSARJOBHISTORYSCROLL_H
#define HUSSARJOBHISTORYSCROLL_H

#include <QScrollArea>
#include "hussarsession.h"

class QProcess;
class HussarJobHistoryPlane;
class HussarJobView;

class HussarJobHistoryScroll : public QScrollArea
{
    Q_OBJECT
public:
    explicit HussarJobHistoryScroll(HussarSession *session, QWidget *parent = 0);

signals:

public slots:

private slots:
    void onJobCreated(const QString &command, QProcess *process);
    void onContentResized();
    void onScrollRangeChanged(int min, int max);
    void onMaximizeRequested();
    void onMinimizeRequested();
    void minimizeAllExcept(HussarJobView *exceptJobView);
    void updateScrollPositionToShowMaximizedJobView();
    void delayedEnsureVisibleMaximizedJobView();

private:
    HussarSession *session;
    HussarJobHistoryPlane *historyPlane;
    QList<HussarJobView *> jobViews;
    HussarJobView *maximizedJobView;
};

#endif // HUSSARJOBHISTORYSCROLL_H
