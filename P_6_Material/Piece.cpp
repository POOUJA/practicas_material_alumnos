/** 
 * @file Piece.cpp
 * @author Yoyapro Gramo
 * 
 * @date Stellar date 20160317
 */

#include "Piece.h"

/**
 * @todo You have to check that the weight is not negative. If it is,
 *      you have to throw an exception of type std::invalid_argument
 */
Piece::Piece( string name, float weight,
              string description ): _name(name), _weight(weight),
                                     _description(description)
{
}

Piece::Piece ( const Piece& orig ): _name(orig._name), _weight(orig._weight),
                                    _description(orig._description)
{
}

Piece::~Piece ( )
{
}

void Piece::setDescripction( string description )
{
   this->_description = description;
}

string Piece::getDescription( ) const
{
   return _description;
}

/**
 * @todo You have to check that the weight is not negative. If it is,
 *      you have to throw an exception of type std::invalid_argument
 */
void Piece::setWeight( float weight )
{
   this->_weight = weight;
}

float Piece::getWeight( ) const
{
   return _weight;
}

void Piece::setName( string name )
{
   this->_name = name;
}

string Piece::getName( ) const
{
   return _name;
}

Piece& Piece::operator = (const Piece& orig)
{
   _name = orig._name;
   _description = orig._description;
   _weight = orig._weight;
   
   return ( *this );
}