/** 
 * @file Pilot.cpp
 * @author Casipro Gramo
 * 
 * @date Stellar date 20160309
 */

#include <stdexcept>
#include <sstream>
#include <iostream>

#include "Pilot.h"
#include "Report.h"

int Pilot::_numPilots = 0;

Pilot::Pilot( ): _name(""), nationality(""), _numMission(0),
                    _dateLastMission(0), _incidentsLastMission(""), _spaceship(0),
                    _auxiliar(0)
{
   _numPilots++;
   _pilotID = _numPilots;
}

Pilot::Pilot( string name, string nacionalidad, long dateLM,
              string incidentsLM, int numMissions, StarFighter *spaceship,
              Droid *auxiliar ): _name (name), nationality (nacionalidad),
                                     _dateLastMission (dateLM),
                                     _incidentsLastMission (incidentsLM),
                                     _numMission (numMissions), _spaceship (spaceship),
                                     _auxiliar (auxiliar)
{
   if ( numMissions < 0 )
   {
      throw std::invalid_argument ( "Pilot::Pilot: the number of missions"
                                            " can't be negative" );
   }
   
   if ( ( numMissions == 0 ) && ( incidentsLM != "" ) )
   {
      throw std::invalid_argument ( "Pilot::Pilot: a pilot without missions"
                                            " can't have incidents");
   }

   _numPilots++;
   _pilotID = _numPilots;
}

Pilot::Pilot ( const Pilot& orig ): _name(orig._name),
                                       nationality(orig.nationality),
                                       _numMission(orig._numMission),
                                       _dateLastMission(orig._dateLastMission),
                                       _incidentsLastMission(orig._incidentsLastMission),
                                       _spaceship (0), _auxiliar(0)
{
   _numPilots++;
   _pilotID = _numPilots;
}

Pilot::~Pilot ( )
{
   if ( _spaceship != 0 )
   {
      std::cerr << "Pilot::Pilot trying to destroy a Pilot with an assignated"
              " spaceship";
   }
	 if ( _auxiliar != 0 )
   {
       std::cerr << "Pilot::Pilot trying to destroy a Pilot with an assignated"
               " auxiliar";
   }
}

/**
 * @todo Here you have to add the parameter checkup and throw the corresponding
 *       exception. The number of missions can't be <= 0
 */
void Pilot::setNumMissions( int numMissions )
{
   this->_numMission = numMissions;
}

int Pilot::getNumMissions( ) const
{
   return _numMission;
}

void Pilot::setNationality( string nacionalidad )
{
   this->nationality = nacionalidad;
}

string Pilot::getNationality( ) const
{
   return nationality;
}

void Pilot::setName( string name )
{
   this->_name = name;
}

string Pilot::getName( ) const
{
   return _name;
}

int Pilot::getPilotID( ) const
{
   return _pilotID;
}

/**
 * @todo If the number of missions is 0, it is not possible to
 *       have incidents; do the checkup and throw the corresponding
 *       exception
 */
void Pilot::setIncidentsLastMission( string incidentsLastMission )
{
   this->_incidentsLastMission = incidentsLastMission;
}

string Pilot::getIncidentsLastMission( ) const
{
   return _incidentsLastMission;
}

/**
 * @todo If the Pilot's missions number is 0, it is not possible to
 *       have a date of last mission; do the checkup and throw the
 *       corresponding exception
 */
void Pilot::setDateLastMission( long dateLastMission )
{
   this->_dateLastMission = dateLastMission;
}

/**
 * @todo If the Pilot's missions number is 0, it is not possible to
 *       have a date of last mission; do the checkup and throw the
 *       corresponding exception
 */
long Pilot::getDateLastMission( ) const
{
   return _dateLastMission;
}

string Pilot::toCSV ()
{
   std::stringstream aux;

   aux << _name << " ; "
       << nationality << " ; "
       << _numMission << " ; "
       << _dateLastMission << " ; "
       << _incidentsLastMission;

   return ( aux.str () );
}

Pilot& Pilot::operator =( const Pilot &other )
{
   if ( this != &other )
   {
      _name = other._name;
      nationality = other.nationality;
      _numMission = other._numMission;
      _dateLastMission = other._dateLastMission;
      _incidentsLastMission = other._incidentsLastMission;
      _spaceship = other._spaceship;
      _auxiliar = other._auxiliar;
   }
   
   return ( *this );
}

void Pilot::setSpaceship( StarFighter *spaceship )
{
   this->_spaceship = spaceship;
}

StarFighter* Pilot::getSpaceship( ) const
{
   return _spaceship;
}

void Pilot::setAuxiliar ( Droid* auxiliar )
{
   this->_auxiliar = auxiliar;
}

Droid* Pilot::getAuxiliar ( ) const
{
   return _auxiliar;
}

Report Pilot::generateReport( )
{
   std::stringstream aux;
   Report nuevo;

   aux << "Spaceship: " << _spaceship->getStarFighterID( )
       << ". Droid: " << _auxiliar->getDroidID( )
       << ". Incidents: " << _incidentsLastMission;

    nuevo.setPilotID( this->_pilotID );
    nuevo.setStellarDate( this->_dateLastMission );
    nuevo.setReportData( aux.str( ));
   
   return ( nuevo );
}

void Pilot::fromCSV( string &data )
{
   std::stringstream aux;

   aux << data;

   getline ( aux, this->_name, ';' );
   getline ( aux, this->nationality, ';' );
   aux >> this->_numMission;
   aux.ignore (1);
   aux >> this->_dateLastMission;
   aux.ignore (1);
   getline ( aux, this->_incidentsLastMission );
}