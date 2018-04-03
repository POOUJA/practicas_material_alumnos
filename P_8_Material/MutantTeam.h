/**
 * @file MutantTeam.h
 * @author algarcia
 *
 * @date April 6th, 2016, 19:52
 */

#ifndef MUTANTTEAM_H
#define MUTANTTEAM_H

#include <string>
#include "Mutant.h"

using std::string;

/**
 * @brief
 */
class MutantTeam
{
public:
    static const int _MAX_MEMBERS_ = 10;

public:
    MutantTeam( string name = "---", string base = "---" );
    MutantTeam ( const MutantTeam& orig );
    virtual ~MutantTeam ( );
    void setName( string name );
    string getName( ) const;
    void setBase ( string base );
    string getBase ( ) const;

    string toCSV ();
    MutantTeam& operator= ( const MutantTeam& orig );

    void addMutant( Mutant *m );
    int getNumMembers( ) const;
    Mutant* getMutant( int which );
    Mutant* removeMutant( int which );

private:
    string _name;
    string _base;
    Mutant* _members[_MAX_MEMBERS_];
    int _numMembers;

};

#endif /* MUTANTTEAM_H */

