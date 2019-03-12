/** 
 * @file Informe.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef INFORME_H
#define INFORME_H

#include <string>


/**
 * @brief
 */
class Informe
{
   private:
      static long _numInformes;  ///< Número de informes instanciados
      int _idI = 0;              ///< Identificador de cada informe
      int _idPiloto = 0;    ///< Identificador del piloto que realiza el informe
      long _fechaEstelar = 0;    ///< Fecha del informe en formato aaaammdd
      std::string _datosInforme; ///< Contenido del informe

   public:
      Informe ( );
      Informe ( long fecha );
      Informe ( const Informe& orig );
      virtual ~Informe ( );
      Informe& setDatosInforme ( std::string datosInforme );
      std::string getDatosInforme ( ) const;
      Informe& setFechaEstelar ( long fechaEstelar );
      long getFechaEstelar ( ) const;
      Informe& setIdPiloto ( int idPiloto );
      int getIdPiloto ( ) const;
      int getIdI ( ) const;
      std::string toCSV () const;
      Informe& operator= ( const Informe& otro );
};

#endif /* INFORME_H */

