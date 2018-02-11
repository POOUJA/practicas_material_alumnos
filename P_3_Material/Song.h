/**
 * @file Song.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @desc Song class for OOP practice classes
 * @date 12 de octubre de 2015, 17:08
 */

#include <string>
#ifndef SONG_H
#define	SONG_H

/**
 @brief Class that saves the data of a song
 */
class Song {
public:
    Song();
    Song( std::string title, std::string performer, int duration, int score = 0 );
    Song(const Song& orig);
    virtual ~Song();
    int getScore( ) const;
    void setDuration( int duration );
    int getDuration( ) const;
    void setPerformer( std::string performer );
    std::string getPerformer( ) const;
    void setTitle( std::string title );
    std::string getTitle( ) const;
private:
    std::string _title; ///< Title of the song
    std::string _performer; ///< Performer
    int _duration; ///< Duration in seconds
    int _score; ///< Score depending on how the audience like it
};

#endif	/* SONG_H */


