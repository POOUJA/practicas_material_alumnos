/** 
 * @file    Bloque.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#ifndef BLOQUE_H
#define BLOQUE_H

#include "ItemApilable.h"

/**@Brief Clase base para bloques de construcción*/
class Bloque: public ItemApilable {
public:
    Bloque();
    Bloque(unsigned int cuantos);
    Bloque(const Bloque& orig);
    virtual ~Bloque() = default;
    
    virtual std::string getDescripcion() const;
private:
    

};

#endif /* BLOQUE_H */

