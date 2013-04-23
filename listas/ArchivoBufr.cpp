/**
*
* Clase archivo BUFR.
*
* @file
*	archivoBufr_c.cpp
* @date
*	17-dic-2012
* @author
*	Damian Canovas
* @type
*	Source File (.cpp)
* @change_history
*    1    17-dic-2012    Damian Canovas  Creacion Inicial
*
***************************************************************************/

#include "ArchivoBufr.h"

/**
*
* Constructor de la clase
*
***************************************************************************/

ArchivoBufr::ArchivoBufr()
{
    m_indiceDataset=0;
    m_ultimoIndiceDataset=0;
    m_nombreArchivo="";
    m_indiceDatosCAPPI=0;
    m_indiceActualDatosCAPPI=0;

    m_radar_c = new Radar;

    for (int i=0;i<CantidadMaximaDatasets;i++)
    {
         m_datosDataset[i]=new DatosRadar;
    }

    for (int i=0;i<CantidadMaximaDatasets;i++)
    {
         m_datosDecodificadosDataset[i]=new DatosRadar;
    }

    for (int i=0;i<CantidadMaximaImagenes;i++)
    {
        m_referenciaDatos[i]=QString("");
    }

}

/**
*
* Destructor de la clase
*
********************************************************************/

ArchivoBufr::~ArchivoBufr()
{

    // Destruir todo aqui
    delete m_radar_c;

    for (int i=0;i<CantidadMaximaDatasets;i++)
    {
         delete m_datosDataset[i];
    }

    for (int i=0;i<CantidadMaximaDatasets;i++)
    {
         delete m_datosDecodificadosDataset[i];
    }

    for (int i=0;i<CantidadMaximaImagenes;i++)
    {
        m_datosCAPPI[i].clear();
        m_referenciaDatos[i]=QString("");
    }

}

/**
*
* generarPlantilla
*
********************************************************************/
void ArchivoBufr::generarPlantilla(void)
{
    int primerDataset = 0;

    m_plantilla.variable = QString(m_datosDataset[primerDataset]->obtenerCantidad().c_str());
    m_plantilla.m_cantidadElevaciones = obtenerPasadas();

    for (int i=0; i<m_plantilla.m_cantidadElevaciones; i++)
    {
        m_plantilla.elevacion[i]=m_datosDataset[i]->obtenerAnguloElevacion();
    }

    m_plantilla.ppi_disponible=true;
    m_plantilla.cappi_disponible=true;
    m_plantilla.colmax_disponible=false;
    m_plantilla.rhi_disponible=false;

}





