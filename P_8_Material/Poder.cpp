/**
 * @file Poder.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <stdexcept>
#include <sstream>

#include "Poder.h"

using std::string;

Poder::Poder ( string nmb, string dsc, string aA, float cD ):
       _nombre(nmb), _descripcion(dsc), _afectaA(aA), _capacidadDestructiva(cD)
{
   if ( cD < 0 )
   {
      throw std::invalid_argument ( "Poder::Poder: la capacidad destructiva no"
                                    " puede ser negativa" );
   }
}

Poder::Poder(const Poder& orig) : _nombre(orig._nombre),
                                  _descripcion(orig._descripcion),
                                  _afectaA(orig._afectaA),
                                  _capacidadDestructiva(orig._capacidadDestructiva)
{ }

Poder::~Poder ( )
{ }

void Poder::setNombre ( string nombre )
{
   this->_nombre = nombre;
}

string Poder::getNombre ( ) const
{
   return _nombre;
}

void Poder::setCapacidadDestructiva ( float capacidadDestructiva )
{
   if ( capacidadDestructiva < 0 )
   {
       throw std::invalid_argument ( "Poder::setCapacidadDestructiva: el valor"
                                     " de capacidad no puede ser negativo" );
   }

   this->_capacidadDestructiva = capacidadDestructiva;
}

float Poder::getCapacidadDestructiva ( ) const
{
   return _capacidadDestructiva;
}

void Poder::setAfectaA ( string afectaA )
{
   this->_afectaA = afectaA;
}

string Poder::getAfectaA ( ) const
{
   return _afectaA;
}

void Poder::setDescripcion ( string descripcion )
{
   this->_descripcion = descripcion;
}

string Poder::getDescripcion ( ) const
{
   return _descripcion;
}

string Poder::toCSV ( ) const
{
   std::stringstream aux;

   aux << _nombre << ";"
       << _descripcion << ";"
       << _afectaA << ";"
       << _capacidadDestructiva;

   return aux.str ( );
}

Poder& Poder::operator= ( const Poder& orig )
{
   if ( this != &orig )
   {
      _nombre = orig._nombre;
      _descripcion = orig._descripcion;
      _afectaA = orig._afectaA;
      _capacidadDestructiva = orig._capacidadDestructiva;
   }

   return *this;
}