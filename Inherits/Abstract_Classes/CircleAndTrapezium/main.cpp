#include <iostream>
#include <vector>

#include "circle.h"
#include "factory.h"
#include "rectangle.h"
#include "trapezium.h"

// Figure* FactoryMethod( int num ) {
//  Figure* res = nullptr;
//  switch ( num ) {
//    case 0:
//      res = new Circle( );
//      break;
//    case 1:
//      res = new Rectangle( );
//      break;
//    case 2:
//      res = new Trapezium( );
//      break;
//  }
//  return res;
//}

int main( ) {
  Factory factory;

  std::vector< Figure* > fig;
  fig.push_back( factory.MakeCirkle( 10 ) );
  fig.push_back( factory.MakeRect( 10, 10 ) );
  fig.push_back( factory.MakeTrapezium( 10, 10, 10, 10, 10 ) );

  for ( auto el : fig ) {
    std::cout << typeid( *el ).name( ) << std::endl;
    std::cout << "    area = " << el->Area( ) << std::endl;
    std::cout << "perimetr = " << el->Perimeter( ) << std::endl;
  }
}
