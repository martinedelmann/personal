/**
*
* Clase para manipular los datos del radar.
*
* @file
*	datosRadar_c.h
* @date
*	17-dic-2012
* @author
*	Damian Canovas
* @type
*	Header File (.h)
* @change_history
*    1    17-dic-2012    Damian Canovas  Creacion Inicial
************************************************************************/

#ifndef DATOSRADAR_H
#define DATOSRADAR_H

#include <deque>
#include <QString>

#include "estructuras.h"
#include "defines.h"

class DatosRadar
{

public:

    // Constructor
    DatosRadar();
    // Destructor
    ~DatosRadar();

    void setearDatasetArchivo(int datasetArchivo_p){m_datasetArchivo=datasetArchivo_p;};

    void setearNumeroRayos(int numeroRayos_p){m_datasetArchivoRadar.m_numeroRayos=numeroRayos_p;}
    double obtenerNumeroRayos(void){return m_datasetArchivoRadar.m_numeroRayos;}
    void setearNumeroBins(int numeroBins_p){m_datasetArchivoRadar.m_numeroBins=numeroBins_p;}
    double obtenerNumeroBins(void){return m_datasetArchivoRadar.m_numeroBins;}
    void setearLargoBin(double largoBin_p){m_datasetArchivoRadar.m_largoBin=largoBin_p;}
    double obtenerLargoBin(void){return m_datasetArchivoRadar.m_largoBin;} // en metros
    void setearRadioInicial(double radioInicial_p){m_datasetArchivoRadar.m_radioInicial=radioInicial_p;}
    double obtenerRadioInicial(void){return m_datasetArchivoRadar.m_radioInicial;}
    void setearAnguloElevacion(double anguloElevacion_p){m_datasetArchivoRadar.m_anguloElevacion=anguloElevacion_p;}
    double obtenerAnguloElevacion(void){return m_datasetArchivoRadar.m_anguloElevacion;}
    void setearAnguloArranque(double anguloArranque_p){m_datasetArchivoRadar.m_anguloArranque=anguloArranque_p;}
    double obtenerAnguloArranque(void){return m_datasetArchivoRadar.m_anguloArranque;}
    void setearAnguloFin(double anguloFin_p){m_datasetArchivoRadar.m_anguloFin=anguloFin_p;}
    double obtenerAnguloFin(void){return m_datasetArchivoRadar.m_anguloFin;}
    void setearProducto(char * producto_p);
    std::string obtenerProducto(void){return m_datasetArchivoRadar.m_producto;}

    void setearCantidad(char * cantidad_p);
    std::string obtenerCantidad(void){return m_datasetArchivoRadar.m_cantidad;}
    void setearA1gate(int a1gate_p){m_datasetArchivoRadar.m_a1gate=a1gate_p;}
    double obtenerA1gate(void){return m_datasetArchivoRadar.m_a1gate;}
    void setearNoDetectado(double noDetectado_p){m_datasetArchivoRadar.m_noDetectado=noDetectado_p;}
    double obtenerNoDetectado(void){return m_datasetArchivoRadar.m_noDetectado;}
    void setearSinDatos(double sinDatos_p){m_datasetArchivoRadar.m_sinDatos=sinDatos_p;}
    double obtenerSinDatos(void){return m_datasetArchivoRadar.m_sinDatos;}
    void setearGanancia(double ganancia_p){m_datasetArchivoRadar.m_ganancia=ganancia_p;}
    double obtenerGanancia(void){return m_datasetArchivoRadar.m_ganancia;}
    void setearOffset(double offset_p){m_datasetArchivoRadar.m_offset=offset_p;}
    double obtenerOffset(void){return m_datasetArchivoRadar.m_offset;}

    void setearParametros(int parametros_p){m_parametros=parametros_p;};
    int obtenerParametros(void){return m_parametros;};

    void agregarParametro(void){if (m_ultimoIndiceParametro<CantidadMaximaParametrosDataset) m_ultimoIndiceParametro++; else {/* Ver */}};
    void setearParametroDataset(int parametroDataset_p){m_parametroDataset=parametroDataset_p;};

    double obtenerArcoBinDataset(int bin_p);

    std::deque<celda_t> m_datosData[CantidadMaximaParametrosDataset]; // datos del datasets

    //double obtenerArcoBinDataset(int bin_p, int indiceDataset_p);

protected:

private:

    int m_datasetArchivo;

    int m_parametroDataset;
    int m_ultimoIndiceParametro;
    int m_parametros; // nparams indice para los data dentro de un dataset

    // Parametros scan de radar
    configuracion_radar_t m_datasetArchivoRadar;
};


#endif // DATOSRADAR_H
