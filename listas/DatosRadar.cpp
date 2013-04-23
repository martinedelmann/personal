/**
*
* Clase Datos Radar.
*
* @file
*	datosRadar_c.cpp
* @date
*	17-dic-2012
* @author
*	Damian Canovas
* @type
*	Source File (.cpp)
* @change_history
*    1    17-dic-2012    Damian Canovas  Creacion Inicial
*
****************************************************************************/

#include "DatosRadar.h"

/**
*
* Constructor de la clase
*
****************************************************************************/

DatosRadar::DatosRadar()
{

}

/**
*
* Destructor de la clase
*
****************************************************************************/

DatosRadar::~DatosRadar()
{

}

/**
*
* Esta funcion setea el producto contenido en el archivo Bufr para el radar
*
*    @producto_p [in] char *  Producto relevado por el radar.
*
*    @return void
****************************************************************************/

void DatosRadar::setearProducto(char * producto_p)
{

    strncpy(m_datasetArchivoRadar.m_producto,producto_p,sizeof(m_datasetArchivoRadar.m_producto)-1);
    m_datasetArchivoRadar.m_producto[sizeof(m_datasetArchivoRadar.m_producto)-1]='\0';

}

/**
*
* Esta funcion setea la cantidad que se refiere al quantity o variable contenido
* en el archivo Bufr para el radar
*
*    @cantidad_p [in] char *  Cantidad (Quantity) relevada por el radar (variable).
*
*    @return void
*
****************************************************************************/

void DatosRadar::setearCantidad(char * cantidad_p)
{

    strncpy(m_datasetArchivoRadar.m_cantidad,cantidad_p,sizeof(m_datasetArchivoRadar.m_cantidad)-1);
    m_datasetArchivoRadar.m_cantidad[sizeof(m_datasetArchivoRadar.m_cantidad)-1]='\0';

}

/**
*
* Esta funcion devuelve el arco (radio de distancia= corregido segun la
* curvatura de la tierra a un bin determinado
*
*    @bin_p [in] int  Numero de bin.
*
*    @indiceDataset_p [in] int  Dataset correspondiente.
*
*    @return double arco en kilometros.
*
* Nota: asumimos arcos contantes para el mismo bin.
****************************************************************************/

double DatosRadar::obtenerArcoBinDataset(int bin_p)
{
    double devolverArco=0.0;
    // No uso el dataset
    int indiceParametroData=0;

    for (int i=0; i< (int) m_datosData[indiceParametroData].size();i++)
    {
        if (m_datosData[indiceParametroData].at(i).bin==bin_p)
        {
            // Asumimos arcos constantes para el mismo bin
            devolverArco=m_datosData[indiceParametroData].at(i).s_arco;
            break;
        }

    }

    return devolverArco;
}



