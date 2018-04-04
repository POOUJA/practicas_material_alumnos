/** 
 * @file Droid.cpp
 * @author Casipro Gramo
 * 
 * @date Stellar date 20160309
 */

#include <sstream>

#include "Droid.h"

int Droid::_numDroids = 0;

Droid::Droid ( ): _brand(""), _model("")
{
   _numDroids++;
   _droidID = _numDroids;
}

Droid::Droid( string brand, string model ): _brand (brand), _model (model)
{
   _numDroids++;
   _droidID = _numDroids;
}

Droid::Droid ( const Droid& orig ): _brand(orig._brand), _model(orig._model)
{
   _numDroids++;
   _droidID = _numDroids;
}

Droid::~Droid ( )
{
}

int Droid::getDroidID( ) const
{
   return _droidID;
}

void Droid::setModel( string model )
{
   this->_model = model;
}

string Droid::getModel( ) const
{
   return _model;
}

void Droid::setBrand( string brand )
{
   this->_brand = brand;
}

string Droid::getBrand( ) const
{
   return _brand;
}

string Droid::toCSV ()
{
   std::stringstream aux;

   aux << _brand << " ; "
       << _model;

   return ( aux.str () );
}

Droid& Droid::operator =( const Droid &other )
{
   if ( this != &other )
   {
      _brand = other._brand;
      _model = other._model;
   }
   
   return ( *this );
}

void Droid::fromCSV( string &data )
{
   std::stringstream aux;

   aux << data;

   getline ( aux, this->_brand, ';' );
   getline ( aux, this->_model, ';' );
}