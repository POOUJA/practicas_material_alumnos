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
      static int _numStarFighters; ///< Number of objects instantiated by this class
      int _SFid; ///< Unique identifier of the Starship
      string _brand; ///< Starship's brand (seems that VW's polute more)
      string _model; ///< Starship's model
      int _numSeats; ///< Number of seat in the Starship

   public:
      StarFighter ();
      StarFighter( string brand, string model, int numSeats = 1 );
      StarFighter ( const StarFighter& orig );
      virtual ~StarFighter ( );
      void setNumSeats( int numSeats );
      int getNumSeats( ) const;
      void setModel( string model );
      string getModel( ) const;
      void setBrand( string brand );
      string getBrand( ) const;
      int getSFid( ) const;
      string toCSV () const;
      StarFighter& operator=( const StarFighter &other );
};

#endif /* STARFIGHTER_H */

