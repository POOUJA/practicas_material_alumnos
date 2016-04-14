/**
 * @file PoderPsiquico.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef PODERPSIQUICO_H
#define PODERPSIQUICO_H

#include "Poder.h"

/**
 * @brief
 */
class PoderPsiquico: public Poder
{
   public:
      PoderPsiquico ( string nmb="---", string dsc="---", string aA="---",
                      float cD=0 );
      PoderPsiquico ( const PoderPsiquico& orig );
      virtual ~PoderPsiquico ( );
      PoderPsiquico& operator= ( const PoderPsiquico& orig );
};

#endif /* PODERPSIQUICO_H */

