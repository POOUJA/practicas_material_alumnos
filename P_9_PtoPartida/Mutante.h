/**
 * @file Mutante.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef MUTANTE_H
#define MUTANTE_H

#include <string>
#include "Poder.h"

using std::string;

/**
 * @brief
 */
class Mutante
{
   public:
      static const int _MAX_DONES_ = 10;

   private:
      string _nombreReal;
      string _apodo;
      int _fechaDeNacimiento;
      string _nacionalidad;
      Poder* _dones[_MAX_DONES_];
      int _numDones;

   public:
      Mutante ( string nombre="---", string apodo="---", int fechaN=0,
                string nacionalidad="---" );
      Mutante ( const Mutante& orig );
      virtual ~Mutante ( );
      void setNombreReal ( string nombreReal );
      string getNombreReal ( ) const;
      void setNacionalidad ( string nacionalidad );
      string getNacionalidad ( ) const;
      void setFechaDeNacimiento ( int fechaDeNacimiento );
      int getFechaDeNacimiento ( ) const;
      void setApodo ( string apodo );
      string getApodo ( ) const;
      int getNumDones () const;
      const Poder* getDon ( int cual );
      void addPoder ( string nombre, string descripcion, string afectaA,
                      float capacidadD );
      void borraPoder ( int cual );
      void borraPoderes ();
      float capacidadDestructivaTotal ();
      string toCSV ();
      Mutante& operator= ( const Mutante& orig );
      void addPoderFisico ( string nombre, string descripcion, string afectaA,
                            float capacidadD );
      void addPoderPsiquico ( string nombre, string descripcion, string afectaA,
                              float capacidadD );
};

#endif /* MUTANTE_H */

