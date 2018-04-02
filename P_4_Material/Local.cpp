/**
 * @brief Implementation of the Local class
 * @file Local.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:51
 */

#include "Local.h"

/**
 * @brief Default constructor of the class
 * @param name Name of the Local
 * @param address Address of the Local
 * @post Creates a new object of class Local
 */
Local::Local( std::string name, std::string address ) :
_name(name)
, _address(address) {
}

/**
 * @brief Copy constructor of the class
 * @param orig Object of type Local from which data are being copied
 * @post Creates a new object of class Local
 */

Local::Local( const Local &orig ) :
_name(orig._name)
, _address(orig._address) {
}

/**
 * @brief Destructor of the class
 * @post Destroys the object
 */
Local::~Local() {
}

/**
 * @brief Modifies the new address of the Local
 * @param address New address
 * @post Modifies the address of the Local
 */
void Local::setAddress( std::string address ) {
   if ( address == "" )
      throw std::string ( "Trying to assing an empty address" );

   this->_address = address;
}

/**
 * @brief Returns the address of the Local
 * @post Returns the address of the Local
 */
std::string Local::getAddress( ) const {
    return _address;
}

/**
 * @brief Modies the name of the Local
 * @param name New name for the Local
 * @post Modies the name of the Local
 */
void Local::setName( std::string name ) {
   if ( name == "" )
      throw std::string ( "Trying to assign an empty name" );

   this->_name = name;
}

/**
 * @brief Returns the name of the Local
 * @post Returns the name of the Local
 */
std::string Local::getName( ) const {
    return _name;
}

