/**
 * @file main.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <cstdlib>
#include <iostream>
#include "EquipoMutante.h"

using namespace std;

/**
 *
 */
int main ( int argc, char** argv )
{
   const int MAXMUTANTES = 5;
   Mutante* mutantes[MAXMUTANTES];

   mutantes[0] = new Mutante ( "Logan", "Lobezno", 19320101, "Estadounidense" );
   mutantes[1] = new Mutante ( "Marie", "Rogue", 19700101, "Estadounidense" );
   mutantes[2] = new Mutante ( "Ororo", "Tormenta", 19500101, "Keniata" );
   mutantes[3] = new Mutante ( "Scott", "Cíclope", 19300101, "Estadounidense" );
   mutantes[4] = new Mutante ( "Charles", "Profesor X", 19200101, "Estadounidense" );

   EquipoMutante patrullaX ( "Patrulla X", "Mansión" );
   patrullaX.addMutante (mutantes[1]);
   patrullaX.addMutante (mutantes[3]);

   EquipoMutante malvados ("Los malos", "Casa Magneto");
   malvados.addMutante (mutantes[0]);
   malvados.addMutante (mutantes[2]);
   malvados.addMutante (mutantes[4]);

   mutantes[0]->addPoder ( "longevidad", "vivir mucho", "su cuerpo", 0 );
   mutantes[1]->addPoder ( "absorción", "absorve poderes de otros mutantes",
                           "cualquier mutante", 100 );
   mutantes[2]->addPoderFisico ( "clima", "puede manejar el clima", "atmósfera",
                                 150 );
   mutantes[3]->addPoderFisico ( "rayo", "expulsa láser por los ojos",
                                 "lo que pille por delante", 500 );
   mutantes[4]->addPoderPsiquico ( "AtacaMente", "ataca la mente de su enemigo",
                                   "cualquiera", 150 );

   std::cout << patrullaX.toCSV () << std::endl;
   std::cout << malvados.toCSV () << std::endl;

   for ( int i = 0; i < MAXMUTANTES; i++ )
   {
      delete mutantes[i];
   }

   return 0;
}

