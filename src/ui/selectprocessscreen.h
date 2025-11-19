#ifndef SELECTPROCESSSCREEN_H
#define SELECTPROCESSSCREEN_H

#include <QWidget>
#include <QPushButton>

class SelectProcessScreen : public QWidget
{
    Q_OBJECT
public:
    explicit SelectProcessScreen(QWidget *parent = nullptr);
    QPushButton* m_addProcessButton;

signals:
};

#endif // SELECTPROCESSSCREEN_H
