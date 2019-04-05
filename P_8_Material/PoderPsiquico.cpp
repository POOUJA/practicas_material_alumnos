/**
 * @file PoderPsiquico.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <sstream>

#include "PoderPsiquico.h"

using std::string;

PoderPsiquico::PoderPsiquico ( string nmb, string dsc, string aA, float cD ):
               Poder ( nmb, dsc, aA, cD )
{ }

PoderPsiquico::PoderPsiquico ( const PoderPsiquico& orig ):
               Poder(orig)
{ }

PoderPsiquico::~PoderPsiquico ( )
{ }

PoderPsiquico& PoderPsiquico::operator= ( const PoderPsiquico& orig )
{
   if ( this != &orig )
   {
      this->Poder::operator= ( orig );
   }

   return  *this;
}