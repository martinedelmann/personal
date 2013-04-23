/**
*
* Archivo con las principales estructuras.
*
* @file
*	estructuras.h
* @date
*	17-dic-2012
* @author
*	Damian Canovas
* @type
*	Header File (.h)
* @change_history
*    1    17-dic-2012    Damian Canovas  Creacion Inicial
*
**********************************************************************/

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <utility>
#include <QString>

#include "defines.h"

typedef struct celda_s{

        double s_arco;
        double s_arco_prox;
        int bin;
        int rayo;
        double dato;
        int valido; //0 invalido 1 valido
        double h_altura;


        celda_s ()
        {
            bin=0;
            rayo=0;
            dato=0.0;
            valido=0;
            h_altura=0.0;
            s_arco=0.0;
            s_arco_prox=0.0;
        }
} celda_t;

typedef struct datosCAPPI_s{

        double x;
        double y;
        double valor;
        double h;
        double res;

        datosCAPPI_s ()
        {
            x=0.0;
            y=0.0;
            valor=0.0;
            h=0.0;
            res=0.0;
        }

} datosCAPPI_t;

typedef struct configuracion_radar_s
{
    int m_numeroRayos;
    int m_numeroBins;
    double m_largoBin; // rscale en metros
    double m_radioInicial; // rStart desde donde comienza tiene q ser <> 0 en KM
    double m_anguloElevacion; // elAngle
    double m_anguloArranque; // startAz
    double m_anguloFin; //stopAz
    char m_producto[CaracteresParaTexto]; // product
    char m_cantidad[CaracteresParaTexto]; // quantity
    int m_a1gate; //a1gate
    double m_noDetectado;
    double m_sinDatos;
    double m_ganancia;
    double m_offset;

    configuracion_radar_s()
    {
        m_numeroRayos=0;
        m_numeroBins=0;
        m_largoBin=0;
        m_radioInicial=0.0;
        m_anguloElevacion=0.0;
        m_anguloArranque=0.0;
        m_anguloFin=0.0;
        m_producto[0]=0;
        m_cantidad[0]=0;
        m_noDetectado=0.0;
        m_sinDatos=0.0;
        m_ganancia=0.0;
        m_offset=0.0;
    }

} configuracion_radar_t;

typedef struct plantilla_productos_s
{
    QString variable; // Nombre de la variable
    double elevacion[CantidadMaximaDatasets]; // Array de elevaciones
    int m_cantidadElevaciones; // Total de Elevaciones
    bool ppi_disponible;
    bool cappi_disponible;
    bool colmax_disponible;
    bool rhi_disponible;
    double ppi_min;
    double ppi_max;

    plantilla_productos_s()
    {
        m_cantidadElevaciones=0;
        ppi_disponible=false;
        cappi_disponible=false;
        colmax_disponible=false;
        rhi_disponible=false;
        ppi_min=0.0;
        ppi_max=0.0;
    }

} plantilla_productos_t;


#endif // ESTRUCTURAS_H
