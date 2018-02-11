/**
 * @brief
 * @file djutils.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 18:09
 */

#include "Song.h"
#include "Local.h"
#include "Date.h"

#ifndef DJUTILS_H
#define	DJUTILS_H

namespace djutils {
    void displaySong( const Song &song, std::string prefix = "" );
    void displayLocal( const Local &local, std::string prefix = "" );
    void displayDate( const Date &date, std::string prefix = "" );
    void askLocal( Local &local );
}


#endif	/* DJUTILS_H */


