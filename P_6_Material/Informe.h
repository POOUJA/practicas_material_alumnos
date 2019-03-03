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
      static long _numInformes;
      int _idI = 0;
      int _idPiloto = 0;
      long _fechaEstelar = 0;
      std::string _datosInforme;

   public:
      Informe ( );
      Informe ( int idPiloto, long fecha, std::string datos );
      Informe ( const Informe& orig );
      virtual ~Informe ( );
      void setDatosInforme ( std::string datosInforme );
      std::string getDatosInforme ( ) const;
      void setFechaEstelar ( long fechaEstelar );
      long getFechaEstelar ( ) const;
      void setIdPiloto ( int idPiloto );
      int getIdPiloto ( ) const;
      int getIdI ( ) const;
      std::string toCSV ();
      Informe& operator= ( const Informe& otro );
};

#endif /* INFORME_H */

