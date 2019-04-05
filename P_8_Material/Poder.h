/**
 * @file Poder.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef PODER_H
#define PODER_H

#include <string>

/**
 * @brief
 */
class Poder
{
   private:
      std::string _nombre = "---";
      std::string _descripcion = "---";
      std::string _afectaA = "---";
      float _capacidadDestructiva = 0;

   public:
      Poder () = default;
      Poder ( std::string nmb, std::string dsc, std::string aA, float cD );
      Poder ( const Poder& orig );
      virtual ~Poder ( );
      void setNombre ( std::string nombre );
      std::string getNombre ( ) const;
      void setCapacidadDestructiva ( float capacidadDestructiva );
      float getCapacidadDestructiva ( ) const;
      void setAfectaA ( std::string afectaA );
      std::string getAfectaA ( ) const;
      void setDescripcion ( std::string descripcion );
      std::string getDescripcion ( ) const;

      std::string toCSV ( ) const;
      Poder& operator= ( const Poder& orig );
      
};

#endif /* PODER_H */

