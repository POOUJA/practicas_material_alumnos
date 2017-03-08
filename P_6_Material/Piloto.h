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

using std::string;

/**
 * @brief
 */
class Piloto
{
   private:
      static int _numPilotos;
      int _idP;
      string _nombre;
      string _nacionalidad;
      int _numMisiones;
      long _fechaUltimaMision;
      string _incidenciasUltimaMision;
      StarFighter *_nave;
      Droide *_auxiliar;

   public:
      Piloto ( );
      Piloto ( string nombre, string nacionalidad="", long fechaUM=0,
               string incidenciasUM="", int numMisiones=0, StarFighter *nave=0,
               Droide *auxiliar = 0 );
      Piloto ( const Piloto& orig );
      virtual ~Piloto ( );
      void setNumMisiones ( int numMisiones );
      int getNumMisiones ( ) const;
      void setNacionalidad ( string nacionalidad );
      string getNacionalidad ( ) const;
      void setNombre ( string nombre );
      string getNombre ( ) const;
      int getIdP ( ) const;
      void setIncidenciasUltimaMision ( string incidenciasUltimaMision );
      string getIncidenciasUltimaMision ( ) const;
      void setFechaUltimaMision ( long fechaUltimaMision );
      long getFechaUltimaMision ( ) const;
      string toCSV ();
      Piloto& operator= ( const Piloto& otro );
      void setNave ( StarFighter* nave );
      StarFighter* getNave ( ) const;
      void setAuxiliar ( Droide* auxiliar );
      Droide* getAuxiliar ( ) const;
      Informe generaInforme ();
      void fromCSV ( string& datos );
};

#endif /* PILOTO_H */

