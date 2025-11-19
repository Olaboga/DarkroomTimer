#include "settingscreen.h"
#include "addprocessscreen.h"
#include "selectprocessscreen.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <qlabel.h>

SettingScreen::SettingScreen(QWidget *parent)
    : QWidget{parent}
{
    auto* layout = new QVBoxLayout(this);

    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(10);
    layout->setAlignment(Qt::AlignCenter);

    auto* stack = new QStackedWidget(this);
    auto* selectScreen = new SelectProcessScreen(this);
    auto* addScreen = new AddProcessScreen(this);

    connect(selectScreen->m_addProcessButton, &QPushButton::clicked, this, [=](){stack->setCurrentIndex(1);});

    stack->addWidget(selectScreen);
    stack->addWidget(addScreen);
    stack->setCurrentIndex(0);

    layout->addWidget(stack);
}
