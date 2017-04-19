/**
 * @file Poder.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef PODER_H
#define PODER_H

#include <string>

using std::string;

/**
 * @brief
 */
class Poder
{
   private:
      string _nombre;
      string _descripcion;
      string _afectaA;
      float _capacidadDestructiva;

   public:
      Poder ( string nmb="---", string dsc="---", string aA="---", float cD=0 );
      Poder ( const Poder& orig );
      virtual ~Poder ( );
      void setNombre ( string nombre );
      string getNombre ( ) const;
      void setCapacidadDestructiva ( float capacidadDestructiva );
      float getCapacidadDestructiva ( ) const;
      void setAfectaA ( string afectaA );
      string getAfectaA ( ) const;
      void setDescripcion ( string descripcion );
      string getDescripcion ( ) const;

       string toCSV () const;
      Poder& operator= ( const Poder& orig );
      
};

#endif /* PODER_H */

