#include <QLayout>
#include <QVBoxLayout>
#include <QtDebug>

#include "hussarjobview.h"

#define MINIMIZED_HEIGHT 5
#define CONTENT_VERTICAL_MARGIN 8 // FIXME

HussarJobView::HussarJobView(QWidget *parent) :
    QWidget(parent),
    commandLineView(new QLabel(this)),
    outputView(new QPlainTextEdit(this)),
    process(0),
    maximized(false),
    requestedMaximumHeight(0)
{
    outputView->setReadOnly(true);
    outputView->installEventFilter(this);
    outputView->viewport()->installEventFilter(this);
    QLayout *layout = new QVBoxLayout;
    setLayout(layout);
    layout->addWidget(commandLineView);
    layout->addWidget(outputView);
    setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setStyleSheet("QPlainTextEdit { background: white; border: 1px solid black } QLabel { background: #cccccc; border: 1px solid black }");
    setMaximized(false);
}

void HussarJobView::setCommandLine(const QString &commandLine)
{
    commandLineView->setText(commandLine);
}

void HussarJobView::setProcess(QProcess *process)
{
    this->process = process;
    connect(process, SIGNAL(finished(int,QProcess::ExitStatus)), SLOT(onProcessFinished(int,QProcess::ExitStatus)));
    connect(process, SIGNAL(error(QProcess::ProcessError)), SLOT(onProcessError(QProcess::ProcessError)));
    connect(process, SIGNAL(readyReadStandardOutput()), SLOT(onStdOutReadReady()));
    connect(process, SIGNAL(readyReadStandardError()), SLOT(onStdErrReadReady()));
}

void HussarJobView::setMaximized(bool maximized)
{
    qDebug() << "setMaximized" << maximized;
    this->maximized = maximized;
    if (maximized) {
        setFocus();
        outputView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        emit maximizeRequested();
    } else {
        clearFocus();
        outputView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }
    updateSize();
}

void HussarJobView::setMaximumHeight(int height)
{
    requestedMaximumHeight = height;
}

void HussarJobView::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "HussarJobView resize" << size();
}

bool HussarJobView::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == outputView || obj == outputView->viewport()) {
        if (!maximized) {
            if (event->type() == QEvent::MouseButtonRelease) {
                mouseReleaseEvent(static_cast<QMouseEvent *>(event));
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress || event->type() == QEvent::Wheel) {
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}

void HussarJobView::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitStatus);
    loadDataFromStdOut();
    loadDataFromStdErr();
    qDebug() << commandLineView->text() << "finished with" << exitCode;
}

void HussarJobView::onProcessError(QProcess::ProcessError error)
{
    qDebug() << commandLineView->text() << "error:" << error;
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
    updateSize();
}

void HussarJobView::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    // FIXME: children should pass this
    qDebug() << "mouse release";
    setMaximized(true);
}

void HussarJobView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        setMaximized(false);
    }
}

void HussarJobView::updateSize()
{
    int lineHeight = outputView->fontMetrics().lineSpacing();
    int textHeight = outputView->document()->size().height() * lineHeight;
    int maximumHeight = qMax(requestedMaximumHeight - outputView->y(), MINIMIZED_HEIGHT * lineHeight);
    if (maximized) {
        outputView->setFixedHeight(qMin(maximumHeight, textHeight) + CONTENT_VERTICAL_MARGIN);
    } else {
        int minHeight = qMin(textHeight, MINIMIZED_HEIGHT * lineHeight);
        outputView->setFixedHeight(minHeight + CONTENT_VERTICAL_MARGIN);
    }
}
