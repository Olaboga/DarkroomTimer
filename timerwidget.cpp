#include "timerwidget.h"
#include <QTimer>
#include <QStyleOption>

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

    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    auto w = width();
    auto h = height();
    auto size = qMin(w, h) - 10;
    QRectF rect((w - size) / 2, (h - size) / 2, size, size);

    auto mid = palette().color(QPalette::Mid);
    auto light = palette().color(QPalette::Light);

    painter.setPen(QPen(mid, 10));
    painter.drawEllipse(rect);

    painter.setPen((QPen(light, 10, Qt::SolidLine, Qt::FlatCap)));
    auto fill = static_cast<float>(m_currTime) / static_cast<float>(m_duration);
    auto spanAngle = static_cast<int>(fill*16*360);
    painter.drawArc(rect, 90 * 16, -spanAngle);
}
