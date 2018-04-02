/** 
 * @file Pilo.h
 * @author Casipro Gramo
 *
 * @date Stellar date 20160309
 */

#ifndef PILOT_H
#define PILOT_H

#include <string>
#include "StarFighter.h"
#include "Droid.h"
#include "Report.h"

using std::string;

/**
 * @brief
 */
class Pilot
{
   private:
      static int _numPilots;
      int _pilotID;
      string _name;
      string nationality;
      int _numMission;
      long _dateLastMission;
      string _incidentsLastMission;
      StarFighter *_spaceship;
      Droid *_auxiliar;

   public:
      Pilot( );
      Pilot( string name, string nacionalidad = "", long dateLM = 0,
             string incidentsLM = "", int numMissions = 0, StarFighter *spaceship = 0,
             Droid *auxiliar = 0 );
      Pilot ( const Pilot& orig );
      virtual ~Pilot ( );
      void setNumMissions( int numMissions );
      int getNumMissions( ) const;
      void setNationality( string nationality );
      string getNationality( ) const;
      void setName( string name );
      string getName( ) const;
      int getPilotID( ) const;
      void setIncidentsLastMission( string incidentsLastMission );
      string getIncidentsLastMission( ) const;
      void setDateLastMission( long dateLastMission );
      long getDateLastMission( ) const;
      string toCSV ();
      Pilot& operator=( const Pilot &other );
      void setSpaceship( StarFighter *spaceship );
      StarFighter* getSpaceship( ) const;
      void setAuxiliar ( Droid* auxiliar );
      Droid* getAuxiliar ( ) const;
      Report generateReport( );
      void fromCSV( string &data );
};

#endif /* PILOT_H */

