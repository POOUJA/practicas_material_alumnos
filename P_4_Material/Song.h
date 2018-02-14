/**
 * @file Song.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @desc Song class for OOP practices
 * @date 12 de octubre de 2015, 17:08
 */

#ifndef SONG_H
#define	SONG_H

#include <string>
#include "Date.h"

/**
 @brief Class that saves the data of a Song
 */
class Song {
public:
    Song();
    Song( std::string title, std::string performer, int duration,
          std::string nameLastLocal, Date dateLastUse,
          int score = 0 );
    Song(const Song& orig);
    virtual ~Song();
    int getScore( ) const;
    void setDuration( int duration );
    int getDuration( ) const;
    void setPerformer( std::string performer );
    std::string getPerformer( ) const;
    void setTitle( std::string title );
    std::string getTitle( ) const;
    void setNameLastLocal( std::string nameLastLocal );
    std::string getNameLastLocal( ) const;
    void setDateLastUse( const Date &dateLastUse );
    Date getDateLastUse( ) const;

private:
    std::string _title; ///< Title of the song
    std::string _performer; ///< Performer
    int _duration; ///< Duration in seconds
    int _score; ///< Score depending on how the audience like it
    std::string _nameLastLocal;   ///< Last local where it was played
    Date _dateLastUse;   ///< Last day when it was played
};

#endif	/* SONG_H */

