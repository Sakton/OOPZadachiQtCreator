#include <iostream>

#include "money24.h"

using namespace std;

int main( ) {
  Money24B mn( 100, 10 );
  mn.Display( );
  Money24B mn1( 1000, 10 );
  mn1.Display( );

  mn += mn1;
  mn.Display( );

  cout << "Hello World!" << endl;
  return 0;
}
