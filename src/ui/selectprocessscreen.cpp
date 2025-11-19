#include "selectprocessscreen.h"
#include <QVBoxLayout>

SelectProcessScreen::SelectProcessScreen(QWidget *parent)
    : QWidget{parent}
{
    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(10);
    layout->setAlignment(Qt::AlignCenter);

    m_addProcessButton = new QPushButton("Add Process");
    layout->addWidget(m_addProcessButton);
}
