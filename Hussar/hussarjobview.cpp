#include <QLayout>
#include <QVBoxLayout>
#include <QtDebug>

#include "hussarjobview.h"

HussarJobView::HussarJobView(QWidget *parent) :
    QWidget(parent),
    commandLineView(new QLabel(this)),
    outputView(new QTextEdit(this)),
    process(0)
{
    outputView->setReadOnly(true);
    QLayout *layout = new QVBoxLayout;
    setLayout(layout);
    layout->addWidget(commandLineView);
    layout->addWidget(outputView);
    setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setStyleSheet("* { background: white; border: 1px solid black }");
}

void HussarJobView::setCommandLine(const QString &commandLine)
{
    commandLineView->setText(commandLine);
}

void HussarJobView::setProcess(QProcess *process)
{
    this->process = process;
    connect(process, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(onProcessFinished(int,QProcess::ExitStatus)));
    connect(process, SIGNAL(readyReadStandardOutput()), SLOT(onStdOutReadReady()));
    connect(process, SIGNAL(readyReadStandardError()), SLOT(onStdErrReadReady()));
}

void HussarJobView::resizeEvent(QResizeEvent *event)
{
    qDebug() << "HussarJobView resize" << size();
}

void HussarJobView::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    loadDataFromStdOut();
    loadDataFromStdErr();
    qDebug() << commandLineView->text() << "finished with" << exitCode;
}

void HussarJobView::onStdOutReadReady()
{
    loadDataFromStdOut();
}

void HussarJobView::onStdErrReadReady()
{
    loadDataFromStdErr();
}

void HussarJobView::loadDataFromStdOut()
{
    QByteArray data = process->readAllStandardOutput();
    QString text(data); // TODO: handle \0 bytes
    outputView->insertPlainText(text);
}

void HussarJobView::loadDataFromStdErr()
{
    QByteArray data = process->readAllStandardError();
    QString text(data); // TODO: \0 bytes
    outputView->insertPlainText(text);
}
