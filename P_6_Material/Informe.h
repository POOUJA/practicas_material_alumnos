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
      static long _numInformes;
      int _idI;
      int _idPiloto;
      long _fechaEstelar;
      string _datosInforme;

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
      string toCSV ();
      Informe& operator= ( const Informe& otro );
};

#endif /* INFORME_H */

