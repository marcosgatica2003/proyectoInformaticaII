#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.setWindowTitle("Sistema de Seguridad para Cámaras Frigoríficas");
    w.show();
    return a.exec();
}
