/** 
 * @file Pilot.cpp
 * @author Yoyapro Gramo
 * 
 * @date Stellar date 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Pilot.h"

int Pilot::_numPilots = 0;

Pilot::Pilot ( ): _name(""), _nationality(""), _numMissions(0),
                    _dateLastMission(0), _incidentsLastMission("")
{
   _numPilots++;
   _pilotID = _numPilots;
}

Pilot::Pilot( string name, string nationality, long dateLM,
              string incidentsLM, int numMissions ):
                 _name (name), _nationality (nationality),
                 _dateLastMission (dateLM),
                 _incidentsLastMission ( incidentsLM ),
                 _numMissions ( numMissions )
{
   if ( numMissions < 0 )
   {
      throw std::invalid_argument ( "Pilot::Pilot: the number of missions"
                                            " can't be negative");
   }
   
   if ( ( numMissions == 0 ) && ( incidentsLM != "" ) )
   {
      throw std::invalid_argument ( "Pilot::Pilot: a Pilot without missions"
                                            " can't have incident");
   }

   _numPilots++;
   _pilotID = _numPilots;
}

Pilot::Pilot ( const Pilot& orig ): _name(orig._name),
                                       _nationality(orig._nationality),
                                       _numMissions(orig._numMissions),
                                       _dateLastMission(orig._dateLastMission),
                                       _incidentsLastMission(orig._incidentsLastMission)
{
   _numPilots++;
   _pilotID = _numPilots;
}

Pilot::~Pilot ( )
{
}

/**
 * @todo Here you have to add the parameter checking and throw the corresponding
 *       exception. The number of missions can't be <= 0
 */
void Pilot::setNumMissions( int numMissions )
{
   this->_numMissions = numMissions;
}

int Pilot::getNumMissions( ) const
{
   return _numMissions;
}

void Pilot::setNationality( string nationality )
{
   this->_nationality = nationality;
}

string Pilot::getNationality( ) const
{
   return _nationality;
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
 * @todo If the number of missions of the Pilot is 0, the Pilot can't have incidents
 *       Do this checkup and throw the corresponding exception
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
 * @todo If the number of missions of the Pilot is 0, the Pilot can't
 *       have a date of last missions; do this checkup and throw the
 *       corresponding exception
 */
void Pilot::setDateLastMission( long dateLastMission )
{
   this->_dateLastMission = dateLastMission;
}

/**
 * @todo If the number of missions of the Pilot is 0, the Pilot can't
 *       have a date of last missions; do this checkup and throw the
 *       corresponding exception.
 */
long Pilot::getDateLastMission( ) const
{
   return _dateLastMission;
}

string Pilot::toCSV () const
{
   std::stringstream aux;

   aux << _name << " ; "
       << _nationality << " ; "
       << _numMissions << " ; "
       << _dateLastMission << " ; "
       << _incidentsLastMission;

   return ( aux.str () );
}

Pilot& Pilot::operator =( const Pilot &other )
{
   if ( this != &other )
   {
      _name = other._name;
      _nationality = other._nationality;
      _numMissions = other._numMissions;
      _dateLastMission = other._dateLastMission;
      _incidentsLastMission = other._incidentsLastMission;
   }
   
   return ( *this );
}