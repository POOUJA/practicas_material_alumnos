/** 
 * @file Droid.h
 * @author Casipro Gramo
 *
 * @date Stellar date 20160309
 */

#ifndef DROID_H
#define DROID_H

#include <string>

using std::string;

/**
 * @brief
 */
class Droid
{
   private:
      static int _numDroids;
      int _droidID;
      string _brand;
      string _model;

   public:
      Droid ( );
      Droid( string brand, string model );
      Droid ( const Droid& orig );
      virtual ~Droid ( );
      int getDroidID( ) const;
      void setModel( string model );
      string getModel( ) const;
      void setBrand( string brand );
      string getBrand( ) const;
      string toCSV ();
      Droid& operator=( const Droid &other );
      void fromCSV( string &data );
};

#endif /* DROID_H */

