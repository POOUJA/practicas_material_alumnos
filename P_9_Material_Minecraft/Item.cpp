/** 
 * @file    Item.cpp
 * @author  jrbalsas
 * 
 * @date    April 15th, 2016
 */

#include "Item.h"

Item::Item( std::string description )
    :_decription(description){
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

void Item::setDescription( std::string description ) {
    this->_decription = description;
}

std::string Item::getDescription( ) const {
    return _decription;
}

