#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <qlabel.h>
#include "timerpanel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto* central = new QWidget;
    auto* layout = new QVBoxLayout(central);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(20);
    layout->setAlignment(Qt::AlignCenter);

    QVector<TimerPanel*> panels;
    panels.reserve(3);
    for(auto i = 0; i < 3; ++i)
    {
        auto* panel = new TimerPanel("Test Name", central);
        if(i > 0)
            connect(panels[i-1], &TimerPanel::timerDone, panel, &TimerPanel::startTimer);
        layout->addWidget(panel);
        panels.push_back(panel);
    }

    setCentralWidget(central);
    panels[0]->startTimer();

}

MainWindow::~MainWindow()
{
}
