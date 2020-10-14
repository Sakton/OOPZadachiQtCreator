#include <iostream>

#include "goods_50.h"

int main( ) {
  Goods50 gd;
  gd.Init( "aaaa", "27.09.2019", 1, 100.0, 2000 );
  gd.Display( );
  gd.Sale( 1 );
  gd.Display( );
}
