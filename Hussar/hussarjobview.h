#ifndef HUSSARJOBVIEW_H
#define HUSSARJOBVIEW_H

#include <QProcess>
#include <QWidget>
#include <QLabel>
#include <QPlainTextEdit>

class HussarJobView : public QWidget
{
    Q_OBJECT
public:
    explicit HussarJobView(QWidget *parent = 0);
    void setCommandLine(const QString &commandLine);
    void setProcess(QProcess *process);
    void setMaximized(bool maximized);
    void setMaximumHeight(int height);

signals:

public slots:

private slots:
    void onStdOutReadReady();
    void onStdErrReadReady();
    void onProcessFinished(int, QProcess::ExitStatus);
    void onProcessError(QProcess::ProcessError);
    void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    virtual void resizeEvent(QResizeEvent *event);
    bool eventFilter(QObject *, QEvent *);
    void loadDataFromStdOut();
    void loadDataFromStdErr();
    void updateSize();

    QLabel *commandLineView;
    QPlainTextEdit *outputView;
    QProcess *process;
    bool maximized;
    int maximumHeight;
};

#endif // HUSSARJOBVIEW_H
