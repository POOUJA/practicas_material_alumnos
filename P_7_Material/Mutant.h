/**
 * @file Mutant.h
 * @author algarcia
 *
 * @date April 6th, 2016, 19:52
 */

#ifndef MUTANT_H
#define MUTANT_H

#include <string>

using std::string;

/**
 * @brief Mutant Class
 */
class Mutant {
public:
    static const int MAX_POWER = 10; ///< Mutant's max power

public:
    Mutant( string name = "---", string nickname = "---", int birthdate = 0,
            string nationality = "---" );
    Mutant(const Mutant& orig);
    virtual ~Mutant();
    void setRealName( string realName );
    string getRealName( ) const;
    void setNationality( string nationality );
    string getNationality( ) const;
    void setBirthDate( int birthDate );
    int getBirthDate( ) const;
    void setNickname( string nickname );
    string getNickname( ) const;

    string toCSV() const;

    Mutant& operator=(const Mutant& orig);

private:
    string _realName;
    string _nickname;
    int _birthDate;
    string _nationality;

};

#endif /* MUTANT_H */

