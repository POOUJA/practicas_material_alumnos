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
      static int _numStarFighters; ///< Número de objetos de esta clase instanciados
      int _idSF; ///< Identificador único de la nave
      string _marca; ///< Marca de la nave (parece que las VW contaminan más)
      string _modelo; ///< Modelo de la nava
      int _numPlazas; ///< Número de plazas de la nave

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
      string toCSV () const;
      StarFighter& operator= ( const StarFighter& otro );
};

#endif /* STARFIGHTER_H */

