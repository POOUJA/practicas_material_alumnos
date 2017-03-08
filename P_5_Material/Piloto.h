/** 
 * @file Piloto.h
 * @author Yoyapro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef PILOTO_H
#define PILOTO_H

#include <string>

using std::string;

/**
 * @brief
 */
class Piloto
{
   private:
      static int _numPilotos; ///< Número de objetos Piloto que han sido instanciados
      int _idP; ///< Identificador único del Piloto
      string _nombre; ///< Nombre del Piloto
      string _nacionalidad; ///< Nacionalidad del Piloto
      int _numMisiones; ///< Número de misiones en que ha participado
      long _fechaUltimaMision; ///< Fecha estelar de su última misión
      string _incidenciasUltimaMision; ///< Incidencias reportadas por el piloto en su última misión.

   public:
      Piloto ( );
      Piloto ( string nombre, string nacionalidad="", long fechaUM=0,
               string incidenciasUM="", int numMisiones=0 );
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
      string toCSV () const;
      Piloto& operator= ( const Piloto& otro );
};

#endif /* PILOTO_H */

