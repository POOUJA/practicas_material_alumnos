/**
 * @file Mutante.cpp
 * @author algarcia
 *
 */

#include <stdexcept>
#include <sstream>

#include "Mutante.h"

Mutante::Mutante(string nombre, string apodo, int fechaN, string nacionalidad) 
    : _nombreReal(nombre),
      _apodo(apodo),
      _fechaDeNacimiento(fechaN),
      _nacionalidad(nacionalidad)
      {
    
}

Mutante::Mutante(const Mutante& orig)
    : _nombreReal(orig._nombreReal),
    _apodo(orig._apodo),
    _fechaDeNacimiento(orig._fechaDeNacimiento),
    _nacionalidad(orig._nacionalidad)
 {
    
}

Mutante::~Mutante() {
}

void Mutante::setNombreReal(string nombreReal) {
    this->_nombreReal = nombreReal;
}

string Mutante::getNombreReal() const {
    return _nombreReal;
}

void Mutante::setNacionalidad(string nacionalidad) {
    this->_nacionalidad = nacionalidad;
}

string Mutante::getNacionalidad() const {
    return _nacionalidad;
}

void Mutante::setFechaDeNacimiento(int fechaDeNacimiento) {
    this->_fechaDeNacimiento = fechaDeNacimiento;
}

int Mutante::getFechaDeNacimiento() const {
    return _fechaDeNacimiento;
}

void Mutante::setApodo(string apodo) {
    this->_apodo = apodo;
}

string Mutante::getApodo() const {
    return _apodo;
}


/**@brief Representación CSV de un mutante
   @post  Genera la representación básica en CSV, sin incluir los poderes*/
string Mutante::toCSV() const{
    std::stringstream aux;
    aux << _nombreReal << ";"
            << _apodo << ";"
            << _fechaDeNacimiento << ";"
            << _nacionalidad;

    return aux.str();
}

Mutante& Mutante::operator=(const Mutante& orig) {
    if (this != &orig) {
        _nombreReal = orig._nombreReal;
        _apodo = orig._apodo;
        _fechaDeNacimiento = orig._fechaDeNacimiento;
        _nacionalidad = orig._nacionalidad;

    }

    return  *this;
}

