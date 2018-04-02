/**
 * @brief Implementation of the methods from Song class
 * @file Song.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:08
 */
#include "Song.h"

/**
 * @brief Default constructor of the class
 * @post Creates an object of type Song
 */
Song::Song() : _title(""), _performer(""), _duration(0),
                   _nameLastLocal(""), _dateLastUse (),
                   _score(0)
{ }

/**
 * @brief Parameterized cosntructor
 * @param title Title of the Song
 * @param performer Person or group that plays the song
 * @param duration Duration in seconds
 * @param nameLastLocal Name of the last Local where it was played
 * @param dateLastUse Date when the Song was lastly played
 * @param score Score given by the audience
 * @post Creates an object of Song class
 */
Song::Song( std::string title, std::string performer, int duration,
            std::string nameLastLocal, Date dateLastUse,
            int score ): _title(title), _performer(performer),
                                   _duration(duration),
                                   _nameLastLocal (nameLastLocal),
                                   _dateLastUse (dateLastUse),
                                   _score(score)
{ }

/**
 * @brief Copy constructor of the class
 * @param orig Object of type Song which data will be copied
 * @post Creates a new object by cope
 */

Song::Song ( const Song& orig ): _title(orig._title),
                                       _performer(orig._performer),
                                       _duration(orig._duration),
                                       _nameLastLocal(orig._nameLastLocal),
                                       _dateLastUse(orig._dateLastUse),
                                       _score(orig._score)
{ }

/**
 * @brief Destructor of the class
 * @post Destoys the object
 */
Song::~Song()
{ }


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
 * @param performer New performes
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

void Song::setNameLastLocal( std::string nameLastLocal )
{
   this->_nameLastLocal = nameLastLocal;
}

std::string Song::getNameLastLocal( ) const
{
   return _nameLastLocal;
}

void Song::setDateLastUse( const Date &dateLastUse )
{
   this->_dateLastUse = dateLastUse;
}

Date Song::getDateLastUse( ) const
{
   return _dateLastUse;
}

