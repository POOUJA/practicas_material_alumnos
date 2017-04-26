/** 
 * @file    Item.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include <string>

#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    Item(std::string descripcion="Desconocido");
    Item(const Item& orig);
    virtual ~Item();
    void setDescripcion(std::string descripcion);
    std::string getDescripcion() const;
private:
    std::string _descripcion;
};

#endif /* ITEM_H */

