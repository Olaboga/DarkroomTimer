#include "timerwidget.h"
#include <QTimer>

TimerWidget::TimerWidget(QWidget *parent)
    : QWidget{parent}
{

}

TimerWidget::TimerWidget(int duration, QWidget* parent)
    : QWidget{parent}, m_duration(duration)
{
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=](){
        if(m_currTime <= m_duration)
        {
            ++m_currTime;
            update();
        }

        if(m_currTime == m_duration)
            emit timeOut();
    });
    timer->start(1000);
}

QSize TimerWidget::sizeHint() const
{
    return QSize(150, 150);
}

QSize TimerWidget::minimumSizeHint() const
{
    return QSize(100, 100);
}

void TimerWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    auto w = width();
    auto h = height();
    auto size = qMin(w, h) - 10;
    QRectF rect((w - size) / 2, (h - size) / 2, size, size);

    painter.setPen(QPen(Qt::black, 10));
    painter.drawEllipse(rect);

    painter.setPen((QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap)));
    auto fill = static_cast<float>(m_currTime) / static_cast<float>(m_duration);
    auto spanAngle = static_cast<int>(fill*16*360);
    painter.drawArc(rect, 90 * 16, -spanAngle);
}
