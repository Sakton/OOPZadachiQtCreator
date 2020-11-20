#ifndef ULOV_H
#define ULOV_H
#include <iostream>
#include <set>

#include "ifish.h"

class Predicat {
 public:
  bool operator( )( const IFish* a, const IFish* b ) const { return a->getId( ) < b->getId( ); }
};

class Ulov
{
 public:
  Ulov( );
  void push( IFish* f );
  size_t size( ) const;
  friend std::ostream& operator<<( std::ostream& out, const Ulov& r );

  friend const Ulov operator+( const Ulov& u1, const Ulov& u2 );
  friend const Ulov operator-( const Ulov& u1, const Ulov& u2 );
  friend const Ulov operator/( const Ulov& u1, const Ulov& u2 );

 private:
  std::set< IFish*, Predicat > ulov_;
};

#endif // ULOV_H
