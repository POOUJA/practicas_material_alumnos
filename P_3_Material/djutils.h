/**
 * @brief
 * @file djutils.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 18:09
 */

#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"

#ifndef DJUTILS_H
#define	DJUTILS_H

namespace djutils {
    void mostrarTemazo( const Temazo& temazo, std::string prefijo="" );
    void mostrarGarito( const Garito& garito, std::string prefijo="" );
    void mostrarFecha( const Fecha& fecha, std::string prefijo="" );
    void pedirGarito( Garito& garito);
}


#endif	/* DJUTILS_H */

