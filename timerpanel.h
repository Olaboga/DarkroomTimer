#ifndef TIMERPANEL_H
#define TIMERPANEL_H

#include <QWidget>
#include <qboxlayout.h>
#include <qframe.h>

class TimerPanel : public QFrame
{
    Q_OBJECT
public:
    explicit TimerPanel(QWidget *parent = nullptr);
    explicit TimerPanel(QString panelName, QWidget* parent = nullptr);

public slots:
    void startTimer();

signals:
    void timerDone();

private:
    QVBoxLayout* m_layout;
};

#endif // TIMERPANEL_H
