#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include "timerwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto* layout = new QVBoxLayout(this);
    setLayout(layout);

    auto* tw = new TimerWidget(33, this);
    connect(tw, &TimerWidget::timeOut, this, [=](){
        layout->removeWidget(tw);
        tw->hide();
        tw->deleteLater();
    });

    tw->setGeometry(100, 100, 200, 200);
    layout->addWidget(tw);
}

MainWindow::~MainWindow()
{
}
