#ifndef ULOV_H
#define ULOV_H
#include <iostream>
#include <set>

#include "ifish.h"

class Ulov
{
 public:
  Ulov( );
  // void push( IFish* f );
  void push( std::shared_ptr< IFish > f );
  size_t size( ) const;
  friend std::ostream& operator<<( std::ostream& out, const Ulov& r );

  friend const Ulov operator+( const Ulov& u1, const Ulov& u2 );
  friend const Ulov operator-( const Ulov& u1, const Ulov& u2 );
  friend const Ulov operator/( const Ulov& u1, const Ulov& u2 );

 private:
  std::set< std::shared_ptr< IFish >, Predicat > ulov_;
};

#endif // ULOV_H
