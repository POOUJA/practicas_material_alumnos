/** 
 * @file Droide.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef DROIDE_H
#define DROIDE_H

#include <string>


/**
 * @brief
 */
class Droide
{
   private:
      static int _numDroides;
      int _idD = 0;
      std::string _marca;
      std::string _modelo;

   public:
      Droide ( );
      Droide ( std::string marca, std::string modelo );
      Droide ( const Droide& orig );
      virtual ~Droide ( );
      int getIdD ( ) const;
      void setModelo ( std::string modelo );
      std::string getModelo ( ) const;
      void setMarca ( std::string marca );
      std::string getMarca ( ) const;
      std::string toCSV ();
      Droide& operator= ( const Droide& otro );
      void fromCSV ( std::string& datos );
};

#endif /* DROIDE_H */

