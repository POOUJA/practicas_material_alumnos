/**
 * @file Mutante.cpp
 * @author algarcia
 *
 */

#include <stdexcept>
#include <sstream>

#include "Mutant.h"

Mutant::Mutant( string name, string nickname, int birthdate, string nationality )
    : _realName(name),
      _nickname(nickname),
      _birthDate(birthdate),
      _nationality(nationality)
      {
    
}

Mutant::Mutant(const Mutant& orig)
    : _realName(orig._realName),
    _nickname(orig._nickname),
    _birthDate(orig._birthDate),
    _nationality(orig._nationality)
 {
    
}

Mutant::~Mutant() {
}

void Mutant::setRealName( string nombreReal ) {
    this->_realName = nombreReal;
}

string Mutant::getRealName( ) const {
    return _realName;
}

void Mutant::setNationality( string nacionalidad ) {
    this->_nationality = nacionalidad;
}

string Mutant::getNationality( ) const {
    return _nationality;
}

void Mutant::setBirthDate( int birthDate ) {
    this->_birthDate = birthDate;
}

int Mutant::getBirthDate( ) const {
    return _birthDate;
}

void Mutant::setNickname( string nickname ) {
    this->_nickname = nickname;
}

string Mutant::getNickname( ) const {
    return _nickname;
}

/**@brief CSV representation of a mutant
 * @post Generates a basic CSV representation, without including powers*/
string Mutant::toCSV() const{
    std::stringstream aux;
    aux << _realName << ";"
            << _nickname << ";"
            << _birthDate << ";"
            << _nationality;

    return aux.str();
}

Mutant& Mutant::operator=(const Mutant& orig) {
    if (this != &orig) {
        _realName = orig._realName;
        _nickname = orig._nickname;
        _birthDate = orig._birthDate;
        _nationality = orig._nationality;

    }

    return  *this;
}

