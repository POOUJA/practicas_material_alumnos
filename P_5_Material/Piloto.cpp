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
 * @todo Si el número de misiones del piloto es 0, no puede tener incidencias;
 *       haz esta comprobación y lanza la excepción correspondiente
 */
void Piloto::setIncidenciasUltimaMision ( string incidenciasUltimaMision )
{
   this->_incidenciasUltimaMision = incidenciasUltimaMision;
}

string Piloto::getIncidenciasUltimaMision ( ) const
{
   return _incidenciasUltimaMision;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
void Piloto::setFechaUltimaMision ( long fechaUltimaMision )
{
   this->_fechaUltimaMision = fechaUltimaMision;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
long Piloto::getFechaUltimaMision ( ) const
{
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