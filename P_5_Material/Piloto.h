/** 
 * @file Piloto.h
 * @author Yoyapro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef PILOTO_H
#define PILOTO_H

#include <string>

/**
 * @brief
 */
class Piloto
{
   private:
      static int _numPilotos; ///< Número de objetos Piloto que han sido instanciados
      int _idP = 0;                       ///< Identificador único del Piloto
      std::string _nombre;                ///< Nombre del Piloto
      std::string _nacionalidad;          ///< Nacionalidad del Piloto
      int _numMisiones = 0;        ///< Número de misiones en que ha participado
      long _fechaUltimaMision = 0;        ///< Fecha estelar de su última misión
      std::string _incidenciasUltimaMision; ///< Incidencias reportadas por el piloto en su última misión.

   public:
      Piloto ( );
      Piloto ( std::string nombre );
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
      std::string toCSV () const;
      Piloto& operator= ( const Piloto& otro );
};

#endif /* PILOTO_H */

