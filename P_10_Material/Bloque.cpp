/** 
 * @file    Bloque.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Bloque.h"

#include <sstream>

Bloque::Bloque()
    :Bloque(1){
}

Bloque::Bloque(unsigned int cuantos)
    :ItemApilable(cuantos){
}

Bloque::Bloque(const Bloque& orig)
    :ItemApilable(orig){
}

Bloque::~Bloque() {
}

std::string Bloque::getDescripcion() const {
    std::stringstream ss;
    
    ss << "Bloque de tierra (" 
       << getNumElementos() << ") ";
       
    
    return ss.str();
}
