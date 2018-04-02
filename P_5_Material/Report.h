/** 
 * @file Informe.h
 * @author Casipro Gramo
 *
 * @date Stellar date 20160309
 */

#ifndef REPORT_H
#define REPORT_H

#include <string>

using std::string;

/**
 * @brief
 */
class Report
{
   private:
      static long _numReports; ///< Number of instantiated Reports
      int _reportID; ///< Identifier for each report
      int _pilotID; ///< Identifier of the Pilot that makes the report
      long _stellarDate; ///< Report date in the format yyyymmdd
      string _reportData; ///< Report's content

   public:
      Report ( );
      Report( int pilotId, long date, string data );
      Report ( const Report& orig );
      virtual ~Report ( );
      void setReportData( string reportData );
      string getReportData( ) const;
      void setStellarDate( long stellarDate );
      long getStellarDate( ) const;
      void setPilotId( int pilotID );
      int getPilotID( ) const;
      int getIncidentID( ) const;
      string toCSV () const;
      Report& operator=( const Report &other );
};

#endif /* REPORT_H
 **/

