#include <QtDebug>
#include <QProcess>
#include "hussarsession.h"

HussarSession::HussarSession(QObject *parent) :
    QObject(parent)
{
}

void HussarSession::execute(const QString &command)
{
    qDebug() << command;
    QProcess *process = new QProcess();
    // TODO: ownership
    process->start(command);
    emit jobCreated(command, process);
}
