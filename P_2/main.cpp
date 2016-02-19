/** 
 * @brief Fichero principal de la práctica 2 de POO
 * @file main.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:08
 */

#include <iostream>
#include <cstdlib>

#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"
#include "djutils.h"

using namespace std;

/**
 * @brief Función principal
 * @argc Número de argumentos pasados por línea de órdenes
 * @argc Caractares pasados como argumentos por línea de órdenes
 * @return 0 si todo funciona bien; distinto de 0 en otro caso.
 */
int main(int argc, char** argv) {
    cout << "POO: Práctica 2 resuelta" << endl;
    // 2 temazos: uno usando el constructor por defecto y otro usando el parametrizado
    Temazo tema1;
    Temazo tema2("Vaya torito", "El Fari", 194, 10);

    // 2 garitos: uno usando el constructor parametrizado y otro  usando el constructor de copia
    Garito local1("Bar Felipe Sanchez", "C/ Besugo nº 4, 72123, Alcornarejo");
    Garito local2 = local1;

    // 2 fechas: una usando el constructor por defecto y otra el constructor parametrizado.
    Fecha fecha1;
    Fecha fecha2(12, 10, 2016);


    cout << "En primer lugar mostramos datos SIN usar menú." << endl << endl;
    // A continuación, usando las funciones de la biblioteca auxiliar, escribir los datos de los temazos, los garitos y las fechas en pantalla.
    djutils::mostrarTemazo(tema1);
    djutils::mostrarTemazo(tema2);
    djutils::mostrarGarito(local1);
    djutils::mostrarGarito(local2);
    djutils::mostrarFecha(fecha1);
    djutils::mostrarFecha(fecha2);
    /*
            Finalmente, modificar los datos del 2º garito(el que hemos creado por copia) y luego escribir en pantalla los nuevos datos del mismo, usando para ello las funciones declaradas en la biblioteca de funciones auxiliares.
     * */

    djutils::pedirGarito(local2);
    djutils::mostrarGarito(local2);

    /*

            6. (Opcional) Crear un menú que permita al usuario decidir si quiere : a) mostrar los datos de los Temazos;
    b) mostrar los datos de los garitos;
    c) mostrar los datos de las fechas;
    d) modificar los datos del segundo garito;
    e) terminar el programa.
     */

    cout << endl << endl 
            << "En segundo lugar mostramos datos USANDO un menú." 
            << endl << endl;
    int opcion = 0;
    do {
        cout << "Indique la opción que desea ejecutar: " << endl;
        cout << " [1] Mostrar datos de temazos " << endl;
        cout << " [2] Mostrar datos de garitos " << endl;
        cout << " [3] Mostrar datos de fechas " << endl;
        cout << " [4] Modificar los datos del segundo garito" << endl;
        cout << endl;
        cout << " [0] Salir del programa" << endl;
        cin >> opcion;
        cin.ignore(1);

        switch (opcion) {
            case 0:
            {
                cout << "Saliendo de la aplicación" << endl;
                break;
            }
            case 1:
            {
                djutils::mostrarTemazo(tema1);
                djutils::mostrarTemazo(tema2);
                break;
            }
            case 2:
            {
                djutils::mostrarGarito(local1);
                djutils::mostrarGarito(local2);
                break;
            }
            case 3:
            {
                djutils::mostrarFecha(fecha1);
                djutils::mostrarFecha(fecha2);
                break;
            }
            case 4:
            {

                djutils::pedirGarito(local2);
                djutils::mostrarGarito(local2);
                break;
            }
            default:
            {
                cout << "La opción pulsada: " << opcion << " NO es válida" << endl;
            }

        }
        if (opcion >= 1 && opcion <= 4) {
            string tmp;
            cout << "Pulse enter para continuar..." << endl;
            getline(cin, tmp);
        }
    } while (opcion != 0);


    return 0;
}

