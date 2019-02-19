/**
 * @file Garito.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @desc Clase Garito para las prácticas de POO
 * @date 12 de octubre de 2015, 17:08
 */


#ifndef GARITO_H
#define	GARITO_H

#include <string>
/**
 * @brief Clase para almacenar los datos de un local en el que actúa el DJ
 */
class Garito {
public:
    Garito() = default;
    Garito(std::string nombre, std::string direccion);
    Garito(const Garito& orig);
    virtual ~Garito();
    void setDireccion(std::string direccion);
    std::string getDireccion() const;
    void setNombre(std::string nombre);
    std::string getNombre() const;
private:
    std::string _nombre = "Sin nombre"; ///< Nombre del local
    std::string _direccion = "Desconocida"; ///< Dirección del local
};

#endif	/* GARITO_H */

