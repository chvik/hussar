#ifndef HUSSARJOBVIEW_H
#define HUSSARJOBVIEW_H

#include <QWidget>
#include <QLabel>

class HussarJobView : public QWidget
{
    Q_OBJECT
public:
    explicit HussarJobView(QWidget *parent = 0);
    void setContent(const QString &content);

signals:

public slots:

private:
    virtual void resizeEvent(QResizeEvent *event);

    QLabel *content;
};

#endif // HUSSARJOBVIEW_H
