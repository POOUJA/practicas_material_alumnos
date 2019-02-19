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
    std::cout << prefijo << " - Título: " << temazo.getTitulo() << std::endl;
    std::cout << prefijo << " - Intérprete: " << temazo.getInterprete() << std::endl;
    std::cout << prefijo << " - Duración: " << temazo.getDuracion() << " segundos" << std::endl;
    std::cout << prefijo << " - Puntuación: " << temazo.getPuntuacion() << " puntos" << std::endl;
    std::cout << prefijo << " - Último garito: " << temazo.getNombreUltimoGarito () << std::endl;
    std::cout << prefijo << " - Fecha de la última reproducción:" << std::endl;
    djutils::mostrarFecha (temazo.getFechaUltimoUso (), "      " );
}

void djutils::mostrarGarito(const Garito& garito,std::string prefijo) {
    std::cout << prefijo << "GARITO: " << std::endl;
    std::cout << prefijo << " - Nombre: " << garito.getNombre() << std::endl;
    std::cout << prefijo << " - Dirección: " << garito.getDireccion() << std::endl;
}

void djutils::mostrarFecha(const Fecha& fecha,std::string prefijo) {
    std::cout << prefijo << "FECHA: " << std::endl;
    std::cout << prefijo << " - Día: " << fecha.getDia() << std::endl;
    std::cout << prefijo << " - Mes: " << fecha.getMes() << std::endl;
    std::cout << prefijo << " - Año: " << fecha.getAnio() << std::endl;

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

void djutils::mostrarTemazosAnteriores ( const Temazo vTemazos[], int tamV,
                                         const Fecha& referencia )
{
   std::cout << "Los temazos anteriores a la fecha indicada son:" << std::endl;
   for ( int i = 0; i < tamV; i++ )
   {
      if ( vTemazos[i].getFechaUltimoUso () < referencia )
      {
         djutils::mostrarTemazo ( vTemazos[i] );
      }
   }
}