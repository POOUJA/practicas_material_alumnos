/** 
 * @file    Item.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Item.h"

Item::Item(std::string descripcion)
    :_descripcion(descripcion){
}

Item::~Item() {
}

void Item::setDescripcion(std::string descripcion) {
    this->_descripcion = descripcion;
}

std::string Item::getDescripcion() const {
    return _descripcion;
}

