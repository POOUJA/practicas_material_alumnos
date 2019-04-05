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
    Cofre();
    Cofre(int cuantosCaben);
    Cofre(const Cofre& orig);
    virtual ~Cofre();
    int cuantosCaben();
    int cuantosHay() const;
    void mete(Item *item);
    Item& consulta(int cual);
    Item* saca(int cual);
private:
    int _maxItems = 27; ///< Tamaño del vector de punteros
    Item* *_items = nullptr; ///< Vector de punteros creado dinámicamente
    int _numItems = 0; ///< Primeras posiciones del vector ocupadas (máximo maxItems)
};

#endif /* COFRE_H */

