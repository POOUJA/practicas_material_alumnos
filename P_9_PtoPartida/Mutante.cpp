/**
 * @file Mutante.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <stdexcept>
#include <sstream>

#include "Mutante.h"
#include "PoderFisico.h"
#include "PoderPsiquico.h"

Mutante::Mutante ( string nombre, string apodo, int fechaN,
                   string nacionalidad ): _nombreReal(nombre), _apodo(apodo),
                                          _fechaDeNacimiento(fechaN),
                                          _nacionalidad (nacionalidad), _numDones(0)
{
   for ( int i = 0; i < _MAX_DONES_; i++ )
   {
      _dones[i] = 0;
   }
}

Mutante::Mutante ( const Mutante& orig ): _nombreReal(orig._nombreReal),
                                          _apodo(orig._apodo),
                                          _fechaDeNacimiento(orig._fechaDeNacimiento),
                                          _nacionalidad(orig._nacionalidad),
                                          _numDones(orig._numDones)
{
   for ( int i = 0; i < orig._numDones; i++ )
   {
      _dones[i] = new Poder ( *(orig._dones[i]) );
   }
}

Mutante::~Mutante ( )
{
   for ( int i = 0; i < _numDones; i++ )
   {
      delete _dones[i];
      _dones[i] = 0;
   }
}

void Mutante::setNombreReal ( string nombreReal )
{
   this->_nombreReal = nombreReal;
}

string Mutante::getNombreReal ( ) const
{
   return _nombreReal;
}

void Mutante::setNacionalidad ( string nacionalidad )
{
   this->_nacionalidad = nacionalidad;
}

string Mutante::getNacionalidad ( ) const
{
   return _nacionalidad;
}

void Mutante::setFechaDeNacimiento ( int fechaDeNacimiento )
{
   this->_fechaDeNacimiento = fechaDeNacimiento;
}

int Mutante::getFechaDeNacimiento ( ) const
{
   return _fechaDeNacimiento;
}

void Mutante::setApodo ( string apodo )
{
   this->_apodo = apodo;
}

string Mutante::getApodo ( ) const
{
   return _apodo;
}

int Mutante::getNumDones () const
{
   return _numDones;
}

const Poder* Mutante::getDon ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numDones ) )
   {
      throw std::invalid_argument ( "Mutante::getDon: número de don incorrecto" );
   }

   return ( _dones[cual] );
}

void Mutante::addPoder ( string nombre, string descripcion, string afectaA,
                         float capacidadD )
{
   if ( _numDones >= _MAX_DONES_ )
   {
      throw std::length_error ("Mutante::addPoder: el mutante no admite más dones");
   }

   _dones[_numDones] = new Poder (nombre, descripcion, afectaA, capacidadD );
   _numDones++;
}

void Mutante::borraPoder ( int cual )
{
   if ( ( cual < 0 ) || ( cual >= _numDones ) )
   {
      throw std::invalid_argument ( "Mutante::borraPoder: número de don incorrecto" );
   }

   delete _dones[cual];

   for ( int i = cual; i < _numDones-1; i++ )
   {
      _dones[i] = _dones[i+1];
   }

   _dones[_numDones-1] = 0;

   _numDones--;
}

void Mutante::borraPoderes ()
{
   for ( int i = 0; i < _numDones; i++ )
   {
      delete _dones[i];
      _dones[i] = 0;
   }
}

float Mutante::capacidadDestructivaTotal ()
{
   float aux=0;
   for ( int i = 0; i < _numDones; i++ )
   {
      aux += _dones[i]->getCapacidadDestructiva ();
   }

   return ( aux );
}

string Mutante::toCSV ()
{
   std::stringstream aux;
   aux << _nombreReal << " ; "
       << _apodo << " ; "
       << _fechaDeNacimiento << " ; "
       << _nacionalidad;

   for ( int i = 0; i < _numDones; i++ )
   {
      aux << " ; " << _dones[i]->toCSV ();
   }

   return ( aux.str () );
}

Mutante& Mutante::operator = (const Mutante& orig)
{
   if ( this != &orig )
   {
      _nombreReal = orig._nombreReal;
      _apodo = orig._apodo;
      _fechaDeNacimiento = orig._fechaDeNacimiento;
      _nacionalidad = orig._nacionalidad;

      borraPoderes ();

      _numDones = orig._numDones;

      for ( int i = 0; i < _numDones; i++ )
      {
         _dones[i] = new Poder ( *orig._dones[i] );
      }
   }

   return ( *this );
}

void Mutante::addPoderFisico ( string nombre, string descripcion, string afectaA,
                               float capacidadD )
{
   if ( _numDones >= _MAX_DONES_ )
   {
      throw std::length_error ( "Mutante::addPoderFisico: el mutante no admite"
                                " más dones");
   }

   _dones[_numDones] = new PoderFisico (nombre, descripcion, afectaA, capacidadD );
   _numDones++;
}

void Mutante::addPoderPsiquico ( string nombre, string descripcion, string afectaA,
                                 float capacidadD )
{
   if ( _numDones >= _MAX_DONES_ )
   {
      throw std::length_error ( "Mutante::addPoderPsiquico: el mutante no admite"
                                " más dones");
   }

   _dones[_numDones] = new PoderPsiquico (nombre, descripcion, afectaA, capacidadD );
   _numDones++;
}