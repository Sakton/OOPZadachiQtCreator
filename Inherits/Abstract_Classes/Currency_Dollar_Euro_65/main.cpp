#include <iostream>

#include "dollar.h"
#include "euro.h"

class Factory {
 public:
  virtual ~Factory( ) {}
  Currency* getDollar( double summ ) { return new Dollar( summ ); }
  Currency* getEuro( double summ ) { return new Euro( summ ); }
};

int main( ) {
  Factory f;
  Currency* d = f.getDollar( 100 );
  d->change( );
  d->display( );

  Currency* e = f.getEuro( 100 );
  e->change( );
  e->display( );
}
