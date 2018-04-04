/** 
 * @file StarFighter.cpp
 * @author Casipro Gramo
 * 
 * @date Stellar date 20160309
 */

#include <stdexcept>
#include <sstream>

#include "StarFighter.h"

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter ( ): _brand (""), _model (""), _seatsNumber (1)
{
   _numStarFighters++;
   _starFighterID = _numStarFighters;
}

StarFighter::StarFighter( string brand, string model, int seatsNumber ):
                           _brand (brand), _model(model), _seatsNumber(seatsNumber)
{
   if ( seatsNumber <= 0 )
   {
      throw std::invalid_argument ( "StarFighter::StarFighter: the number of"
                                            " seats can't be negative" );
   }

   _numStarFighters++;
   _starFighterID = _numStarFighters;
}

StarFighter::StarFighter ( const StarFighter& orig ): _brand(orig._brand),
                                                      _model(orig._model),
                                                      _seatsNumber(orig._seatsNumber)
{
   _numStarFighters++;
   _starFighterID = _numStarFighters;
}

StarFighter::~StarFighter ( )
{
}

/**
 * @todo You have to add the parameter checkup and throw the corresponding
 *       exception. The number of seats can't be <=0
 */
void StarFighter::setSeatsNumber( int seatsNumber )
{
   this->_seatsNumber = seatsNumber;
}t

int StarFighter::getSeatsNumber( ) const
{
   return _seatsNumber;
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

int StarFighter::getStarFighterID( ) const
{
   return _starFighterID;
}

string StarFighter::toCSV ()
{
   std::stringstream aux;

   aux << _brand << " ; "
       << _model << " ; "
       << _seatsNumber;

   return ( aux.str () );
}

StarFighter& StarFighter::operator =( const StarFighter &other )
{
   if ( this != &other )
   {
      _brand = other._brand;
      _model = other._model;
      _seatsNumber = other._seatsNumber;
   }
   
   return ( *this );
}

void StarFighter::fromCSV( string &data )
{
   std::stringstream aux;
   
   aux << data;
   
   getline ( aux, _brand, ';' );
   getline ( aux, _model, ';' );
   aux >> _seatsNumber;
}