/**
*
* Clase Radar.
*
* @file
*	radar_c.h
* @date
*	17-dic-2012
* @author
*	Damian Canovas
* @type
*	Header File (.h)
* @change_history
*    1    17-dic-2012    Damian Canovas  Creacion Inicial
*
***********************************************************************************/

#ifndef RADAR_H
#define RADAR_H

#include <string>

class Radar
{
public:

    // Constructor
    Radar();
    // Destructor
    ~Radar();

    void setNombre(std::string nombreRadar_p){m_nombreRadar=nombreRadar_p;}
    std::string obtenerNombre(){return m_nombreRadar;}
    void setDescripcion(std::string descripcionRadar_p){m_descripcionRadar=descripcionRadar_p;}
    std::string obtenerDescripcion(){return m_descripcionRadar;}
    void setTipo(std::string tipoRadar_p){m_tipoRadar=tipoRadar_p;}
    std::string obtenerTipo(){return m_tipoRadar;}
    void setBandaTrabajo(std::string bandaTrabajo_p){m_bandaTrabajo=bandaTrabajo_p;}
    std::string obtenerBandaTrabajo(){return m_bandaTrabajo;}
    void setEstrategiaBarrido(std::string estrategiaBarrido_p){m_estrategiaBarrido=estrategiaBarrido_p;}
    std::string obtenerEstrategiaBarrido(){return m_estrategiaBarrido;}
    void setCentro(double centX_Lon_p, double centY_Lat_p);
    double obtenerCentro(int i){if (i == 0)return m_centroXLon; else return m_centroYLat;}
    void setAltura(double alturaSNM_p){m_alturaSNM=alturaSNM_p;}
    double obtenerAltura(){return m_alturaSNM;}

protected:

private:

    // Nombre del Radar
    std::string m_nombreRadar;

    // Descripcion del Radar
    std::string m_descripcionRadar;

    // Tipo de Radar
    std::string m_tipoRadar;

    // Banda de Trabajo
    std::string m_bandaTrabajo;

    // Estrategia de Barrido
    std::string m_estrategiaBarrido;

    // Latitud Longitud
    double m_centroXLon;
    double m_centroYLat;

    // Altitud SNM
    double m_alturaSNM;

};

#endif // RADAR_H
