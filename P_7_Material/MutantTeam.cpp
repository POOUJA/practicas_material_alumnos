/**
 * @file MutantTeam.cpp
 * @author algarcia
 *
 * @date April 6th, 2016
 */

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "MutantTeam.h"

MutantTeam::MutantTeam( string name, string base )
    : _name(name),
    _base(base),
    _numMembers(0) {

    for (int i = 0; i < _MAX_MEMBERS_; i++) {
        _members[i] = 0;
    }
}

MutantTeam::MutantTeam(const MutantTeam& orig)
    : _name(orig._name),
    _base(orig._base),
    _numMembers(orig._numMembers) {
    
    for (int i = 0; i < _MAX_MEMBERS_; i++) {
        _members[i] = orig._members[i];
    }
}

MutantTeam::~MutantTeam() {
    if (_numMembers > 0) {
        for (int i = 0; i < _numMembers; i++) {
            _members[i] = 0;
        }
    }
}

void MutantTeam::setName( string name ) {
    this->_name = name;
}

string MutantTeam::getName( ) const {
    return _name;
}

int MutantTeam::getNumMembers( ) const {
    return _numMembers;
}

void MutantTeam::setBase(string base) {
    this->_base = base;
}

string MutantTeam::getBase() const {
    return _base;
}

void MutantTeam::addMutant( Mutant *m ) {
    if (_numMembers == _MAX_MEMBERS_) {
        throw std::length_error("MutantTeam::addMutant: the team is full.");
    }

    _members[_numMembers] = m;
    _numMembers++;
}

Mutant* MutantTeam::getMutant( int which ) {
    if ((which < 0) || (which >= _numMembers)) {
        throw std::invalid_argument("MutantTeam::getMutant: member value"
                                            " is incorrect.");
    }

    return _members[which];
}

Mutant* MutantTeam::removeMutant( int which ) {
    Mutant *aux;

    if ((which < 0) || (which >= _numMembers)) {
        throw std::invalid_argument("MutantTeam::getMutant: member value"
                                            " is incorrect.");
    }

    aux = _members[which];
    _members[which] = 0;

    if (_numMembers > 1) {
        _members[which] = _members[_numMembers - 1];
        _members[_numMembers - 1] = 0;
    }

    _numMembers--;

    return  aux;
}

string MutantTeam::toCSV() {
    std::stringstream aux;

    aux << _name << ";"
            << _base;

    for (int i = 0; i < _numMembers; i++) {
        aux << ";" << _members[i]->toCSV();
    }

    return  aux.str();
}

MutantTeam& MutantTeam::operator=(const MutantTeam& orig) {
    if (this != &orig) {
        _name = orig._name;
        _base = orig._base;
        _numMembers = orig._numMembers;

        for (int i = 0; i < _MAX_MEMBERS_; i++) {
            _members[i] = orig._members[i];
        }
    }

    return  *this;
}