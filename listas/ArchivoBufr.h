#ifndef ARCHIVO_BUFR_H
#define ARCHIVO_BUFR_H

#include "defines.h"
#include "Radar.h"
#include "DatosRadar.h"

class ArchivoBufr
{
public:

    // Constructor
    ArchivoBufr();
    // Destructor
    ~ArchivoBufr();

    void setearNombreArchivo(QString nombreArchivo_p){m_nombreArchivo=nombreArchivo_p;}
    QString obtenerNombreArchivo(void){return m_nombreArchivo;}

    void setearPasadas(int pasadas_p){m_pasadas=pasadas_p;}
    int  obtenerPasadas(void){return m_pasadas;}
    void setearAnio(int anio_p){m_anio=anio_p;}
    int  obtenerAnio(void){return m_anio;}
    void setearMes(int mes_p){m_mes=mes_p;}
    int  obtenerMes(void){return m_mes;}
    void setearDia(int dia_p){m_dia=dia_p;}
    int  obtenerDia(void){return m_dia;}
    void setearHora(int hora_p){m_hora=hora_p;}
    int  obtenerHora(void){return m_hora;}
    void setearMinuto(int minuto_p){m_minuto=minuto_p;}
    int  obtenerMinuto(void){return m_minuto;}
    void setearSegundo(int segundo_p){m_segundo=segundo_p;}
    int  obtenerSegundo(void){return m_segundo;}
    void setearTablaMaestra(int tablaMaestra_p){m_tablaMaestra=tablaMaestra_p;}
    int  obtenerTablaMaestra(void){return m_tablaMaestra;}
    void setearSubcentro(int subcentro_p){m_subcentro=subcentro_p;}
    int  obtenerSubcentro(void){return m_subcentro;}
    void setearCentroGenerador(int centroGenerador_p){m_centroGenerador=centroGenerador_p;}
    int  obtenerCentroGenerador(void){return m_centroGenerador;}
    void setearSecuencia(int secuencia_p){m_secuencia=secuencia_p;}
    int  obtenerSecuencia(void){return m_secuencia;}
    void setearSeccionOp(int seccionOp_p){m_seccionOp=seccionOp_p;}
    int  obtenerseccionOp(void){return m_seccionOp;}
    void setearCategoriaDatos(int categoriaDatos_p){m_categoriaDatos=categoriaDatos_p;}
    int  obtenerCategoriaDatos(void){return m_categoriaDatos;}
    void setearSubcategoriaDatos(int subcategoriaDatos_p){m_subcategoriaDatos=subcategoriaDatos_p;}
    int  obtenerSubcategoriaDatos(void){return m_subcategoriaDatos;}
    void setearInterCatDatos(int interCatDatos_p){m_interCatDatos=interCatDatos_p;}
    int  obtenerInterCatDatos(void){return m_interCatDatos;}
    void setearTablasVersion(int tablasVersion_p){m_tablasVersion=tablasVersion_p;}
    int  obtenerTablasVersion(void){return m_tablasVersion;}
    void setearTablasLocVersion(int tablasLocVersion_p){m_tablasLocVersion=tablasLocVersion_p;}
    int  obtenerTablasLocVersion(void){return m_tablasLocVersion;}

    void agregarDataset(void){if (m_ultimoIndiceDataset<CantidadMaximaDatasets) m_ultimoIndiceDataset++; else {/* Ver */}};
    void generarPlantilla(void);

    Radar *m_radar_c;
    DatosRadar *m_datosDataset[CantidadMaximaDatasets]; // Datos Crudos
    DatosRadar *m_datosDecodificadosDataset[CantidadMaximaDatasets];

    std::deque<datosCAPPI_s> m_datosCAPPI[CantidadMaximaImagenes];
    QString m_referenciaDatos[CantidadMaximaImagenes];
    int m_indiceDatosCAPPI;
    int m_indiceActualDatosCAPPI;

    plantilla_productos_s m_plantilla;

protected:

private:

    QString m_nombreArchivo;

    int m_anio; // AAAA
    int m_mes; // MM
    int m_dia; // DD
    int m_hora; // HH
    int m_minuto; // MiMi
    int m_segundo; // SS
    int m_tablaMaestra; // tablas WMO BUFR
    int m_subcentro; // subcentro originador
    int m_centroGenerador;   // centro originador
    int m_secuencia; // 0 para BUFR originales, != 0 para mensajes de actualizaciones
    int m_seccionOp;    // Seccion opcion 1 seccion opcional incluida, 0 no incluida
    int m_categoriaDatos;     // Tipo de categoria de datos (BUFR Tabla A)
    int m_subcategoriaDatos;  // Subcategoria de datos
    int m_interCatDatos;   // Tipo de categoria de datos internacional
                            // Tabla comun C-13, usada para BUFR edicion 4
    int m_tablasVersion;     // version de las tablas maestras usadas
    int m_tablasLocVersion; // version de las tablas locales usadas

    int m_indiceDataset;
    int m_ultimoIndiceDataset;
    int m_pasadas; // nscans cantidad de dataset

};

#endif // ARCHIVO_BUFR_H
