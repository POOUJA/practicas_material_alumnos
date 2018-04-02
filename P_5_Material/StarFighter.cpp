/** 
 * @file StarFighter.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "StarFighter.h"

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter ( ): _brand (""), _model (""), _numSeats (1)
{
   _numStarFighters++;
   _SFid = _numStarFighters;
}

StarFighter::StarFighter( string brand, string model, int numSeats ):
                           _brand (brand), _model(model), _numSeats(numSeats)
{
   if ( numSeats <= 0 )
   {
      throw std::invalid_argument ( "StarFighter::StarFighter: the number of"
                                            "seats can't be negative" );
   }

   _numStarFighters++;
   _SFid = _numStarFighters;
}

StarFighter::StarFighter ( const StarFighter& orig ): _brand(orig._brand),
                                                      _model(orig._model),
                                                      _numSeats(orig._numSeats)
{
   _numStarFighters++;
   _SFid = _numStarFighters;
}

StarFighter::~StarFighter ( )
{
}

/**
 * @todo Here you have to add the parameter checking and throw the corresponding
 *       exception. The number of seats can't be <= 0
 */
void StarFighter::setNumSeats( int numSeats )
{
   this->_numSeats = numSeats;
}

int StarFighter::getNumSeats( ) const
{
   return _numSeats;
}

void StarFighter::setModel( string model )
{
   this->_model = model;
}

string StarFighter::getModel( ) const
{
   return _model;
}

void StarFighter::setBrand( string brand )
{
   this->_brand = brand;
}

string StarFighter::getBrand( ) const
{
   return _brand;
}

int StarFighter::getSFid( ) const
{
   return _SFid;
}

string StarFighter::toCSV () const
{
   std::stringstream aux;

   aux << _brand << " ; "
       << _model << " ; "
       << _numSeats;

   return ( aux.str () );
}

StarFighter& StarFighter::operator =( const StarFighter &other )
{
   if ( this != &other )
   {
      _brand = other._brand;
      _model = other._model;
      _numSeats = other._numSeats;
   }
   
   return ( *this );
}