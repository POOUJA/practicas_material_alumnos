/** 
 * @file StarFighter.h
 * @author Casipro Gramo
 *
 * @date Stellar date 20160309
 */

#ifndef STARFIGHTER_H
#define STARFIGHTER_H

#include <string>

using std::string;

/**
 * @brief
 */
class StarFighter
{
   private:
      static int _numStarFighters;
      int _starFighterID;
      string _brand;
      string _model;
      int _seatsNumber;

   public:
      StarFighter ();
      StarFighter( string brand, string model, int seatsNumber = 1 );
      StarFighter ( const StarFighter& orig );
      virtual ~StarFighter ( );
      void setSeatsNumber( int seatsNumber );
      int getSeatsNumber( ) const;
      void setModel( string model );
      string getModel( ) const;
      void setBrand( string brand );
      string getBrand( ) const;
      int getStarFighterID( ) const;
      string toCSV ();
      StarFighter& operator=( const StarFighter &other );
      void fromCSV( string &data );
};

#endif /* STARFIGHTER_H */

