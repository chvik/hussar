#ifndef HUSSARJOBHISTORYSCROLL_H
#define HUSSARJOBHISTORYSCROLL_H

#include <QScrollArea>
#include "hussarsession.h"

class QProcess;
class HussarJobHistoryPlane;

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

private:
    HussarSession *session;
    HussarJobHistoryPlane *historyPlane;
};

#endif // HUSSARJOBHISTORYSCROLL_H
