/* 
 * File:   main.cpp
 * Author: jrbalsas
 *
 * Created on 15 de abril de 2016, 11:11
 */

#include <cstdlib>
#include <iostream>

#include "Chest.h"
#include "Item.h"
using namespace std;

/**Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a 0
 * @return número de posiciones del vector con items creados*/
int inicializaItems(Item* v[], int tamv) {
    int numItems=0;

    v[numItems++] = new Item("Bloque de tierra (5)");
    v[numItems++] = new Item("Bloque de tierra (8)");
    v[numItems++] = new Item("Bloque de tierra (1)");    
    v[numItems++] = new Item("Espada de madera");   
    v[numItems++] = new Item("Muslo de pollo");       

    //Asigna a 0 el resto de posiciones no ocupadas
    for (int i = numItems; i < tamv; i++) {
        v[i] = 0;
    }        
    return numItems;
}
/**Libera los items del vector creados en memoria dinámica*/
void liberaItems(Item* v[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        delete v[i];
        v[i]=0;
    }

}

void visualiza(Chest &c) {
    std::cout << "CONTENIDO DEL COFRE" << std::endl
              << "===================" << std::endl;
    for (int i = 1; i <= c.howManyThereAre( ); i++) {
        std::cout << i <<".- "
                  << c.see( i ).getDescription( ) << std::endl;
    }

}


/**@brief Probando los Cofres
 * 
 */
int main(int argc, char** argv) {

    const int MAXITEMS=10;
    Item* objetos[MAXITEMS];

    //Inicializamos algunos objetos de prueba
    int numObjetos=inicializaItems(objetos,MAXITEMS);

    Chest c; //Creamos un cofre con 27 posiciones
    
    //Metemos todos los objetos en el cofre
    
    for (int i = 0; i < numObjetos; i++) {
        c.put( objetos[ i ] );
    }

    visualiza(c);    
    
    //Liberamos recursos
    liberaItems(objetos,numObjetos);
    
    return 0;
}

