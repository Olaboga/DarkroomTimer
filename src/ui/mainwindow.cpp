#include "mainwindow.h"
#include "processscreen.h"
#include "settingscreen.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <qlabel.h>
#include <QMediaPlayer>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto* central = new QWidget;
    auto* layout = new QVBoxLayout(central);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(10);
    layout->setAlignment(Qt::AlignCenter);

    auto* stack = new QStackedWidget(this);
    auto* settingScreen = new SettingScreen(this);
    auto* processScreen = new ProcessScreen(this);

    stack->addWidget(settingScreen);
    stack->addWidget(processScreen);

    layout->addWidget(stack);
    stack->setCurrentIndex(0);

    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
}
