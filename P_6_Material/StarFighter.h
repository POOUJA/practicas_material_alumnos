/** 
 * @file StarFighter.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
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
      int _idSF;
      string _marca;
      string _modelo;
      int _numPlazas;

   public:
      StarFighter ();
      StarFighter ( string marca, string modelo, int numPlazas=1 );
      StarFighter ( const StarFighter& orig );
      virtual ~StarFighter ( );
      void setNumPlazas ( int numPlazas );
      int getNumPlazas ( ) const;
      void setModelo ( string modelo );
      string getModelo ( ) const;
      void setMarca ( string marca );
      string getMarca ( ) const;
      int getIdSF ( ) const;
      string toCSV ();
      StarFighter& operator= ( const StarFighter& otro );
      void fromCSV ( string& datos );
};

#endif /* STARFIGHTER_H */

