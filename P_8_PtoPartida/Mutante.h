/**
 * @file Mutante.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef MUTANTE_H
#define MUTANTE_H

#include <string>

using std::string;

/**
 * @brief
 */
class Mutante
{
   private:
      string _nombreReal;
      string _apodo;
      int _fechaDeNacimiento;
      string _nacionalidad;

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
      string toCSV ();
      Mutante& operator= ( const Mutante& orig );
};

#endif /* MUTANTE_H */

