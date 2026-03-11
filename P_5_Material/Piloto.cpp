/** 
 * @file Piloto.cpp
 * @author Yoyapro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Piloto.h"

using std::string;

int Piloto::_numPilotos = 0;

Piloto::Piloto ( ): Piloto ( "" )
{ }

Piloto::Piloto ( string nombre ): _nombre (nombre)
{
   _numPilotos++;
   _idP = _numPilotos;
}

Piloto::Piloto ( const Piloto& orig ): _nombre(orig._nombre),
                                       _nacionalidad(orig._nacionalidad),
                                       _numMisiones(orig._numMisiones),
                                       _fechaUltimaMision(orig._fechaUltimaMision),
                                       _incidenciasUltimaMision(orig._incidenciasUltimaMision)
{
   _numPilotos++;
   _idP = _numPilotos;
}

Piloto::~Piloto ( )
{ }

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de misiones no puede ser <= 0
 */
void Piloto::setNumMisiones ( int numMisiones )
{
   this->_numMisiones = numMisiones;
}

int Piloto::getNumMisiones ( ) const
{
   return _numMisiones;
}

void Piloto::setNacionalidad ( string nacionalidad )
{
   this->_nacionalidad = nacionalidad;
}

string Piloto::getNacionalidad ( ) const
{
   return _nacionalidad;
}

void Piloto::setNombre ( string nombre )
{
   this->_nombre = nombre;
}

string Piloto::getNombre ( ) const
{
   return _nombre;
}

int Piloto::getIdP ( ) const
{
   return _idP;
}

/**
 * @pre El número de misiones del piloto debe ser mayor que 0, en otro caso, no puede tener incidencias
  */
void Piloto::setIncidenciasUltimaMision ( string incidenciasUltimaMision )
{
     // TODO: verificar precondición utilizando assert
   this->_incidenciasUltimaMision = incidenciasUltimaMision;
}

string Piloto::getIncidenciasUltimaMision ( ) const
{
   return _incidenciasUltimaMision;
}

/**
 * @pre El número de misiones del piloto debe ser mayor que 0, en otro caso, no puede tener fecha de
 *       última misión
 */
void Piloto::setFechaUltimaMision ( long fechaUltimaMision )
{
   // TODO: verificar precondición utilizando assert
   this->_fechaUltimaMision = fechaUltimaMision;
}

/**
 * @pre El número de misiones del piloto debe ser mayor que 0, en otro caso, no puede tener fecha de
 *       última misión
 */
long Piloto::getFechaUltimaMision ( ) const
{
   // TODO: verificar precondición utilizando assert
   return _fechaUltimaMision;
}

string Piloto::toCSV () const
{
   std::stringstream aux;

   aux << _nombre << " ; "
       << _nacionalidad << " ; "
       << _numMisiones << " ; "
       << _fechaUltimaMision << " ; "
       << _incidenciasUltimaMision;

   return ( aux.str () );
}

Piloto& Piloto::operator = ( const Piloto& otro )
{
   if ( this != &otro )
   {
      _nombre = otro._nombre;
      _nacionalidad = otro._nacionalidad;
      _numMisiones = otro._numMisiones;
      _fechaUltimaMision = otro._fechaUltimaMision;
      _incidenciasUltimaMision = otro._incidenciasUltimaMision;
   }
   
   return ( *this );
}
