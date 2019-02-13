/**
 * @brief Implementación de la clase Garito
 * @file Garito.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:51
 */

#include "Garito.h"

/**
 * @brief Constructor por defecto de la clase
 * @param nombre Nombre del garito
 * @param direccion Direccion del garito
 * @post Crea un nuevo objeto de la clase Garito
 */
Garito::Garito(std::string nombre, std::string direccion) :
    _nombre(nombre),
    _direccion(direccion) {
}

/**
 * @brief Constructor de copia de la clase
 * @param orig Objeto de tipo garito del que se copiarán los datos
 * @post Crea un nuevo objeto de la clase Garito
 */

Garito::Garito(const Garito& orig) :
    _nombre(orig._nombre),
    _direccion(orig._direccion) {
}

/**
 * @brief Destructor de clase
 * @post Destruye el objeto
 */
Garito::~Garito() {
}

/**
 * @brief Modifica la dirección del Garito
 * @param direccion Nueva dirección
 * @post Modifica la dirección del Garito
 */
void Garito::setDireccion(std::string direccion) {
   if ( direccion == "" )
      throw std::string ( "Se intenta asignar una dirección vacía" );

   this->_direccion = direccion;
}

/**
 * @brief Devuelve la dirección del garito
 * @post Devuelve la dirección del garito
 */
std::string Garito::getDireccion() const {
    return _direccion;
}

/**
 * @brief Modifica el nombre del garito
 * @param nombre Nuevo nombre para el garito
 * @post Modifica el nombre del garito
 */
void Garito::setNombre(std::string nombre) {
   if ( nombre == "" )
      throw std::string ( "Se intenta asignar una dirección vacía" );

   this->_nombre = nombre;
}

/**
 * @brief Devuelve el nombre del garito
 * @post Devuelve el nombre del garito
 */
std::string Garito::getNombre() const {
    return _nombre;
}

