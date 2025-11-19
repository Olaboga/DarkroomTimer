#ifndef ADDBATHSCREEN_H
#define ADDBATHSCREEN_H

#include <QWidget>
#include "../core/bath.h"

class AddBathScreen : public QWidget
{
    Q_OBJECT
public:
    explicit AddBathScreen(Bath* bath, QWidget *parent = nullptr);

signals:

private:
    QWidget* createEditorForProperty(const QMetaProperty& prop, const QVariant& value, Bath *bath);
};

#endif // ADDBATHSCREEN_H
