#include "mainwindow.h"
#include "ImageLoader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Utils::ImageLoader window;
    window.resize(800, 600);
    window.show();
    return a.exec();
}
