#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = nullptr);
    explicit TimerWidget(int duration, QWidget* parent = nullptr);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

signals:
    void timeOut();

protected:
    void paintEvent(QPaintEvent*) override;

private:
    int m_duration;
    int m_currTime = 0;
};

#endif // TIMERWIDGET_H
