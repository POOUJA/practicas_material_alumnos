/** 
 * @file    Chest.h
 * @author  jrbalsas
 * 
 * @date    April 15th, 2016
 */

#include "Item.h"
#include <string>

#ifndef CHEST_H
#define CHEST_H

class Chest {
public:
    Chest(int maxElements=27);
    Chest(const Chest& orig);
    virtual ~Chest();
    int howManyCanFit( );
    int howManyThereAre( ) const;
    void put( Item *item );
    Item& see( int which );
    Item* extract( int which );
private:
    int _maxItems; ///< size of the vector of pointers
    Item* *_items; ///< Vector of pointers created dynamically
    int _numItems; ///< First positions occupied in the vector (max is maxItems)
};

#endif /* CHEST_H */

