#ifndef HUSSARCOMMANDLINEEDIT_H
#define HUSSARCOMMANDLINEEDIT_H

#include <QLineEdit>
#include "hussarsession.h"

class HussarCommandLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit HussarCommandLineEdit(HussarSession *session,
                                   QWidget *parent = 0);

signals:

public slots:
private slots:
    void onEditingFinished();

private:
    HussarSession *session;
};

#endif // HUSSARCOMMANDLINEEDIT_H
