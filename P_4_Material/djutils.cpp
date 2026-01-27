/**
 * @brief
 * @file djutils.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 18:12
 */

#include <iostream>
#include "djutils.h"

void djutils::mostrarTemazo(const Temazo& temazo,std::string prefijo) {
    std::cout << prefijo << "TEMAZO: " << std::endl;
    std::cout << prefijo << " - T�tulo: " << temazo.getTitulo() << std::endl;
    std::cout << prefijo << " - Int�rprete: " << temazo.getInterprete() << std::endl;
    std::cout << prefijo << " - Duraci�n: " << temazo.getDuracion() << " segundos" << std::endl;
    std::cout << prefijo << " - Puntuaci�n: " << temazo.getPuntuacion() << " puntos" << std::endl;
    std::cout << prefijo << " - �ltimo garito: " << temazo.getNombreUltimoGarito () << std::endl;
    std::cout << prefijo << " - Fecha de la �ltima reproducci�n:" << std::endl;
    djutils::mostrarFecha (temazo.getFechaUltimoUso (), "      " );
}

void djutils::mostrarGarito(const Garito& garito,std::string prefijo) {
    std::cout << prefijo << "GARITO: " << std::endl;
    std::cout << prefijo << " - Nombre: " << garito.getNombre() << std::endl;
    std::cout << prefijo << " - Direcci�n: " << garito.getDireccion() << std::endl;
}

void djutils::mostrarFecha(const Fecha& fecha,std::string prefijo) {
    std::cout << prefijo << "FECHA: " << std::endl;
    std::cout << prefijo << " - D�a: " << fecha.getDia() << std::endl;
    std::cout << prefijo << " - Mes: " << fecha.getMes() << std::endl;
    std::cout << prefijo << " - A�o: " << fecha.getAnio() << std::endl;

}
