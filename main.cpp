#include "menuglowne.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuGlowne w;
    w.show();
    return a.exec();
}
