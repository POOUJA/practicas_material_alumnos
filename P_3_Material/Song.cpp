/**
 * @brief Methods' implementaion of Song Class
 * @file Song.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:08
 */
#include "Song.h"

/**
 * @brief Default constructor of the class
 * @post Creates an object of Song Class
 */
Song::Song() :
_title("")
, _performer("")
, _duration(0)
, _score(0) {
}

/**
 * @brief Parametrized constructor
 * @param title Title of the song
 * @param performer Person or group that performs
 * @param duration Duration in seconds
 * @param score Score given by the audience
 * @post Created an object of Song Class
 */
Song::Song( std::string title, std::string performer, int duration, int score ) :
_title(title)
, _performer(performer)
, _duration(duration)
, _score(score) {
}

/**
 * @brief Copy constructor of the class
 * @param orig Original object from which data is obtained
 * @post Creates a new object by copy
 */

Song::Song(const Song& orig) :
_title(orig._title)
, _performer(orig._performer)
, _duration(orig._duration)
, _score(orig._score) {
}

/**
 * @brief Destructor of the class
 * @post Destructs the object
 */
Song::~Song() {
}


/**
 * @brief Returns the score of the Song
 * @post  Returns the score of the Song
 */
int Song::getScore( ) const {
    return _score;
}

/**
 * @brief Modifies the duration of the Song
 * @param duration New duration
 * @post Modifies the duration of the Song
 */
void Song::setDuration( int duration ) {
    this->_duration = duration;
}

/**
 * @brief Returns the duration of the Song
 * @post  Returns the duration of the Song
 */
int Song::getDuration( ) const {
    return _duration;
}

/**
 * @brief Modifies the performer of the Song
 * @param performer Nuevo intérprete
 * @post Modifies the performer of the Song
 */
void Song::setPerformer( std::string performer ) {
    this->_performer = performer;
}

/**
 * @brief Returns the performer of the Song
 * @post  Returns the performer of the Song
 */
std::string Song::getPerformer( ) const {
    return _performer;
}

/**
 * @brief Modifies the title of the Song
 * @param title New title
 * @post Modifies the title of the Song
 */
void Song::setTitle( std::string title ) {
    this->_title = title;
}

/**
 * @brief Returns the title of the Song
 * @post  Returns the title of the Song
 */
std::string Song::getTitle( ) const {
    return _title;
}


