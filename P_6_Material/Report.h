/** 
 * @file Report.h
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
      static long _numReports;
      int _reportID;
      int _pilotID;
      long _stellarDate;
      string _reportData;

   public:
      Report ( );
      Report( int pilotID, long date, string data );
      Report ( const Report& orig );
      virtual ~Report ( );
      void setReportData( string reportData );
      string getReportData( ) const;
      void setStellarDate( long stellarDate );
      long getStellarDate( ) const;
      void setPilotID( int pilotID );
      int getPilotID( ) const;
      int getReportID( ) const;
      string toCSV ();
      Report& operator=( const Report &other );
};

#endif /* REPORT_H */

