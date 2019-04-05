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

using std::string;

Mutante::Mutante ( ): Mutante ( "---", "---", 0, "---" )
{ }

Mutante::Mutante ( string nombre, string apodo, int fechaN, string nacionalidad ): 
         _nombreReal ( nombre ), _apodo ( apodo ), _fechaDeNacimiento ( fechaN ),
         _nacionalidad ( nacionalidad ), _numPoderes ( 0 )
{
   for ( int i = 0; i < MAX_PODERES; i++ )
   {
      _poderes[i] = nullptr;
   }
}

Mutante::Mutante ( const Mutante& orig ): _nombreReal ( orig._nombreReal ),
         _apodo ( orig._apodo ), _fechaDeNacimiento ( orig._fechaDeNacimiento ),
         _nacionalidad ( orig._nacionalidad ), _numPoderes ( orig._numPoderes )
{
   for ( int i = 0; i < orig._numPoderes; i++ )
   {
      //¿Estamos copiando correctamente los Poderes?
      _poderes[i] = new Poder ( *(orig._poderes[i]) );
   }
}

Mutante::~Mutante ( )
{
   borraPoderes ( );
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

int Mutante::getNumPoderes ( ) const
{
   return _numPoderes;
}

const Poder& Mutante::getPoder ( int cual )
{
   if ( (cual < 0) || (cual >= _numPoderes) )
   {
      throw std::invalid_argument ( "Mutante::getDon: número de don incorrecto" );
   }

   return *(_poderes[cual]);
}

void Mutante::addPoder ( string nombre, string descripcion, string afectaA,
                         float capacidadD )
{
   addPoder ( Poder ( nombre, descripcion, afectaA, capacidadD ) );
}

void Mutante::addPoderFisico ( string nombre, string descripcion,
                               string afectaA, float capacidadD )
{
   addPoder ( PoderFisico ( nombre, descripcion, afectaA, capacidadD ) );
}

void Mutante::addPoderPsiquico ( string nombre, string descripcion,
                                 string afectaA, float capacidadD )
{
   addPoder ( PoderPsiquico ( nombre, descripcion, afectaA, capacidadD ) );
}

void Mutante::addPoder ( const Poder& poder )
{
   if ( _numPoderes >= MAX_PODERES )
   {
      throw std::length_error ( "Mutante::addPoder: el mutante no admite más"
                                " dones" );
   }

   _poderes[_numPoderes] = new Poder ( poder );
   _numPoderes++;
}

void Mutante::addPoder ( const PoderFisico& poder )
{
   if ( _numPoderes >= MAX_PODERES )
   {
      throw std::length_error ( "Mutante::addPoder(PoderFisico): el mutante no"
                                " admite más dones" );
   }

   _poderes[_numPoderes] = new PoderFisico ( poder );
   _numPoderes++;
}

void Mutante::addPoder ( const PoderPsiquico& poder )
{
   if ( _numPoderes >= MAX_PODERES )
   {
      throw std::length_error ( "Mutante::addPoder(PoderPsiquico): el mutante no"
                                " admite más dones" );
   }

   _poderes[_numPoderes] = new PoderPsiquico ( poder );
   _numPoderes++;
}

void Mutante::borraPoder ( int cual )
{
   if ( (cual < 0) || (cual >= _numPoderes) )
   {
      throw std::invalid_argument ( "Mutante::borraPoder: número de don"
                                    " incorrecto" );
   }

   delete _poderes[cual];

   for ( int i = cual; i < _numPoderes-1; i++ )
   {
      _poderes[i] = _poderes[i + 1];
   }

   _poderes[_numPoderes-1] = nullptr;

   _numPoderes--;
}

void Mutante::borraPoderes ( )
{
   for ( int i = _numPoderes-1; i >=0 ; i-- )
   {
      borraPoder ( i ); //Borramos hacia atrás para evitar la reorganización de huecos
   }
}

float Mutante::capacidadDestructivaTotal ( ) const
{
   float aux = 0;
   for ( int i = 0; i < _numPoderes; i++ )
   {
      aux += _poderes[i]->getCapacidadDestructiva ( );
   }

   return  aux;
}

/**@brief Representación CSV de un mutante
   @post  Genera la representación básica en CSV, sin incluir los poderes*/
string Mutante::toCSV () const
{
    std::stringstream aux;
    aux << _nombreReal << ";"
        << _apodo << ";"
        << _fechaDeNacimiento << ";"
        << _nacionalidad;

    return aux.str();
}

/**@brief Asigna información a un mutante a partir de su representación CSV
   @post  Asigna la información básica de un mutante a partir de su presentación CSV, sin incluir los poderes*/
void Mutante::fromCSV ( std::string& cadena )
{
   std::stringstream ss ( cadena );
   std::getline ( ss,_nombreReal, ';' );
   std::getline ( ss,_apodo, ';' );
   ss>>_fechaDeNacimiento;
   ss.ignore ( );
   std::getline ( ss, _nacionalidad, ';' );
}

Mutante& Mutante::operator= ( const Mutante& orig )
{
   if ( this != &orig )
   {
      _nombreReal = orig._nombreReal;
      _apodo = orig._apodo;
      _fechaDeNacimiento = orig._fechaDeNacimiento;
      _nacionalidad = orig._nacionalidad;

      borraPoderes ( );

      _numPoderes = orig._numPoderes;

      for ( int i = 0; i < _numPoderes; i++ )
      {
         _poderes[i] = new Poder ( *orig._poderes[i] );
      }
   }

   return  *this;
}