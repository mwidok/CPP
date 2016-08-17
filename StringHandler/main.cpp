#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("StringPlayTool");
    w.setFixedSize(381,151);
    w.show();

    return a.exec();
}
