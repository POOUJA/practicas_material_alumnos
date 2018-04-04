/** 
 * @file    Chest.cpp
 * @author  jrbalsas
 * 
 * @date    April 15th, 2016
 */

#include "Chest.h"
#include <stdexcept>

Chest::Chest(int maxElements)
    :_maxItems(maxElements)
    ,_numItems(0) {
    
    _items=new Item*[maxElements];
    for (int i = 0; i < maxElements; i++) {
        _items[i]=0;
    }
}

/**Creates an empty Chest with the same size as the original*/
Chest::Chest(const Chest& orig)
    :_maxItems(orig._maxItems)
    ,_numItems(orig._numItems) {

    _items=new Item*[_maxItems];
    for (int i = 0; i < _maxItems; i++) {
        _items[i]=0;
    }
}

Chest::~Chest() {
    delete [] _items;
}

int Chest::howManyThereAre( ) const {
    return _numItems;
}

int Chest::howManyCanFit( ) {
    return _maxItems;
}

void Chest::put( Item *item ) {
    if (_numItems==_maxItems)
        throw std::out_of_range("[Chest::put] Chest can't take more elements");
    _items[_numItems++]=item;
}

/**@param which number of the element to see
 * @return Reference to the indicated object from the Chest
   @throw std::out_of_range if the element doesn't exist*/
Item& Chest::see( int which ) {
    if (which<=0 || which >_numItems)
        throw std::out_of_range("[Chest::see] The indicated element doesn't exist");
    return *_items[which-1];
}


/**@param which number of the element to extract
 * @return Extracts an element from the Chest and returns a pointer to the indica-
 *         ted element
   @throw std::out_of_range if the element doesn't exist*/
Item* Chest::extract( int which ) {
    if (which<=0 || which >_numItems)
        throw std::out_of_range("[Chest::put] The indicated element doesn't exist");
    Item* element = _items[which-1];
    _numItems--;
    if (_numItems>0)
        _items[which-1]=_items[_numItems];
    return element;
}
