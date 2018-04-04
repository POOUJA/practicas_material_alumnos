/**
 * @file PsychicPower.h
 * @author algarcia
 *
 * @date April 6th, 2016, 19:52
 */

#ifndef PSYCHICPOWER_H
#define PSYCHICPOWER_H

#include "Power.h"

/**
 * @brief
 */
class PsychicPower : public Power {
public:
    PsychicPower( string name = "---", string description = "---", string affectsTo = "---",
                  float destructiveCapacity = 0 );
    PsychicPower(const PsychicPower& orig);
    virtual ~PsychicPower();
    PsychicPower& operator=(const PsychicPower& orig);

    //ToDo, redefine toCSV and getDestructiveCapacity

    private:
        //ToDo, add lucidity
};

#endif /* PSYCHICPOWER_H */

