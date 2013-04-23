#include "miclase.h"

miClase::miClase(QObject *parent) :
    QObject(parent)
{
    primerElemento_m = 0;
    segundoElemento_m = 0;
    tercerElemento_m = 0;
}

void miClase::setPrimerElemento(int value)
{
    primerElemento_m = value;
}

int miClase::primerElemento() const
{
    return primerElemento_m;
}

void miClase::setSegundoElemento(qint16 value)
{
    segundoElemento_m = value;
}

short miClase::segundoElemento() const
{
    return segundoElemento_m;
}
