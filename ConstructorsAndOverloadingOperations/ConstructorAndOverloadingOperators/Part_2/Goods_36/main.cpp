#include "goods36b.h"
#include <iostream>

using namespace std;

int main( ) {
  Goods36B gds( "Test1", "23.09.2020", 1, 398.00, 2 );
  Display( gds );
  AddCount( gds, 2 );
  Display( gds );

  SetPrice( gds, 100 );
  Display( gds );

  SubCount( gds, 2 );
  Display( gds );
}
