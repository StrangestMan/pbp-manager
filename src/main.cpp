#include "pbpmanager.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pbpmanager w;
    w.setWindowTitle("PrBoom+ Manager");
    w.show();
    return a.exec();
}
