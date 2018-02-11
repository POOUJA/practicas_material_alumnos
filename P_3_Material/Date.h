/**
 * @file Date.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @desc Date class for OOP practice classes
 * @date 12 de octubre de 2015, 17:08
 */


#ifndef DATE_H
#define	DATE_H
/**
 * @brief Date class
 */
class Date {
public:
    Date();
    Date( int day, int month, int year );
    Date(const Date& orig);
    virtual ~Date();
    void setYear( int year );
    int getYear( ) const;
    void setMonth( int month );
    int getMonth( ) const;
    void setDay( int day );
    int getDay( ) const;
private:
    int _day; ///< Day in a month
    int _month; ///< Month in a year
    int _year; ///< Year of the stored date
};

#endif	/* DATE_H */

