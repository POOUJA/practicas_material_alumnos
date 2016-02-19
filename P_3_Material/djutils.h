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
    void mostrarTemazo( const Temazo& temazo );
    void mostrarGarito( const Garito& garito );
    void mostrarFecha( const Fecha& fecha );
    void pedirGarito( Garito& garito);    
}


#endif	/* DJUTILS_H */

