/**
 * @file main.cpp
 * @author algarcia
 *
 * @date April 6th 2016
 */

#include <iostream>
#include <fstream>
#include "MutantTeam.h"

using namespace std;

/***@brief Visualizes the complete information of a Mutant*/
void visualize( Mutant &m ) {
    std::cout << "MUTANT: "
              << m.toCSV() << std::endl;
    std::cout << "  Powers : " << std::endl;
    for (int i = 0; i < m.getNumPowers(); i++) {
        std::cout << "    - " << m.getPower(i).toCSV()<<std::endl;
    }
}
/***@brief Visualizes the data of all of the members of the Mutant team*/
void visualize( MutantTeam &eq ) {
    std::cout << "TEAM: " << eq.getName()
              << " (Base: " << eq.getBase()<< ")" <<std::endl
              << "============================"
              << std::endl;
    for (int i = 0; i < eq.getNumMembers(); i++) {
        visualize( *( eq.getMutant( i )));
    }
}

//ToDo
/***@brief Visualizes a vector of Mutants in CSV format*/
void visualize( ) {
    
}


/**@brief Saves the Mutants of a vector in a CSV file
   @param Mutant* v[], vector of pointers to Mutant objects
   @param unsigned int sizeV, number of mutants saved in a vector
   @param string fileName, file where the Mutants are going to be saved. If there's anything, it'll overwrite
   @post  Saves simple data (without powers) of each Mutant in a CSV format in a different line from the specified file
 */
void saveMutantsCSV( Mutant **v, unsigned int sizeV, std::string fileName ) {
    std::ofstream file;
    file.open(fileName.c_str()); //c_str() is  not necessary if the compiler supports >= C++11

    if (file.good()) {
        for (unsigned int i = 0; i < sizeV; i++) {
            file << v[i]->toCSV() << std::endl;
        }
        file.close();
    }
}

//ToDo
/**@brief Retrieves mutants from a CSV file to a vector
   @param Mutant* v[], vector of pointers to Mutant objects
   @param unsigned int sizeV, maximum number of mutants that can be saved in v
   @param string fileName, file from which Mutants are retieved in CSV format
   @post  Positions will be overwritten
   @post  Retrieves Mutants from the file and it creates them in dynamic memory, associating each one to a position
          of the vector
   @return number of read and created (max is going to be sizeV)
 */
int retrieveMutantsCSV( Mutant **v, unsigned int sizeV, std::string fileName) {

}
    
/**@brief initializes vector of Mutants and creates some
   @pre v has to have at least sizeV positions
   @post will initialize all v's position to 0 or a new Mutant
   @return number of created Muntats in the vector*/
int initializeMutants( Mutant **v, int sizeV ) {
    
    for (int i = 0; i < sizeV; i++) {
        v[i]=0;
    }

    int created=0;
    v[created++] = new Mutant("Logan", "Wolverine", 19320101, "American");
    v[created++] = new Mutant("Marie", "Rogue", 19700101, "American");
    v[created++] = new Mutant("Ororo", "Thunder", 19500101, "Kenian");
    v[created++] = new Mutant("Scott", "Cyclop", 19300101, "American");
    v[created++] = new Mutant("Charles", "Professor X", 19200101, "American");

    return created;
}


int main(int argc, char** argv) {

    const int MAXMUTANTS = 5;
    Mutant* mutants[MAXMUTANTS];
    int numMutants=0;
    std::string mutantsFile="mutants.csv";
    
    numMutants= initializeMutants( mutants, MAXMUTANTS );
    //ToDo, retrieves Mutants from the file
    
    //ToDo, Visualizes vector of Mutants in CSV format
    
    
    //Creation of the teams of configuration of powers
    MutantTeam team1("Patrol X", "Mansion");
    team1.addMutant(mutants[1]);
    team1.addMutant(mutants[3]);

    MutantTeam team2("The bad guys", "Magneto's house");
    team2.addMutant(mutants[0]);
    team2.addMutant(mutants[2]);
    team2.addMutant(mutants[4]);

    //Different ways of adding powers_ using data or objects of type Power
    mutants[0]->addPower("longevity", "live a lot", "the body", 0);
    mutants[1]->addPower(Power("absorption", "absorbs powers from other Mutants",
            "any Mutant", 100));
    mutants[2]->addPhysicalPower("weather", "can control weather", "atmosphere",
            150);
    mutants[3]->addPower(PhysicalPower("laser", "shoots laser from the eyes",
            "anything it touches", 500));
    mutants[4]->addPower(PsychicPower("MindAttack", "attacks enemies' minds",
            "any", 150));

    visualize( team1 );
    visualize( team2 );
    
    //ToDo, Create physical power 'suffocate' and add Doctor
    
    //ToDo, Order and visualize a vector of Mutants with template of Order method
    //Check that DoctorX has improved his position as his Destructive capacity has increased

    saveMutantsCSV( mutants, 5, mutantsFile );

    for (int i = 0; i < MAXMUTANTS; i++) {
        delete mutants[i];
        mutants[i] = 0;
    }

    return 0;
}

