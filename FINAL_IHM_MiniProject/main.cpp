#include "welcomep.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WelcomeP w;
    w.show();
    return a.exec();
}
