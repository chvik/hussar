#ifndef HUSSARJOBVIEW_H
#define HUSSARJOBVIEW_H

#include <QProcess>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>

class HussarJobView : public QWidget
{
    Q_OBJECT
public:
    explicit HussarJobView(QWidget *parent = 0);
    void setCommandLine(const QString &commandLine);
    void setProcess(QProcess *process);

signals:

public slots:

private slots:
    void onStdOutReadReady();
    void onStdErrReadReady();
    void onProcessFinished(int, QProcess::ExitStatus);

private:
    virtual void resizeEvent(QResizeEvent *event);
    void loadDataFromStdOut();
    void loadDataFromStdErr();

    QLabel *commandLineView;
    QTextEdit *outputView;
    QProcess *process;
};

#endif // HUSSARJOBVIEW_H
