#include "mainwindow.h"
#include <QApplication>
#include "miclase.h"
#include <typeinfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    miClase *objetoClase = new miClase();
    objetoClase->setSegundoElemento(3);
    QObject *objeto = objetoClase;

    objeto->setProperty("primerElemento",10);

    qDebug("property:%d",objeto->property("primerElemento").toInt());
    qDebug("privado: %d",objetoClase->primerElemento());

//    qDebug("privado: %d",objeto->property("primerElemento").);
    qDebug("tipo: %s", objeto->property("primerElemento").typeName());

    return a.exec();
}
