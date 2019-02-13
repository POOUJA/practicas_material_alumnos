/**
 * @brief
 * @file djutils.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 18:12
 */

#include <iostream>
#include "djutils.h"

void djutils::mostrarTemazo(const Temazo& temazo,std::string prefijo) {
    std::cout << prefijo << "TEMAZO: " << std::endl
              << prefijo << " - Título: " << temazo.getTitulo() << std::endl
              << prefijo << " - Intérprete: " << temazo.getInterprete() << std::endl
              << prefijo << " - Duración: " << temazo.getDuracion() << " segundos" << std::endl
              << prefijo << " - Puntuación: " << temazo.getPuntuacion() << " puntos" << std::endl;
}

void djutils::mostrarGarito(const Garito& garito,std::string prefijo) {
    std::cout << prefijo << "GARITO: " << std::endl
              << prefijo << " - Nombre: " << garito.getNombre() << std::endl
              << prefijo << " - Dirección: " << garito.getDireccion() << std::endl;
}

void djutils::mostrarFecha(const Fecha& fecha,std::string prefijo) {
    std::cout << prefijo << "FECHA: " << std::endl
              << prefijo << " - Día: " << fecha.getDia() << std::endl
              << prefijo << " - Mes: " << fecha.getMes() << std::endl
              << prefijo << " - Año: " << fecha.getAnio() << std::endl;

}

void djutils::pedirGarito(Garito& garito) {
    std::string tmp;
    std::cout << "INTRODUZCA LOS DATOS DEL GARITO: " << std::endl
              << " - Nombre del garito: ";
    getline(std::cin, tmp);
    garito.setNombre(tmp);
    std::cout << " - Dirección del garito: ";
    getline(std::cin, tmp);
    garito.setDireccion(tmp);
}