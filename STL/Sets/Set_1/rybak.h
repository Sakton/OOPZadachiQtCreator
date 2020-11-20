#ifndef RYBAK_H
#define RYBAK_H
#include <iostream>

#include "ozero.h"
#include "ulov.h"

class Rybak
{
 public:
  // ctor
  Rybak( );

  // generate
  void getFishOut_n( Ozero* o, int8_t colvo );
  void add( IFish* fish );

  // sz
  size_t size( ) const;
  friend std::ostream& operator<<( std::ostream& out, const Rybak& r );
  const Ulov getUlov( ) const;

 private:
  Ulov ulov_;
};

#endif // RYBAK_H
