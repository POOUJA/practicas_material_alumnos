/** 
 * @file    Item.h
 * @author  jrbalsas
 * 
 * @date    April 6th, 2016
 */

#include <string>

#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    Item( std::string description = "Unknown" );
    Item(const Item& orig);
    virtual ~Item();
    void setDescription( std::string description );
    std::string getDescription( ) const;
private:
    std::string _decription;
};

#endif /* ITEM_H */

