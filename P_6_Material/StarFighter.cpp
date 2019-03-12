/** 
 * @file StarFighter.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "StarFighter.h"

using std::string;

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter ( ): StarFighter ( "", "" ) {
}

StarFighter::StarFighter ( string marca, string modelo ):
                           _marca (marca), _modelo(modelo)
{
   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::StarFighter ( const StarFighter& orig ):
    _marca(orig._marca),_modelo(orig._modelo),
    _numPlazas(orig._numPlazas)
{
   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::~StarFighter ( )
{
}

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de plazas no puede ser <= 0
 */
StarFighter& StarFighter::setNumPlazas ( int numPlazas )
{
   if ( numPlazas <= 0 )
   {
      throw std::invalid_argument ( "StarFighter::StarFighter: el número de"
                                    " plazas no puede ser negativo" );
   }

    this->_numPlazas = numPlazas;
    return *this;
}

int StarFighter::getNumPlazas ( ) const
{
   return _numPlazas;
}

StarFighter& StarFighter::setModelo ( string modelo )
{
   this->_modelo = modelo;
   return *this;
}

string StarFighter::getModelo ( ) const
{
   return _modelo;
}

StarFighter& StarFighter::setMarca ( string marca )
{
   this->_marca = marca;
   return *this;
}

string StarFighter::getMarca ( ) const
{
   return _marca;
}

int StarFighter::getIdSF ( ) const
{
   return _idSF;
}

string StarFighter::toCSV () const
{
   std::stringstream aux;

   aux << _marca << " ; "
       << _modelo << " ; "
       << _numPlazas;

   return aux.str ();
}

StarFighter& StarFighter::operator = (const StarFighter& otro)
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
      _numPlazas = otro._numPlazas;
   }
   
   return *this;
}

void StarFighter::fromCSV (string& datos)
{
   std::stringstream aux;
   
   aux << datos;
   
   getline ( aux, _marca, ';' );
   getline ( aux, _modelo, ';' );
   aux >> _numPlazas;
}