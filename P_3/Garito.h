/* 
 * File:   Garito.h
 * Author: Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * Created on 12 de octubre de 2015, 17:51
 */

#include <string>

#ifndef GARITO_H
#define	GARITO_H

class Garito {
public:
    Garito(std::string nombre="", std::string direccion="");
    Garito(const Garito& orig);
    virtual ~Garito();
    void setDireccion(std::string direccion);
    std::string getDireccion() const;
    void setNombre(std::string nombre);
    std::string getNombre() const;
private:
    std::string nombre;
    std::string direccion;
};

#endif	/* GARITO_H */

