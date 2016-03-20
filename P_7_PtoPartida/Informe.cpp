/** 
 * @file Informe.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Informe.h"

long Informe::_numInformes = 0;

Informe::Informe ( ): _idPiloto(0), _fechaEstelar(0), _datosInforme("")
{
   _numInformes++;
   _idI = _numInformes;
}

Informe::Informe ( int idPiloto, long fecha, string datos ): _idI(idPiloto),
                                                             _fechaEstelar(fecha),
                                                             _datosInforme(datos)
{
   if ( idPiloto < 0 )
   {
      throw std::invalid_argument ( "Informe::Informe: el identificador del"
                                    " piloto no puede ser negativo" );
   }

   if ( fecha < 0 )
   {
      throw std::invalid_argument ( "Informe::Informe: la fecha no puede ser"
                                    " negativa" );
   }

   _numInformes++;
   _idI = _numInformes;
}

Informe::Informe ( const Informe& orig ): _idPiloto(orig._idPiloto),
                                          _fechaEstelar(orig._fechaEstelar),
                                          _datosInforme(orig._datosInforme)
{
   _numInformes++;
   _idI = _numInformes;
}

Informe::~Informe ( )
{
}

void Informe::setDatosInforme ( string datosInforme )
{
   this->_datosInforme = datosInforme;
}

string Informe::getDatosInforme ( ) const
{
   return _datosInforme;
}

/**
 * @todo Comprobar el valor, y si es negativo, lanzar excepción
 */
void Informe::setFechaEstelar ( long fechaEstelar )
{
   this->_fechaEstelar = fechaEstelar;
}

long Informe::getFechaEstelar ( ) const
{
   return _fechaEstelar;
}

/**
 * @todo Comprobar el valor, y si es negativo, lanzar excepción
 */
void Informe::setIdPiloto ( int idPiloto )
{
   this->_idPiloto = idPiloto;
}

int Informe::getIdPiloto ( ) const
{
   return _idPiloto;
}

int Informe::getIdI ( ) const
{
   return _idI;
}

string Informe::toCSV ()
{
   std::stringstream aux;

   aux << "Fecha estelar: " << _fechaEstelar << " ; "
       << "Piloto: " << _idPiloto << " ; "
       << _datosInforme;

   return ( aux.str () );
}

Informe& Informe::operator = ( const Informe& otro )
{
   if ( this != &otro )
   {
      _idPiloto = otro._idPiloto;
      _fechaEstelar = otro._fechaEstelar;
      _datosInforme = otro._datosInforme;
   }
   
   return ( *this );
}