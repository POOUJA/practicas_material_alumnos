/**
 * @brief Implementación de la clase Fecha
 * @file Fecha.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:59
 */
#include <time.h>
#include "Fecha.h"

/**
 * @brief Constructor por defecto de la clase
 * @post Construye in nuevo objeto estableciendo el dia, mes y año a los que indique el sistema
 */
Fecha::Fecha() :
    _dia(0),
    _mes(0),
    _anio(0) {

    struct tm *tmp;
    time_t fecha;
    time(&fecha);
    tmp = localtime(&fecha);
    this->_anio = tmp->tm_year + 1900;
    this->_mes = tmp->tm_mon + 1;
    this->_dia = tmp->tm_mday;
}

/**
 * @brief Constructor parametrizado
 * @param dia Dia para la fecha
 * @param mes Mes para la fecha
 * @param anio Año para la fecha
 * @post Crea un objeto con los valores indicados
 */
Fecha::Fecha( int dia, int mes, int anio) :
    _dia(dia),
    _mes(mes),
    _anio(anio) {
}

/**
 * @brief Constructor de copia de la clase
 * @param orig Objeto del cual se obtienen los datos
 * @post Crea un objeto de tipo fecha
 */

Fecha::Fecha(const Fecha& orig):
    _dia(orig._dia),
    _mes(orig._mes),
    _anio(orig._anio) {
}

/**
 * @brief Destructor de clase
 * @post Destruye el objeto
 */
Fecha::~Fecha() {
}

/**
 * @brief Modifica el año de la fecha
 * @param anio Nuevo año para la fecha
 * @post Modifica el año para la fecha
 */
void Fecha::setAnio(int anio) {
    this->_anio = anio;
}

/**
 * @brief Devuelve el año de la fecha
 * @post Devuelve el año de la fecha
 */
int Fecha::getAnio() const {
    return _anio;
}

/**
 * @brief Modifica el mes de la fecha
 * @param mes Nuevo mes para la fecha
 * @post Modifica el mes para la fecha
 */
void Fecha::setMes(int mes) {
    this->_mes = mes;
}

/**
 * @brief Devuelve el mes de la fecha
 * @post Devuelve el mes de la fecha
 */
int Fecha::getMes() const {
    return _mes;
}

/**
 * @brief Modifica el dia de la fecha
 * @param dia Nuevo dia para la fecha
 * @post Modifica el dia para la fecha
 */
void Fecha::setDia(int dia) {
    this->_dia = dia;
}
/**
 * @brief Devuelve el dia de la fecha
 * @post Devuelve el dia de la fecha
 */
int Fecha::getDia() const {
    return _dia;
}

