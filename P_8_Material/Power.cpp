/**
 * @file Poder.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <stdexcept>
#include <sstream>

#include "Power.h"

Power::Power( string name, string description, string affectsTo, float destructiveCapacity ) :
_name(name), _description(description), _affectsTo(affectsTo),
_destructiveCapacity(destructiveCapacity) {
    if (destructiveCapacity < 0) {
        throw std::invalid_argument("Power::Power: destructive capacity can't be negative");
    }
}

Power::Power(const Power& orig) : _name(orig._name),
_description(orig._description),
_affectsTo(orig._affectsTo),
_destructiveCapacity(orig._destructiveCapacity) {
}

Power::~Power() {
}

void Power::setName( string name ) {
    this->_name = name;
}

string Power::getName( ) const {
    return _name;
}

void Power::setDestructiveCapacity( float destructiveCapacity ) {
    if (destructiveCapacity < 0) {
        throw std::invalid_argument("Power::setDestructiveCapacity: the value "
                                            "of the capacity can't be negative");
    }

    this->_destructiveCapacity = destructiveCapacity;
}

float Power::getDestructiveCapacity( ) const {
    return _destructiveCapacity;
}

void Power::setAffectsTo( string affectsTo ) {
    this->_affectsTo = affectsTo;
}

string Power::getAffectsTo( ) const {
    return _affectsTo;
}

void Power::setDescription( string description ) {
    this->_description = description;
}

string Power::getDescription( ) const {
    return _description;
}

string Power::toCSV() const{
    std::stringstream aux;

    aux << _name << ";"
            << _description << ";"
            << _affectsTo << ";"
            << _destructiveCapacity;

    return ( aux.str());
}

Power& Power::operator=(const Power& orig) {
    if (this != &orig) {
        _name = orig._name;
        _description = orig._description;
        _affectsTo = orig._affectsTo;
        _destructiveCapacity = orig._destructiveCapacity;
    }

    return ( *this);
}

