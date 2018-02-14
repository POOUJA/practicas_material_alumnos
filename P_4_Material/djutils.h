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
    void showSong( const Song &song, std::string prefix = "" );
    void showLocal( const Local &local, std::string prefix = "" );
    void showDate( const Date &date, std::string prefix = "" );
    void requestLocal( Local &local );
    void showPreviousSongs( const Song *vSongs, int sizeV,
                            const Date &reference );
}


#endif	/* DJUTILS_H */

