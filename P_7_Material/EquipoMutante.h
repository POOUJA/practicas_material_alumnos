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

using std::string;

/**
 * @brief
 */
class EquipoMutante
{
   public:
      static const int _MAX_MIEMBROS_ = 10;

   public:
      EquipoMutante();
      EquipoMutante ( string nombre, string base );
      EquipoMutante ( const EquipoMutante& orig );
      virtual ~EquipoMutante ( );
      void setNombre ( string nombre );
      string getNombre ( ) const;
      void setBase ( string base );
      string getBase ( ) const;

      string toCSV ();
      EquipoMutante& operator= ( const EquipoMutante& orig );

      void addMutante ( Mutante *m );
      int getNumMiembros ( ) const;
      Mutante* getMutante ( int cual );
      Mutante* sacaMutante(int cual);

    private:
      string _nombre = "---";
      string _base = "---";
      Mutante* _miembros[_MAX_MIEMBROS_];
      int _numMiembros = 0;
          
};

#endif /* EQUIPOMUTANTE_H */

