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
class PoderPsiquico : public Poder
{
   public:
      PoderPsiquico ( ) = default;
      PoderPsiquico ( std::string nmb, std::string dsc, std::string aA, float cD );
      PoderPsiquico ( const PoderPsiquico& orig );
      virtual ~PoderPsiquico ( );
      PoderPsiquico& operator= ( const PoderPsiquico& orig );

      //ToDo, redefinir toCSV y getCapacidadDestructiva

   private:
      //ToDo, añadir lucidez
};

#endif /* PODERPSIQUICO_H */

