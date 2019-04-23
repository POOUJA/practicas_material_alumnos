/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file    Espada.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#ifndef ESPADA_H
#define ESPADA_H
#include "Item.h"

class Espada: public Item {
public:
    Espada() = default;
    Espada(const Espada& orig);
    virtual ~Espada();

    virtual std::string getDescripcion() const;

private:
};

#endif /* ESPADA_H */

