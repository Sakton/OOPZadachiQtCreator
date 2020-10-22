#include <iostream>

#include "payment39b.h"

using namespace std;

int main( ) {
  Payment39B pay( "name", 50000.0, "20.02.2013", 1.3, 22, 31 );
  pay.Display( );
}
