/** 
 * @file    Cofre.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Item.h"
#include <string>

#ifndef COFRE_H
#define COFRE_H

class Cofre {
public:
    Cofre(int cuantosCaben=27);
    Cofre(const Cofre& orig);
    virtual ~Cofre();
    int cuantosCaben();
    int cuantosHay() const;
    void mete(Item *item);
    Item& consulta(int cual);
    Item* saca(int cual);
private:
    int _maxItems; ///< Tamaño del vector de punteros
    Item* *_items; ///< Vector de punteros creado dinámicamente
    int _numItems; ///< Primeras posiciones del vector ocupadas (máximo maxItems)
};

#endif /* COFRE_H */

