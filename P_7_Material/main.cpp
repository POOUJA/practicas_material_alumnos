/**
 * @file main.cpp
 * @author 
 *
 */

#include <iostream>
#include "EquipoMutante.h"

using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza( Mutante& m) {
    std::cout << "MUTANTE: " 
              << m.toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    //ToDo, Mostrar los poderes del mutante

}
/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza( EquipoMutante& eq) {
    std::cout << "EQUIPO: " << eq.getNombre() 
              << " (Base: " << eq.getBase()<< ")" <<std::endl
              << "============================"
              << std::endl;
    //ToDo, Mostrar los mutantes del equipo (usar función anterior)

}

//ToDo, Método para almacenar un vector de punteros a mutantes
//almacenaMutantesCSV()


int main(int argc, char** argv) {

    
   // Crea un array de 5 punteros a mutantes, asignándoles los valores a sus
   // atributos directamente en el código fuente

    
   // Crea dos equipos mutantes, asignando al primero los mutantes que ocupan
   // las posiciones pares del array, y al segundo los de las posiciones impares
    
    
   // Añade varios poderes a cada mutante, utilizando los métodos ya
   // implementados: usando datos o objetos de tipo Poder
   // Muestra por la consola la información de cada equipo mutante en formato CSV

    
   //Guardamos datos de mutantes en fichero CSV
    
    
   // Destruye todos los objetos creados en memoria dinámica antes de la
   // finalización del programa

    
    
    return 0;
}

