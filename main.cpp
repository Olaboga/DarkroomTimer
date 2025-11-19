#include "src/ui/mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPalette palette;
    palette.setColor(QPalette::Active, QPalette::Light, QColor(255, 0,0));
    palette.setColor(QPalette::Active, QPalette::Midlight, QColor(80, 0, 0));
    palette.setColor(QPalette::Active, QPalette::Mid, QColor(50, 0, 0));
    palette.setColor(QPalette::Active, QPalette::Dark, QColor(0, 0, 0));
    a.setPalette(palette);

    QFile file(":styles/DarkroomTimerStyleDark.qss");
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        auto style = file.readAll();
        a.setStyleSheet(style);
    }

    MainWindow w;
    w.show();
    return a.exec();
}
