#include <QtDebug>
#include <QProcess>
#include "hussarsession.h"

#define SHELL "bash"

HussarSession::HussarSession(QObject *parent) :
    QObject(parent)
{
}

void HussarSession::execute(const QString &command)
{
    qDebug() << command;
    QProcess *process = new QProcess();
    // TODO: ownership
    process->setProgram(SHELL);
    QStringList args;
    args << "-c" << command;
    process->setArguments(args);
    process->start();
    emit jobCreated(command, process);
}
