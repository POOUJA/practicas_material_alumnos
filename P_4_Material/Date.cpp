/**
 * @brief Implementation of Date class
 * @file Date.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 17:59
 */
#include <time.h>
#include "Date.h"

/**
 * @brief Default constructor of the clas
 * @post Constructs a new object setting the day, month and year to the indicated by the system
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
 * @brief Parameterized cosntructor
 * @param day Day for the Date
 * @param month Month for the Date
 * @param year Year for the Date
 * @post Creates an object with the indicated values
 */
Date::Date( int day, int month, int year ) :
_day(day)
, _month(month)
, _year(year) {
}

/**
 * @brief Copy constructor of the class
 * @param orig Object from which data is copied
 * @post Creates an object of class Date
 */

Date::Date(const Date& orig):
_day(orig._day)
, _month(orig._month)
, _year(orig._year) {
}

/**
 * @brief Destructor of the object
 * @post Destroys the object
 */
Date::~Date() {
}

/**
 * @brief Modifies the year of the Date
 * @param year New year for the Date
 * @post Modifies the year of the Date
 */
void Date::setYear( int year ) {
    this->_year = year;
}

/**
 * @brief Returns the year of the Date
 * @post Returns the year of the Date
 */
int Date::getYear( ) const {
    return _year;
}

/**
 * @brief Modifies the month of the Date
 * @param month New month for the Date
 * @post Modifies the month of the Date
 */
void Date::setMonth( int month ) {
    this->_month = month;
}

/**
 * @brief Returns the month of the Year
 * @post Returns the month of the Year
 */
int Date::getMonth( ) const {
    return _month;
}

/**
 * @brief Modifies the day of the Date
 * @param day New day for the Date
 * @post Modifies the day of the Date
 */
void Date::setDay( int day ) {
    this->_day = day;
}
/**
 * @brief Returns the day of the Date
 * @post Returns the day of the Date
 */
int Date::getDay( ) const {
    return _day;
}


/**
 * @brief Operator "less than"
 * @param other Date being compared
 * @retval true si if the date stored in this object is earlier than the date passed as a parameter
 * @retval false if the date stored in this object is later that the dated passed as a parameter, or if both match
 */
bool Date::operator <( const Date &other )
{
   long numThis = _year*10000 + _month*100 + _day;
   long numOther = other._year*10000 + _month*100 + _day;

   return ( numThis < numOther );
}


/**
 * @brief Operator "equal to"
 * @param other Date being compared
 * @retval true if the date stored in this object is equal to the date passed as a parameter
 * @retval false if the date stored in this object is NOT equal to the date passed as a parameter
 */
bool Date::operator ==( const Date &other )
{
   long numThis = _year*10000 + _month*100 + _day;
   long numOther = other._year*10000 + _month*100 + _day;

   return ( numThis == numOther );
}

/**
 * @brief Operator "less than or equal to"
 * @param other Date being compared
 * @retval true if the date stored in this object is earlier than or iqual to the date that is passed as a parameter
 * @retval false if the date stored in this object is later than or equal to the date that is passed as a parameter
 */
bool Date::operator<=( const Date &other )
{
   return ( ( this->operator < (other) ) || ( this->operator == (other) ) );
}

/**
 * @brief Operator "greater than or equal to"
 * @param other Date being compared
 * @retval true if the date stored in this object is equal to or later than the date passed as a parameter
 * @retval false si if the date stored in this object is earlier than the date passed as a parameter
 */
bool Date::operator>=( const Date &other )
{
   return ( !( this->operator < (other) ) );
}

/**
 * @brief Operator "greater than"
 * @param other Date being compared
 * @retval true if the date stored in this object is later than or equal to the date that is passed as a parameter
 * @retval false if the date stored in this object is earlier than or iqual to the date that is passed as a parameter
 */
bool Date::operator>( const Date &other )
{
   return ( !( this->operator < (other) ) && !( this->operator == (other) ) );
}

/**
 * @brief Operador de "distinto a"
 * @param other Date being compared
 * @retval true if the date stored in this object is different to the passed passed as a parameter
 * @retval false if the date stored in this object is equal to the date passed as a parameter
 */
bool Date::operator!=( const Date &other )
{
   return ( !( this->operator == (other) ) );
}
