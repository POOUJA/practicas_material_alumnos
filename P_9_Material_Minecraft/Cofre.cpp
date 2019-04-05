/** 
 * @file    Cofre.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Cofre.h"
#include <stdexcept>

Cofre::Cofre (): Cofre(27) {
    
}
Cofre::Cofre(int cuantosCaben)
    :_maxItems(cuantosCaben)
    ,_numItems(0) {
    
    _items=new Item*[cuantosCaben];
    for (int i = 0; i < cuantosCaben; i++) {
        _items[i]=nullptr;
    }
}

/**Crea un Cofre vacío del mismo tamaño del original*/
Cofre::Cofre(const Cofre& orig) 
    :_maxItems(orig._maxItems)
    ,_numItems(orig._numItems) {

    _items=new Item*[_maxItems];
    for (int i = 0; i < _maxItems; i++) {
        _items[i]=nullptr;
    }
}

Cofre::~Cofre() {
    delete [] _items;
}

int Cofre::cuantosHay() const {
    return _numItems;
}

int Cofre::cuantosCaben() {
    return _maxItems;
}

void Cofre::mete(Item* item) {
    if (_numItems==_maxItems)
        throw std::out_of_range("[Cofre::mete] No caben más elementos en el cofre");
    _items[_numItems++]=item;
}

/**@param cual nº orden del elemento a consultar
 * @return Referencia al objeto indicado del cofre
   @throw std::out_of_range si el elemento no existe*/
Item& Cofre::consulta(int cual) {
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}


/**@param cual nº orden del elemento a extraer
 * @return Extrae del cofre y devuelve el puntero al Item indicado
   @throw std::out_of_range si el elemento no exist*/
Item* Cofre::saca(int cual) {
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::mete] El elemento indicado no existe");
    Item* elemento = _items[cual-1];
    _numItems--;
    if (_numItems>0)
        _items[cual-1]=_items[_numItems];
    return elemento;
}
