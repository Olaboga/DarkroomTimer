#include "addbathscreen.h"
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QMetaProperty>
#include <QMetaEnum>

AddBathScreen::AddBathScreen(Bath* bath, QWidget *parent)
    : QWidget{parent}
{
    auto* layout = new QFormLayout(this);
    const auto* meta = bath->metaObject();

    for(auto i = meta->propertyOffset(); i < meta->propertyCount(); ++i)
    {
        auto prop = meta->property(i);
        QString propName = prop.name();
        auto value = bath->property(prop.name());

        auto* editor = createEditorForProperty(prop, value, bath);
        if(editor)
            layout->addRow(propName + ":", editor);
    }
}

QWidget *AddBathScreen::createEditorForProperty(const QMetaProperty& prop, const QVariant& value, Bath* bath)
{
    QWidget* editor = nullptr;

    switch(value.typeId())
    {
    case QMetaType::QString:
        editor = new QLineEdit(value.toString());
        connect(static_cast<QLineEdit*>(editor), &QLineEdit::textChanged, this, [=](const QString& text){ bath->setProperty(prop.name(), text);});
        break;

    case QMetaType::UInt:
        editor = new QLineEdit(QString::number(value.toUInt()));
        connect(static_cast<QLineEdit*>(editor), &QLineEdit::textChanged, this, [=](const QString& text){bath->setProperty(prop.name(), text.toUInt());});
        break;

    case QMetaType::Bool:
        editor = new QCheckBox;
        static_cast<QCheckBox*>(editor)->setChecked(value.toBool());
        connect(static_cast<QCheckBox*>(editor), &QCheckBox::toggled, this, [=](bool checked){bath->setProperty(prop.name(), checked);});
        break;

    default:
        if(prop.isEnumType())
        {
            editor = new QComboBox;
            auto metaEnum = prop.enumerator();
            auto* combo = static_cast<QComboBox*>(editor);
            int currentIndex = -1;
            for(auto j = 0; j < metaEnum.keyCount(); ++j)
            {
                auto key = metaEnum.key(j);
                combo->addItem(key, metaEnum.value(j));
                if(metaEnum.value(j) == value.toInt())
                    currentIndex = j;
            }
            if(currentIndex >= 0)
                combo->setCurrentIndex(currentIndex);

            connect(combo, &QComboBox::currentIndexChanged, this, [=](int index){
                auto enumValue = combo->itemData(index).toInt();
                bath->setProperty(prop.name(), enumValue);
            });
            break;
        }
    }

    return editor;
}
