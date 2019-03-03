/** 
 * @file Pieza.h
 * @author Yoyapro Gramo
 *
 * @date Fecha estelar 20160317
 */

#ifndef PIEZA_H
#define PIEZA_H

#include <string>


/**
 * @brief
 */
class Pieza
{
   private:
      std::string _nombre = "";
      float _peso = 0;
      std::string _descripcion = "";

   public:
      Pieza () = default;
      Pieza ( std::string nombre, float peso, std::string descripcion );
      Pieza ( const Pieza& orig );
      virtual ~Pieza ( );
      Pieza& setDescripcion ( std::string descripcion );
      std::string getDescripcion ( ) const;
      Pieza& setPeso ( float peso );
      float getPeso ( ) const;
      Pieza& setNombre ( std::string nombre );
      std::string getNombre ( ) const;
      Pieza& operator= ( const Pieza& orig );
};

#endif /* PIEZA_H */

