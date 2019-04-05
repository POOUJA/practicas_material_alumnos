/**
 * @file PoderFisico.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include "PoderFisico.h"

using std::string;

PoderFisico::PoderFisico ( string nmb, string dsc, string aA, float cD ):
             Poder ( nmb, dsc, aA, cD )
{ }

PoderFisico::PoderFisico ( const PoderFisico& orig ): Poder ( orig )
{ }

PoderFisico::~PoderFisico ( )
{ }

PoderFisico& PoderFisico::operator= ( const PoderFisico& orig )
{
   if ( this != &orig )
   {
       this->Poder::operator= ( orig );
   }

   return  *this;
}