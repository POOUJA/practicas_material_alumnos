/** 
 * @brief
 * @file djutils.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 18:12
 */

#include <iostream>
#include "djutils.h"


void djutils::mostrarTemazo(const Temazo& temazo) {
    std::cout << "TEMAZO: " << std::endl;
    std::cout << " - Título: " << temazo.getTitulo() << std::endl;
    std::cout << " - Intérprete: " << temazo.getInterprete() << std::endl;
    std::cout << " - Duración: " << temazo.getDuracion() << " segundos" << std::endl;
    std::cout << " - Puntuación: " << temazo.getPuntuacion() << " puntos" << std::endl;
}

void djutils::mostrarGarito(const Garito& garito) {
    std::cout << "GARITO: " << std::endl;
    std::cout << " - Nombre: " << garito.getNombre() << std::endl;
    std::cout << " - Dirección: " << garito.getDireccion() << std::endl;
}

void djutils::mostrarFecha(const Fecha& fecha) {
    std::cout << "FECHA: " << std::endl;
    std::cout << " - Día: " << fecha.getDia() << std::endl;
    std::cout << " - Mes: " << fecha.getMes() << std::endl;
    std::cout << " - Año: " << fecha.getAnio() << std::endl;

}
void djutils::pedirGarito(Garito& garito) {
    std::string tmp;
    std::cout << "INTRODUZCA LOS DATOS DEL GARITO: " << std::endl;
    std::cout << " - Nombre del garito: ";
    getline(std::cin, tmp);
    garito.setNombre(tmp);
    std::cout << " - Dirección del garito: ";
    getline(std::cin, tmp);
    garito.setDireccion(tmp);
}