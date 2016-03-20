/** 
 * @file Piloto.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>
#include <iostream>

#include "Piloto.h"
#include "Informe.h"

int Piloto::_numPilotos = 0;

Piloto::Piloto ( ): _nombre(""), _nacionalidad(""), _numMisiones(0),
                    _fechaUltimaMision(0), _incidenciasUltimaMision(""), _nave(0),
                    _auxiliar(0)
{
   _numPilotos++;
   _idP = _numPilotos;
}

Piloto::Piloto ( string nombre, string nacionalidad, long fechaUM,
                 string incidenciasUM, int numMisiones, StarFighter *nave,
                 Droide *auxiliar ): _nombre (nombre), _nacionalidad (nacionalidad),
                                     _fechaUltimaMision (fechaUM),
                                     _incidenciasUltimaMision (incidenciasUM),
                                     _numMisiones (numMisiones), _nave (nave),
                                     _auxiliar (auxiliar)
{
   if ( numMisiones < 0 )
   {
      throw std::invalid_argument ( "Piloto::Piloto: el número de misiones no"
                                    " puede ser negativo" );
   }
   
   if ( ( numMisiones == 0 ) && ( incidenciasUM != "" ) )
   {
      throw std::invalid_argument ( "Piloto::Piloto: un piloto sin misiones no"
                                    " puede tener incidencias");
   }

   _numPilotos++;
   _idP = _numPilotos;
}

Piloto::Piloto ( const Piloto& orig ): _nombre(orig._nombre),
                                       _nacionalidad(orig._nacionalidad),
                                       _numMisiones(orig._numMisiones),
                                       _fechaUltimaMision(orig._fechaUltimaMision),
                                       _incidenciasUltimaMision(orig._incidenciasUltimaMision),
                                       _nave (0), _auxiliar(0)
{
   _numPilotos++;
   _idP = _numPilotos;
}

Piloto::~Piloto ( )
{
   if ( _nave != 0 )
   {
      std::cerr << "Piloto::~Piloto: se intenta destruir un piloto con nave"
                   " asignada";
   }
}

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

string Piloto::toCSV ()
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
      _nave = otro._nave;
      _auxiliar = otro._auxiliar;
   }
   
   return ( *this );
}

void Piloto::setNave ( StarFighter* nave )
{
   this->_nave = nave;
}

StarFighter* Piloto::getNave ( ) const
{
   return _nave;
}

void Piloto::setAuxiliar ( Droide* auxiliar )
{
   this->_auxiliar = auxiliar;
}

Droide* Piloto::getAuxiliar ( ) const
{
   return _auxiliar;
}

Informe Piloto::generaInforme ()
{
   std::stringstream aux;
   Informe nuevo;

   aux << "Nave: " << _nave->getIdSF ()
       << ". Droide: " << _auxiliar->getIdD ()
       << ". Incidencias: " << _incidenciasUltimaMision;

   nuevo.setIdPiloto (this->_idP);
   nuevo.setFechaEstelar (this->_fechaUltimaMision);
   nuevo.setDatosInforme (aux.str ());
   
   return ( nuevo );
}

void Piloto::fromCSV ( string& datos )
{
   std::stringstream aux;

   aux << datos;

   getline ( aux, this->_nombre, ';' );
   getline ( aux, this->_nacionalidad, ';' );
   aux >> this->_numMisiones;
   aux.ignore (1);
   aux >> this->_fechaUltimaMision;
   aux.ignore (1);
   getline ( aux, this->_incidenciasUltimaMision );
}