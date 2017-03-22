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
      static int _numDroides;
      int _idD;
      string _marca;
      string _modelo;

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
      string toCSV ();
      Droide& operator= ( const Droide& otro );
      void fromCSV ( string& datos );
};

#endif /* DROIDE_H */

