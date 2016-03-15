/** 
 * @file Droide.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef DROIDE_H
#define DROIDE_H

#include <string>

using std::string;

/**
 * @brief
 */
class Droide
{
   private:
      static int _numDroides; ///< Número de droides instanciados
      int _idD; ///< Identificador del droide
      string _marca; ///< Marca del droide
      string _modelo; ///< Modelo de droide

   public:
      Droide ( );
      Droide ( string marca, string modelo );
      Droide ( const Droide& orig );
      virtual ~Droide ( );
      int getIdD ( ) const;
      void setModelo ( string modelo );
      string getModelo ( ) const;
      void setMarca ( string marca );
      string getMarca ( ) const;
      string toCSV () const;
      Droide& operator= ( const Droide& otro );
};

#endif /* DROIDE_H */

