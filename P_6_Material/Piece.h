/** 
 * @file Piece.h
 * @author Yoyapro Gramo
 *
 * @date Stellar date 20160317
 */

#ifndef PIECE_H
#define PIECE_H

#include <string>

using std::string;

/**
 * @brief
 */
class Piece
{
   private:
      string _name;
      float _weight;
      string _description;

   public:
      Piece( string name = "", float weight = 0, string description = "" );
      Piece ( const Piece& orig );
      virtual ~Piece ( );
      void setDescripction( string description );
      string getDescription( ) const;
      void setWeight( float weight );
      float getWeight( ) const;
      void setName( string name );
      string getName( ) const;
      Piece& operator= ( const Piece& orig );
};

#endif /* PIECE_H */

