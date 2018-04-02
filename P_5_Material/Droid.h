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
      static int _numDroids; ///< Number of instatiated Droids
      int _droidID; ///< Identifier of the Droid
      string _brand; ///< Droid's brand
      string _model; ///< Droid's model

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
      string toCSV () const;
      Droid& operator=( const Droid &other );
};

#endif /* DROID_H */

