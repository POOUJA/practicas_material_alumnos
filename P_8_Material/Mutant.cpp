/**
 * @file Mutante.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <stdexcept>
#include <sstream>

#include "Mutant.h"
#include "PhysicalPower.h"
#include "PsychicPower.h"

Mutant::Mutant( string name, string nickname, int birthdate, string nationality )
    : _realName(name),
      _nickname(nickname),
      _birthdate(birthdate),
      _nationality(nationality),
      _numPowers(0) {
    
    for (int i = 0; i < MAX_POWERS; i++) {
        _powers[i] = 0;
    }
}

Mutant::Mutant(const Mutant& orig)
    : _realName(orig._realName),
    _nickname(orig._nickname),
    _birthdate(orig._birthdate),
    _nationality(orig._nationality),
    _numPowers(orig._numPowers) {
    
    for (int i = 0; i < orig._numPowers; i++) {
        //Are we copying correctly the powers?
        _powers[i] = new Power(*(orig._powers[i]));
    }
}

Mutant::~Mutant() {
    deletePowers( );
}

void Mutant::setRealName( string realName ) {
    this->_realName = realName;
}

string Mutant::getRealName( ) const {
    return _realName;
}

void Mutant::setNationality( string nationality ) {
    this->_nationality = nationality;
}

string Mutant::getNationality( ) const {
    return _nationality;
}

void Mutant::setBirthDate( int birthdate ) {
    this->_birthdate = birthdate;
}

int Mutant::getBirthdate( ) const {
    return _birthdate;
}

void Mutant::setNickname( string nickname ) {
    this->_nickname = nickname;
}

string Mutant::getNickname( ) const {
    return _nickname;
}

int Mutant::getNumPowers( ) const {
    return _numPowers;
}

const Power& Mutant::getPower( int which ) {
    if ((which < 0) || (which >= _numPowers)) {
        throw std::invalid_argument("Mutant::getGift: number of powers is incorrect");
    }

    return  *(_powers[which]);
}

void Mutant::addPower( string name, string description, string affectsTo, float destructiveCapacity ) {
    addPower( Power( name, description, affectsTo, destructiveCapacity ));
}

void Mutant::addPhysicalPower( string name, string description, string affectsTo, float destructiveCapacity ) {
    addPower( PhysicalPower( name, description, affectsTo, destructiveCapacity ));
}

void Mutant::addPsychicPowers( string name, string description, string affectsTo, float destructiveCapacity ) {
    addPower( PsychicPower( name, description, affectsTo, destructiveCapacity ));
}

void Mutant::addPower( const Power &power ) {
    if (_numPowers >= MAX_POWERS) {
        throw std::length_error("Mutant::addPower: Mutant does not admit more powers");
    }

    _powers[_numPowers] = new Power(power);
    _numPowers++;
}
void Mutant::addPower( const PhysicalPower &power ) {
    if (_numPowers >= MAX_POWERS) {
        throw std::length_error("Mutant::addPower(PhysicalPower): Mutant does not admit more powers");
    }

    _powers[_numPowers] = new PhysicalPower(power);
    _numPowers++;
}
void Mutant::addPower( const PsychicPower &power ) {
    if (_numPowers >= MAX_POWERS) {
        throw std::length_error("Mutant::addPower(PsychicPower): Mutant does not admit more powers");
    }

    _powers[_numPowers] = new PsychicPower(power);
    _numPowers++;
}

void Mutant::deletePower( int which ) {
    if ((which < 0) || (which >= _numPowers)) {
        throw std::invalid_argument("Mutant::deletePower: number of powers is incorrect");
    }

    delete _powers[which];

    for (int i = which; i < _numPowers - 1; i++) {
        _powers[i] = _powers[i + 1];
    }

    _powers[_numPowers - 1] = 0;

    _numPowers--;
}

void Mutant::deletePowers( ) {
    for (int i = _numPowers-1; i >=0 ; i--) {
        deletePower( i ); //We delete in backwards to avoid the reorganization of gaps
    }
}

float Mutant::totalDestructivePower( ) const{
    float aux = 0;
    for (int i = 0; i < _numPowers; i++) {
        aux += _powers[ i ]->getDestructiveCapacity( );
    }

    return  aux;
}

/**@brief CSV representation of a Mutant
   @post  Generates the basic CSV representation, without including the powers*/
string Mutant::toCSV() const{
    std::stringstream aux;
    aux << _realName << ";"
            << _nickname << ";"
            << _birthdate << ";"
            << _nationality;

    return aux.str();
}

/**@brief Assings information to a Mutant from its CSV representation
   @post  Assigns the basica information of a Mutant from its CSV representation,
          without including powers*/
void Mutant::fromCSV(std::string& text) {
    std::stringstream ss(text);
    std::getline(ss,_realName,';');
    std::getline(ss,_nickname,';');
    ss>>_birthdate;
    ss.ignore();
    std::getline(ss,_nationality,';');
}

Mutant& Mutant::operator=(const Mutant& orig) {
    if (this != &orig) {
        _realName = orig._realName;
        _nickname = orig._nickname;
        _birthdate = orig._birthdate;
        _nationality = orig._nationality;

        deletePowers( );

        _numPowers = orig._numPowers;

        for (int i = 0; i < _numPowers; i++) {
            _powers[i] = new Power(*orig._powers[i]);
        }
    }

    return  *this;
}

