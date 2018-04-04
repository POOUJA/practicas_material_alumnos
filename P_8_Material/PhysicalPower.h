/**
 * @file PhysicalPower.h
 * @author algarcia
 *
 * @date April 6th, 2016, 19:52
 */

#ifndef PHYSICALPOWER_H
#define PHYSICALPOWER_H

#include "Power.h"

/**
 * @brief
 */
class PhysicalPower: public Power
{
   public:
      PhysicalPower( string name = "---", string description = "---", string affectsTo = "---",
                     float destructiveCapacity = 0 );
      PhysicalPower ( const PhysicalPower& orig );
      virtual ~PhysicalPower ( );
      PhysicalPower& operator= ( const PhysicalPower& orig );
};

#endif /* PHYSICALPOWER_H */

