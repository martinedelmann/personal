#ifndef MICLASE_H
#define MICLASE_H

#include <QObject>

class miClase : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int primerElemento READ primerElemento WRITE setPrimerElemento)
    Q_PROPERTY(qint16 segundoElemento READ segundoElemento)
public:
    miClase(QObject *parent = 0);
    int primerElemento() const;
    qint16 segundoElemento() const;

    void setSegundoElemento(qint16 value);

public slots:
    void setPrimerElemento(int value);


private:
    int primerElemento_m;
    qint16 segundoElemento_m;
    float tercerElemento_m;
};

#endif // MICLASE_H
