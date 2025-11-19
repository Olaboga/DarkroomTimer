#include "addprocessscreen.h"
#include <QVBoxLayout>
#include <QLineEdit>

AddProcessScreen::AddProcessScreen(/*Process* process,*/ QWidget *parent)
    : QWidget{parent}
{
    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(10);
    layout->setAlignment(Qt::AlignCenter);

    auto* nameEdit = new QLineEdit(this);
    nameEdit->setPlaceholderText("Set process name");
    nameEdit->setText("C-41");

//    connect(nameEdit, &QLineEdit::textChanged, process, &Process::SetName);

    layout->addWidget(nameEdit);
    setLayout(layout);
}
