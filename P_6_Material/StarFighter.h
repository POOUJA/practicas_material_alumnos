/** 
 * @file StarFighter.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef STARFIGHTER_H
#define STARFIGHTER_H

#include <string>

/**
 * @brief
 */
class StarFighter
{
   private:
      static int _numStarFighters;
      int _idSF=0;
      std::string _marca;
      std::string _modelo;
      int _numPlazas = 1;

   public:
      StarFighter ();
      StarFighter ( std::string marca, std::string modelo, int numPlazas );
      StarFighter ( const StarFighter& orig );
      virtual ~StarFighter ( );
      void setNumPlazas ( int numPlazas );
      int getNumPlazas ( ) const;
      void setModelo ( std::string modelo );
      std::string getModelo ( ) const;
      void setMarca ( std::string marca );
      std::string getMarca ( ) const;
      int getIdSF ( ) const;
      std::string toCSV ();
      StarFighter& operator= ( const StarFighter& otro );
      void fromCSV ( std::string& datos );
};

#endif /* STARFIGHTER_H */

