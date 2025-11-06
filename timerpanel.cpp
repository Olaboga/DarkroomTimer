#include "timerpanel.h"
#include "timerwidget.h"
#include <QLabel>
#include <QMediaPlayer>
#include <QAudioOutput>

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

    m_audioOutput = new QAudioOutput(this);
    m_beepPlayer = new QMediaPlayer(this);
    m_beepPlayer->setSource(QUrl("qrc:/sounds/beep.wav"));
    m_beepPlayer->setAudioOutput(m_audioOutput);
}

void TimerPanel::startTimer()
{
       auto* tw = new TimerWidget(10, this);
       tw->setGeometry(100, 100, 200, 200);
       connect(tw, &TimerWidget::timeOut, this, [=](){
           m_layout->removeWidget(tw);
           tw->hide();
           tw->deleteLater();
           m_beepPlayer->play();
           emit timerDone();
       });
       m_layout->addWidget(tw);
       adjustSize();
       updateGeometry();
       update();
}
