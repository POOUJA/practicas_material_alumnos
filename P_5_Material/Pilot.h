/** 
 * @file Pilot.h
 * @author Yoyapro Gramo
 *
 * @date Stellar date 20160309
 */

#ifndef PILOT_H
#define PILOT_H

#include <string>

using std::string;

/**
 * @brief
 */
class Pilot
{
   private:
      static int _numPilots; ///< Number of Pilot objects that have been instantiated
      int _pilotID; ///< Unique Pilot identifier
      string _name; ///< Pilot's name
      string _nationality; ///< Pilot's nationality
      int _numMissions; ///< Number of participated missions
      long _dateLastMission; ///< Stellar date of last mission
      string _incidentsLastMission; ///< Reported incidents by the Pilot in his last mission

   public:
      Pilot ( );
      Pilot( string name, string nationality = "", long dateLM = 0,
             string incidentsLM = "", int numMissions = 0 );
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
      string toCSV () const;
      Pilot& operator=( const Pilot &other );
};

#endif /* PILOT_H
 **/

