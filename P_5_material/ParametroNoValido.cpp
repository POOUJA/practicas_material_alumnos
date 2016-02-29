/** 
 * @file ParametroNoValido.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 19 de febrero de 2016, 12:17
 * @brief Clase Parametro no Valido. Permitirá lanzar excepciones de este tipo.
 */
#include "ParametroNoValido.h"

/**
 * @brief Constructor parametrizado
 * @param _fichero Nombre dle fichero donde ocurre la excepción
 * @param _funcion Nombre de la función o método donde ocurre la excepción
 * @param _descripcion Descripción de la excepción
 * @post Crea un nuevo objeto de tipo ParametroNoValido
 */
ParametroNoValido::ParametroNoValido(std::string _fichero
        , std::string _funcion
        , std::string _descripcion) :
fichero(_fichero)
, funcion(_funcion)
, descripcion(_descripcion) {
}

/**
 * @brief Constructor de copia
 * @param orig Objeto original cuyos datos se van a copiar
 * @post Crea un nuevo objeto de tipo ParametroNoValido por copia
 */
ParametroNoValido::ParametroNoValido(const ParametroNoValido& orig):
fichero(orig.fichero)
, funcion(orig.funcion)
, descripcion(orig.descripcion){
}

/**
 * @brief Destructor de la clase
 * @post Destruye el objeto
 */
ParametroNoValido::~ParametroNoValido() {
}

/**
 * @brief Dvuelve un string concatenando los atributos Fichero, Función y Descripción.
 * @return String concatenando los atributos Fichero, Función y Descripción.
 */
std::string ParametroNoValido::queOcurre() const {
    return ">Fichero: "+fichero+" "
            + ">Método/función: "+funcion+" "
            + ">Descripción: "+descripcion;
}