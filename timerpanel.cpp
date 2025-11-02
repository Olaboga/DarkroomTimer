#include "timerpanel.h"
#include "timerwidget.h"
#include <QLabel>

TimerPanel::TimerPanel(QWidget* parent)
{}

TimerPanel::TimerPanel(QString panelName, QWidget *parent)
    : QFrame(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    m_layout = new QVBoxLayout(this);
    setLayout(m_layout);

    auto* label = new QLabel(panelName, this);
    label->setAlignment(Qt::AlignCenter);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_layout->addWidget(label);
    adjustSize();
}

void TimerPanel::startTimer()
{
       auto* tw = new TimerWidget(10, this);
       tw->setGeometry(100, 100, 200, 200);
       connect(tw, &TimerWidget::timeOut, this, [=](){
           m_layout->removeWidget(tw);
           tw->hide();
           tw->deleteLater();
           emit timerDone();
       });
       m_layout->addWidget(tw);
       adjustSize();
       updateGeometry();
       update();
}
