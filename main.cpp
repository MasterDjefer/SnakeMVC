#include "painterwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PainterWidget w;
    w.show();
    return a.exec();
}
