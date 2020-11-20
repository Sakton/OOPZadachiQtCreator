#include <ctime>
#include <iostream>

#include "ogorod.h"

int main( ) {
  std::srand( std::time( nullptr ) );
  Ogorod og1;
  Ogorod og2;
  //  Ogorod og3;
  std::cout << og1 << std::endl;
  std::cout << std::endl;
  std::cout << og2 << std::endl;
  std::cout << std::endl;
  //  std::cout << og3 << std::endl;
  //  std::cout << std::endl;

  Ogorod t1 = ( og1 + og2 );
  Ogorod t2 = ( og1 - og2 );
  Ogorod t3 = ( og1 / og2 );

  std::cout << t1 << std::endl;
  std::cout << std::endl;
  std::cout << t2 << std::endl;
  std::cout << std::endl;
  std::cout << t3 << std::endl;
  std::cout << std::endl;
}
