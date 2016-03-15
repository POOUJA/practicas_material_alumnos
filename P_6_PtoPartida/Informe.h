/** 
 * @file Informe.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef INFORME_H
#define INFORME_H

#include <string>

using std::string;

/**
 * @brief
 */
class Informe
{
   private:
      static long _numInformes; ///< Número de informes instanciados
      int _idI; ///< Identificador de cada informe
      int _idPiloto; ///< Identificador del piloto que realiza el informe
      long _fechaEstelar; ///< Fecha del informe en formato aaaammdd
      string _datosInforme; ///< Contenido del informe

   public:
      Informe ( );
      Informe ( int idPiloto, long fecha, string datos );
      Informe ( const Informe& orig );
      virtual ~Informe ( );
      void setDatosInforme ( string datosInforme );
      string getDatosInforme ( ) const;
      void setFechaEstelar ( long fechaEstelar );
      long getFechaEstelar ( ) const;
      void setIdPiloto ( int idPiloto );
      int getIdPiloto ( ) const;
      int getIdI ( ) const;
      string toCSV () const;
      Informe& operator= ( const Informe& otro );
};

#endif /* INFORME_H */

