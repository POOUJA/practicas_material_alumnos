/**
 * @brief Date class implementation
 * @file Date.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:59
 */
#include <time.h>
#include "Date.h"

/**
 * @brief Default constructor of the class
 * @post Constructs a new object setting the day, month and year to which the system indicates
 */
Date::Date() :
_day(0)
, _month(0)
, _year(0) {
    struct tm *tmp;
    time_t date;
    time(&date);
    tmp = localtime(&date);
    this->_year = tmp->tm_year + 1900;
    this->_month = tmp->tm_mon + 1;
    this->_day = tmp->tm_mday;
}

/**
 * @brief Parametrized constructor
 * @param day Day for the date
 * @param month Month for the date
 * @param year Year for the date
 * @post Creates an object with the indicated values
 */
Date::Date( int day, int month, int year ) :
_day(day)
, _month(month)
, _year(year) {
}

/**
 * @brief Copy constructor of the class
 * @param orig Original object from which data is copied
 * @post Creates and object of type Date
 */

Date::Date(const Date& orig):
_day(orig._day)
, _month(orig._month)
, _year(orig._year) {
}

/**
 * @brief Destructor of the class
 * @post Destructs the object
 */
Date::~Date() {
}

/**
 * @brief Modifies the year of the date
 * @param year New year for the date
 * @post Modifies the year of the date
 */
void Date::setYear( int year ) {
    this->_year = year;
}

/**
 * @brief Returns the year of the date
 * @post Returns the year of the date
 */
int Date::getYear( ) const {
    return _year;
}

/**
 * @brief Modifies the month of the date
 * @param month New month to be set for the date
 * @post Modifies the month of the date
 */
void Date::setMonth( int month ) {
    this->_month = month;
}

/**
 * @brief Returns the month of the date
 * @post Returns the month of the date
 */
int Date::getMonth( ) const {
    return _month;
}

/**
 * @brief Modifies the day of the date
 * @param day New date for the day
 * @post Modifies the day of the date
 */
void Date::setDay( int day ) {
    this->_day = day;
}
/**
 * @brief Returns the day of the date
 * @post Returns the day of the date
 */
int Date::getDay( ) const {
    return _day;
}

