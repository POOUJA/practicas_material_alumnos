/** 
 * @file Piloto.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef PILOTO_H
#define PILOTO_H

#include <string>
#include "StarFighter.h"
#include "Droide.h"
#include "Informe.h"


/**
 * @brief
 */
class Piloto
{
   private:
      static int _numPilotos;
      int _idP = 0;
      std::string _nombre;
      std::string _nacionalidad;
      int _numMisiones = 0;
      long _fechaUltimaMision = 0;
      std::string _incidenciasUltimaMision;
      StarFighter *_nave = nullptr;
      Droide *_auxiliar = nullptr;

   public:
      Piloto ( );
      Piloto ( std::string nombre, std::string nacionalidad, long fechaUM,
               std::string incidenciasUM, int numMisiones, StarFighter *nave,
               Droide *auxiliar );
      Piloto ( const Piloto& orig );
      virtual ~Piloto ( );
      void setNumMisiones ( int numMisiones );
      int getNumMisiones ( ) const;
      void setNacionalidad ( std::string nacionalidad );
      std::string getNacionalidad ( ) const;
      void setNombre ( std::string nombre );
      std::string getNombre ( ) const;
      int getIdP ( ) const;
      void setIncidenciasUltimaMision ( std::string incidenciasUltimaMision );
      std::string getIncidenciasUltimaMision ( ) const;
      void setFechaUltimaMision ( long fechaUltimaMision );
      long getFechaUltimaMision ( ) const;
      std::string toCSV ();
      Piloto& operator= ( const Piloto& otro );
      void setNave ( StarFighter* nave );
      StarFighter* getNave ( ) const;
      void setAuxiliar ( Droide* auxiliar );
      Droide* getAuxiliar ( ) const;
      Informe generaInforme ();
      void fromCSV ( std::string& datos );
};

#endif /* PILOTO_H */

