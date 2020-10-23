#include <iostream>

#include "bill.h"

int main( ) {
  Bill bl( "MyName", "123123456", 0.3, 5, Bill::Time30( 12, 36, 24 ),
           Bill::Time30( 12, 36, 57 ) );
  bl.Display( );
}
