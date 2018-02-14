/**
 * @brief
 * @file djutils.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 12 de octubre de 2015, 18:12
 */

#include <iostream>
#include "djutils.h"

void djutils::showSong( const Song &song, std::string prefix ) {
    std::cout << prefix << "SONG: " << std::endl;
    std::cout << prefix << " - Title: " << song.getTitle( ) << std::endl;
    std::cout << prefix << " - Performer: " << song.getPerformer( ) << std::endl;
    std::cout << prefix << " - Duration: " << song.getDuration( ) << " seconds" << std::endl;
    std::cout << prefix << " - Score: " << song.getScore( ) << " points" << std::endl;
    std::cout << prefix << " - Last local: " << song.getNameLastLocal( ) << std::endl;
    std::cout << prefix << " - Last played date:" << std::endl;
    djutils::showDate( song.getDateLastUse( ), "      " );
}

void djutils::showLocal( const Local &local, std::string prefix ) {
    std::cout << prefix << "LOCAL: " << std::endl;
    std::cout << prefix << " - Name: " << local.getName( ) << std::endl;
    std::cout << prefix << " - Address: " << local.getAddress( ) << std::endl;
}

void djutils::showDate( const Date &date, std::string prefix ) {
    std::cout << prefix << "DATE: " << std::endl;
    std::cout << prefix << " - Day: " << date.getDay( ) << std::endl;
    std::cout << prefix << " - Month: " << date.getMonth( ) << std::endl;
    std::cout << prefix << " - Year: " << date.getYear( ) << std::endl;

}

void djutils::requestLocal( Local &local ) {
    std::string tmp;
    std::cout << "INSERT DATA OF THE LOCAL: " << std::endl;
    std::cout << " - Name of the local: ";
    getline(std::cin, tmp);
    local.setName( tmp );
    std::cout << " - Address of the local: ";
    getline(std::cin, tmp);
    local.setAddress( tmp );
}

void djutils::showPreviousSongs( const Song *vSongs, int sizeV,
                                 const Date &reference )
{
   std::cout << "The songs previous to the indicated date are:" << std::endl;
   for ( int i = 0; i < sizeV; i++ )
   {
      if ( vSongs[ i ].getDateLastUse( ) < reference )
      {
          djutils::showSong( vSongs[ i ] );
      }
   }
}