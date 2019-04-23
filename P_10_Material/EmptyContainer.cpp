/** 
 * @file    EmptyContainer.cpp
 * @author  jrbalsas
 * 
 * @date    16 de abril de 2016
 */

#include <string>

#include "EmptyContainer.h"

EmptyContainer::EmptyContainer(std::string error)
    :std::domain_error(error){
}

EmptyContainer::EmptyContainer(const EmptyContainer& orig)
    :std::domain_error(orig) {
}

EmptyContainer::~EmptyContainer() noexcept {
}

