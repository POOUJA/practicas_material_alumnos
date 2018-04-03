/**
 * @file main.cpp
 * @author 
 *
 */

#include <iostream>
#include "MutantTeam.h"

using namespace std;

/***@brief Visualizes the complete information of a Mutant*/
void visualiza( Mutant& m) {
    std::cout << "MUTANT: "
              << m.toCSV() << std::endl;
    std::cout << "  Powers : " << std::endl;
    //ToDo, Show the powers of the Mutant

}
/***@brief Visualizes the data of all the members of a Mutant Team*/
void visualiza( MutantTeam& eq) {
    std::cout << "TEAM: " << eq.getName()
              << " (Base: " << eq.getBase()<< ")" <<std::endl
              << "============================"
              << std::endl;
    //ToDo, Show the mutants of the team (use the previous function)

}

//ToDo, Method to save a vector of pointers to Mutants
//saveMutantsCSV()


int main(int argc, char** argv) {

    // You have to create an a array of 5 pointers to mutants, assigning them
    // the values of their attributes directly from the source code

    // Create two mutant teams, assigning to the fist team the mutants that are
    // in the even positions of the array, and to the second team the odd positions

    // Add various powers to each mutant, using the methods already implemented:
    // using data or objects of type Power
    // Show on console the information of each Mutant Team in CSV format

    // Save the mutants data in a CSV file

    //Destroy all the created objects in dynamic memory before the program ending

    return 0;
}

