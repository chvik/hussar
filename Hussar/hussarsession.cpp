#include <QtDebug>
#include "hussarsession.h"

HussarSession::HussarSession(QObject *parent) :
    QObject(parent)
{
}

void HussarSession::execute(const QString &command)
{
    qDebug() << command;
    emit jobCreated(command);
}
