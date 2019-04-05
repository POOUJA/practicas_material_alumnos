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
#include "PoderFisico.h"
#include "PoderPsiquico.h"

/**
 * @brief Clase Muntante
 */
class Mutante
{
   public:
      static const int MAX_PODERES = 10; ///< Max. moderes de un mutante

   private:
      std::string _nombreReal = "---";
      std::string _apodo = "---";
      int _fechaDeNacimiento = 0;
      std::string _nacionalidad = "---";
      Poder* _poderes[MAX_PODERES];
      int _numPoderes = 0;

   public:
      Mutante ( );
      Mutante ( std::string nombre, std::string apodo, int fechaN,
                std::string nacionalidad );
      Mutante ( const Mutante& orig );
      virtual ~Mutante ( );
      void setNombreReal ( std::string nombreReal );
      std::string getNombreReal ( ) const;
      void setNacionalidad ( std::string nacionalidad );
      std::string getNacionalidad ( ) const;
      void setFechaDeNacimiento ( int fechaDeNacimiento );
      int getFechaDeNacimiento ( ) const;
      void setApodo ( std::string apodo );
      std::string getApodo ( ) const;

      std::string toCSV ( ) const;
      void fromCSV ( std::string &cadena );

      Mutante& operator= ( const Mutante& orig );

      // ToDo, operador de comparación '<' de dos mutantes en base a su
      // capacidad destructiva

      void addPoder ( std::string nombre, std::string descripcion,
                      std::string afectaA, float capacidadD );
      void addPoderFisico ( std::string nombre, std::string descripcion,
                             std::string afectaA, float capacidadD );
      void addPoderPsiquico ( std::string nombre, std::string descripcion,
                              std::string afectaA, float capacidadD );
      void addPoder ( const Poder& poder );
      void addPoder ( const PoderFisico& poder );
      void addPoder ( const PoderPsiquico& poder );
      int getNumPoderes ( ) const;
      const Poder& getPoder ( int cual );
      void borraPoder ( int cual );
      void borraPoderes ( );
      float capacidadDestructivaTotal ( ) const;
};

#endif /* MUTANTE_H */