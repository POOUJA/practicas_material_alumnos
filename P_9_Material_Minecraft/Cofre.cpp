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
    
    //Reservamos memoria para el vector de punteros a Item e inicializamos todas las posiciones a nullptr
    _items=new Item*[cuantosCaben]{};
}

/** Crea un Cofre vacío del mismo tamaño del original*/
Cofre::Cofre(const Cofre& orig) 
    :_maxItems(orig._maxItems)
    ,_numItems(orig._numItems) {

    //Todas las posiciones del nuevo cofre se inicializan a nullptr
    _items=new Item*[_maxItems]{};
}

Cofre::~Cofre() {
    delete [] _items;
    _numItems=0;
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

/** Devuelve una referencia al Item indicado del cofre

  @param cual nº orden del elemento a consultar
  @return Referencia al objeto indicado del cofre
  @throw std::out_of_range si el elemento no existe
*/
Item& Cofre::consulta(int cual) {
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}


/** Extrae el Item indicado del cofre

   @param cual nº orden del elemento a extraer
   @post extrae y devuelve el item indicado del cofre. El nº de orden de los items restantes pueden variar.
   @return devuelve el puntero al Item indicado
   @throw std::out_of_range si el elemento no exist
*/
Item* Cofre::saca(int cual) {
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::mete] El elemento indicado no existe");
    Item* elemento = _items[cual-1];
    _numItems--;
    if (_numItems>0) {
        //El último item pasa a ocupar la posición del item extraído
        _items[cual-1]=_items[_numItems];
        _items[_numItems]=nullptr;
    }
    return elemento;
}
