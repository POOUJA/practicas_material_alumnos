/**
 * @file Power.h
 * @author algarcia
 *
 * @date April 6th, 2016, 19:52
 */

#ifndef POWER_H
#define POWER_H

#include <string>

using std::string;

/**
 * @brief
 */
class Power
{
   private:
      string _name;
      string _description;
      string _affectsTo;
      float _destructiveCapacity;

   public:
      Power( string name = "---", string description = "---", string affectsTo = "---", float destructiveCapacity = 0 );
      Power ( const Power& orig );
      virtual ~Power ( );
      void setName( string name );
      string getName( ) const;
      void setDestructiveCapacity( float destructiveCapacity );
      float getDestructiveCapacity( ) const;
      void setAffectsTo( string affectsTo );
      string getAffectsTo( ) const;
      void setDescription( string description );
      string getDescription( ) const;

      string toCSV () const;
      Power& operator= ( const Power& orig );
      
};

#endif /* POWER_H */

