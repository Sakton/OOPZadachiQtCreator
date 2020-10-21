#include "goods36b.h"
#include <iostream>

using namespace std;

int main( ) {
  Goods36B gds( "Test1", "20.09.2020", 1, 398.00, 2 );
  gds.Display( );
  gds.AddCount( 2 );
  gds.Display( );

  gds.SetPrice( Money24( 100 ) );
  gds.Display( );

  gds.SubCount( 2 );
  gds.Display( );

  std::cout << "CountDaysInSave = " << gds.CountDaysInSave( "21.10.2020" )
            << std::endl;
  gds.MarkDown( "21.10.2020" );
  gds.Display( );
}
