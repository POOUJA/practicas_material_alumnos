/**
 * @file EquipoMutante.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef EQUIPOMUTANTE_H
#define EQUIPOMUTANTE_H

#include <string>

#include "Mutante.h"

/**
 * @brief
 */
class EquipoMutante
{
   public:
      static const int _MAX_MIEMBROS_ = 10;

    private:
      std::string _nombre = "---";
      std::string _base = "---";
      Mutante* _miembros[_MAX_MIEMBROS_];
      int _numMiembros = 0;

   public:
      EquipoMutante ( );
      EquipoMutante ( std::string nombre, std::string base );
      EquipoMutante ( const EquipoMutante& orig );
      virtual ~EquipoMutante ( );
      void setNombre ( std::string nombre );
      std::string getNombre ( ) const;
      void setBase ( std::string base );
      std::string getBase ( ) const;

      std::string toCSV ( );
      EquipoMutante& operator= ( const EquipoMutante& orig );

      void addMutante ( Mutante *m );
      int getNumMiembros ( ) const;
      Mutante* getMutante ( int cual );
      Mutante* sacaMutante ( int cual );
};

#endif /* EQUIPOMUTANTE_H */