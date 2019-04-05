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
    Item() = default;
    Item(std::string descripcion);
    Item(const Item& orig) = default;
    virtual ~Item();
    void setDescripcion(std::string descripcion);
    std::string getDescripcion() const;
private:
    std::string _descripcion = "Desconocido";
};

#endif /* ITEM_H */

