/**
*
*    Modulo para la implementacion de la clase Radar_C.
*
*
* ARCHIVO:            radar_c.cpp
*
* AUTOR:              Damian Canovas
*
* VERSION NUMERO:     0.1
*
* FECHA DE CREACION:  21-Ene-2013
*
* ESTADO:             DESARROLLO INICIAL
*
* @change_history
*    1    21-ene-2013    Damian Canovas  Creacion inicial
*********************************************************************************/

#include "Radar.h"

/**
* Constructor
*
********************************************************************/

Radar::Radar()
{

    m_centroXLon=0.0;
    m_centroYLat=0.0;
}

/**
* Destructor
*
********************************************************************/

Radar::~Radar()
{
// Nada para destruir
}

/**
* Funcion para setear el centro su longitud X y su latitud Y
*
* @param[in] double centX_Lon_p Valor del centro X Lon.
*
* @param[in] double centY_Lat_p Valor del centro Y Lat.
*
* return void.
*
********************************************************************/

void Radar::setCentro(double centX_Lon_p, double centY_Lat_p)
{
    // X LONGITUD Y LATITUD
    if(centX_Lon_p >= -90 && centX_Lon_p <=90)
        m_centroXLon = centX_Lon_p;
    else
        m_centroXLon = 0;
    if(centY_Lat_p >= -90 && centY_Lat_p <=90)
        m_centroYLat = centY_Lat_p;
    else
        m_centroYLat = 0;
}
