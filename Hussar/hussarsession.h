#ifndef HUSSARSESSION_H
#define HUSSARSESSION_H

#include <QObject>

class HussarSession : public QObject
{
    Q_OBJECT
public:
    explicit HussarSession(QObject *parent = 0);

signals:
    void jobCreated(const QString &str);

public slots:

public:
    void execute(const QString &command);
};

#endif // HUSSARSESSION_H
