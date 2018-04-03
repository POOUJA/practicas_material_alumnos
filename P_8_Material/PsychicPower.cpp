/**
 * @file PoderPsiquico.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include "PsychicPower.h"

#include <sstream>

PsychicPower::PsychicPower( string name, string description, string affectsTo, float destructiveCapacity )
    :Power(name, description, affectsTo, destructiveCapacity)
{
}

PsychicPower::PsychicPower(const PsychicPower& orig)
    : Power(orig)
{
}

PsychicPower::~PsychicPower() {
}

PsychicPower& PsychicPower::operator=(const PsychicPower& orig) {
    if (this != &orig) {
        this->Power::operator=(orig);
    }

    return  *this;
}




