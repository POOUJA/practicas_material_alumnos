/**
 * @file PhysicalPower.cpp
 * @author algarcia
 *
 * @date April 6th, 2016
 */

#include "PhysicalPower.h"

PhysicalPower::PhysicalPower( string name, string description, string affectsTo, float destructiveCapacity ) :
Power(name, description, affectsTo, destructiveCapacity) {
}

PhysicalPower::PhysicalPower(const PhysicalPower& orig) : Power(orig) {
}

PhysicalPower::~PhysicalPower() {
}

PhysicalPower& PhysicalPower::operator=(const PhysicalPower& orig) {
    if (this != &orig) {
        this->Power::operator=(orig);
    }

    return  *this;
}