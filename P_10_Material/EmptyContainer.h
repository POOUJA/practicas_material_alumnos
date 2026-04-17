/** 
 * @file    EmptyContainer.h
 * @author  jrbalsas
 * 
 * @date    16 de abril de 2016
 */

#ifndef EMPTYCONTAINER_H
#define EMPTYCONTAINER_H

#include <stdexcept>

/** @brief Excepción para indicar intentos de extracción sobre un contenedor  vacío*/
class EmptyContainer: public std::domain_error {
public:
    EmptyContainer(std::string error):std::domain_error(error) { };
    EmptyContainer(const EmptyContainer& orig) = default;
    virtual ~EmptyContainer() noexcept = default;

};

#endif /* EMPTYCONTAINER_H */

