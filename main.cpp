#include "mainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
