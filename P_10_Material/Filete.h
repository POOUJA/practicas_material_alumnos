/** 
 * @file    Filete.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#ifndef FILETE_H
#define FILETE_H

#include "Item.h"

class Filete: public Item {
public:
    Filete() = default;
    Filete(const Filete& orig) = default;
    virtual ~Filete() = default;

    virtual std::string getDescripcion() const;

};

#endif /* FILETE_H */

