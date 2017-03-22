/** 
 * @file Droide.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <sstream>

#include "Droide.h"

int Droide::_numDroides = 0;

Droide::Droide ( ): _marca(""), _modelo("")
{
   _numDroides++;
   _idD = _numDroides;
}

Droide::Droide ( string marca, string modelo ): _marca (marca), _modelo (modelo)
{
   _numDroides++;
   _idD = _numDroides;
}

Droide::Droide ( const Droide& orig ): _marca(orig._marca), _modelo(orig._modelo)
{
   _numDroides++;
   _idD = _numDroides;
}

Droide::~Droide ( )
{
}

int Droide::getIdD ( ) const
{
   return _idD;
}

void Droide::setModelo ( string modelo )
{
   this->_modelo = modelo;
}

string Droide::getModelo ( ) const
{
   return _modelo;
}

void Droide::setMarca ( string marca )
{
   this->_marca = marca;
}

string Droide::getMarca ( ) const
{
   return _marca;
}

string Droide::toCSV ()
{
   std::stringstream aux;

   aux << _marca << " ; "
       << _modelo;

   return ( aux.str () );
}

Droide& Droide::operator = ( const Droide& otro )
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
   }
   
   return ( *this );
}

void Droide::fromCSV ( string& datos )
{
   std::stringstream aux;

   aux << datos;

   getline ( aux, this->_marca, ';' );
   getline ( aux, this->_modelo, ';' );
}