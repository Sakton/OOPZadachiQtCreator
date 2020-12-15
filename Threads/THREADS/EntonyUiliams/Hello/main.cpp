#include <iostream>
#include <thread>

void hello( );

int main( ) {
  std::thread t( hello );
  t.join( );  //ждать поток
}

void hello( ) { std::cout << "Hello parallel world"; }
