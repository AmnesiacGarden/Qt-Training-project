#include "qqwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQWidget w;
    w.show();

    return a.exec();
}
