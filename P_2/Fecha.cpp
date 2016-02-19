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
dia(0)
, mes(0)
, anio(0) {
    struct tm *tmp;
    time_t fecha;
    time(&fecha);
    tmp = localtime(&fecha);
    this->anio = tmp->tm_year + 1900;
    this->mes = tmp->tm_mon + 1;
    this->dia = tmp->tm_mday;
}

/**
 * @brief Constructor parametrizado
 * @param dia Dia para la fecha
 * @param mes Mes para la fecha
 * @param anio Año para la fecha
 * @post Crea un objeto con los valores indicados
 */
Fecha::Fecha( int dia, int mes, int anio) :
dia(dia)
, mes(mes)
, anio(anio) {
}

/**
 * @brief Constructor de copia de la clase
 * @param orig Objeto del cual se obtienen los datos
 * @post Crea un objeto de tipo fecha
 */

Fecha::Fecha(const Fecha& orig):
dia(orig.dia)
, mes(orig.mes)
, anio(orig.anio) {
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
    this->anio = anio;
}

/**
 * @brief Devuelve el año de la fecha
 * @post Devuelve el año de la fecha
 */
int Fecha::getAnio() const {
    return anio;
}

/**
 * @brief Modifica el mes de la fecha
 * @param mes Nuevo mes para la fecha
 * @post Modifica el mes para la fecha
 */
void Fecha::setMes(int mes) {
    this->mes = mes;
}

/**
 * @brief Devuelve el mes de la fecha
 * @post Devuelve el mes de la fecha
 */
int Fecha::getMes() const {
    return mes;
}

/**
 * @brief Modifica el dia de la fecha
 * @param dia Nuevo dia para la fecha
 * @post Modifica el dia para la fecha
 */
void Fecha::setDia(int dia) {
    this->dia = dia;
}
/**
 * @brief Devuelve el dia de la fecha
 * @post Devuelve el dia de la fecha
 */
int Fecha::getDia() const {
    return dia;
}

