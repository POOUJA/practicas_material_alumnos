/** 
 * @file Pieza.h
 * @author Yoyapro Gramo
 *
 * @date Fecha estelar 20160317
 */

#ifndef PIEZA_H
#define PIEZA_H

#include <string>

using std::string;

/**
 * @brief
 */
class Pieza
{
   private:
      string _nombre;
      float _peso;
      string _descripcion;

   public:
      Pieza ( string nombre="", float peso=0, string descripcion="" );
      Pieza ( const Pieza& orig );
      virtual ~Pieza ( );
      void setDescripcion ( string descripcion );
      string getDescripcion ( ) const;
      void setPeso ( float peso );
      float getPeso ( ) const;
      void setNombre ( string nombre );
      string getNombre ( ) const;
      Pieza& operator= ( const Pieza& orig );
};

#endif /* PIEZA_H */

