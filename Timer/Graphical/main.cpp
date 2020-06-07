#include "graphicalwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicalWidget w;
    w.show();

    return a.exec();
}
