#include "timerpanel.h"
#include "timerwidget.h"
#include <QLabel>

TimerPanel::TimerPanel(QWidget* parent)
{}

TimerPanel::TimerPanel(QString panelName, QWidget *parent)
    : QWidget{parent}
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMinimumSize(200, 200);

    m_layout = new QVBoxLayout(this);
    setLayout(m_layout);

    auto* label = new QLabel(panelName, this);
    label->setAlignment(Qt::AlignCenter);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setStyleSheet("font-size: 24px;");
    m_layout->addWidget(label);
}

void TimerPanel::startTimer()
{
       auto* tw = new TimerWidget(30, this);
       tw->setGeometry(100, 100, 200, 200);
       connect(tw, &TimerWidget::timeOut, this, [=](){
           m_layout->removeWidget(tw);
           tw->hide();
           tw->deleteLater();
           emit timerDone();
       });
       m_layout->addWidget(tw);
       updateGeometry();
       update();
}
