/**
 * @file Mutant.h
 * @author algarcia
 *
 * @date April 6th, 2016, 19:52
 */

#ifndef MUTANT_H
#define MUTANT_H

#include <string>
#include "Power.h"
#include "PhysicalPower.h"
#include "PsychicPower.h"

using std::string;

/**
 * @brief Mutant Class
 */
class Mutant {
public:
    static const int MAX_POWERS = 10; ///< Maximum powers of a Mutant

public:
    Mutant( string name = "---", string nickname = "---", int birthdate = 0,
            string nationality = "---" );
    Mutant(const Mutant& orig);
    virtual ~Mutant();
    void setRealName( string realName );
    string getRealName( ) const;
    void setNationality( string nationality );
    string getNationality( ) const;
    void setBirthDate( int birthdate );
    int getBirthdate( ) const;
    void setNickname( string nickname );
    string getNickname( ) const;

    string toCSV() const;
    void fromCSV(std::string &text);

    Mutant& operator=(const Mutant& orig);

    //ToDo, comparison operator '<' of two mutants comparting them by their destructive capacity
    
    void addPower( string name, string description, string affectsTo,
                   float destructiveCapacity );
    void addPhysicalPower( string name, string description, string affectsTo,
                           float destructiveCapacity );
    void addPsychicPowers( string name, string description, string affectsTo,
                           float destructiveCapacity );
    void addPower( const Power &power );
    void addPower( const PhysicalPower &power );
    void addPower( const PsychicPower &power );
    int getNumPowers( ) const;
    const Power& getPower( int which );
    void deletePower( int which );
    void deletePowers( );
    float totalDestructivePower( ) const;

private:
    string _realName;
    string _nickname;
    int _birthdate;
    string _nationality;
    Power* _powers[MAX_POWERS];
    int _numPowers;

};

#endif /* MUTANT_H */

