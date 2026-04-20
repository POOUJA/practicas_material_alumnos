/** 
 * @file   main.cpp
 * @author jrbalsas
 *
 * @date 15 de abril de 2016
 */

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cassert>

#include "Cofre.h"
#include "Item.h"
#include "Bloque.h"
#include "Espada.h"
#include "Filete.h"

using namespace std;

/** Crea algunos items en un vector de punteros a Item
 * 
 * @pre v está vacío, es decir,el vector está inicializado  todos sus punteros son nullptr
 * @pre tamv es mayor o igual a 5
 * @post crea algunos items en memoria dinámica y los coloca en las primeras posiciones del vector
 * @return número de posiciones iniciales del vector donde se han colocado los items creados
 * @note los items creados deben ser liberados cuando ya no se necesiten para evitar fugas de memoria
 */
int generaItems(Item* v[], int tamv) {
	
	assert(tamv>=5);
	/* la plantilla de función all_of devuelve true si todos ls valores de una secuencia
       satisfacen un predicado (función que devuelve un valor booleano) */
    assert( std::all_of(v, v+tamv, [] (Item* val) {return val==nullptr;} ) );

    int numItems=0;

    v[numItems++] = new Bloque(5);
    v[numItems++] = new Bloque(8);
    v[numItems++] = new Bloque();
    v[numItems++] = new Espada();
    v[numItems++] = new Filete();

    //El resto de posiciones no se modifican

    return numItems;
}

/** Libera los items del vector creados en memoria dinámica*/
void liberaItems(Item* v[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        delete v[i];
        v[i] = nullptr;
    }
}

void visualiza(Cofre &c) {
    std::cout << "CONTENIDO DEL COFRE 📦" << std::endl
            << "===================" << std::endl;
    for (int i = 1; i <= c.cuantosHay(); i++) {
        std::cout << i << ".- "
                << c.consulta(i).getDescripcion() << std::endl;
    }
}

/** @brief Probando los Cofres
 */
int main(int argc, char** argv) {

    const int MAXITEMS=10;
    Item* objetos[MAXITEMS]{nullptr}; //inicialización uniforme de todas las posiciones a nullptr
    
    try {
        //Creamos algunos objetos de prueba
        int numObjetos=generaItems(objetos,MAXITEMS);

        Cofre c; //Creamos un cofre con 27 posiciones

        //Metemos todos los objetos en el cofre
        try {
            for (int i = 0; i < numObjetos; i++) {
                c.mete(objetos[i]);
            }
        }catch(std::exception &e) {
            //Capturamos cualquier excepción de la jerarquía que pueda generar
            //Consulta::mete. Es decir: out_of_range y invalid_argument
            std::cerr   << "Error al intentar meter un objeto en el cofre: "
                        << e.what() << std::endl;
        }

        visualiza(c);

        //Liberamos recursos
        liberaItems(objetos, numObjetos);
        
    } catch (std::exception &e) {
        //Capturamos cualquier excepción que se haya podido escapar
        //durante el desarrollo
        std::cerr << "Finalización del programa por excepción sin capturar: "
                << e.what() << std::endl;
    }
    return 0;
}

