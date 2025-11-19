#include "processscreen.h"
#include "../../timerpanel.h"
#include <qpushbutton.h>

ProcessScreen::ProcessScreen(QWidget *parent)
    : QWidget{parent}
{
    auto* layout = new QVBoxLayout(this);

    QVector<TimerPanel*> panels;
    panels.reserve(3);
    for(auto i = 0; i < 3; ++i)
    {
        auto* panel = new TimerPanel("Test Name", this);
        if(i > 0)
            connect(panels[i-1], &TimerPanel::timerDone, panel, &TimerPanel::startTimer);
        layout->addWidget(panel);
        panels.push_back(panel);
    }

    layout->addStretch();

    auto* btn = new QPushButton("Start");
    auto* pnl = panels[0];
    auto* click = new QMediaPlayer(this);
    click->setSource(QUrl("qrc:/sounds/click.wav"));
    auto* output = new QAudioOutput(this);
    click->setAudioOutput(output);
    connect(btn, &QPushButton::clicked, this, [=](){
        pnl->startTimer();
        btn->setEnabled(false);
        click->play();
    });

    connect(panels.last(), &TimerPanel::timerDone, this, [=](){
        btn->setEnabled(true);
    });

    layout->addWidget(btn);
}
