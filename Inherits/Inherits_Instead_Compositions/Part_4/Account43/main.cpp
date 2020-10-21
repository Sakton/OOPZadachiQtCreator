#include <iostream>

#include "account32.h"
#include "accountprivate.h"

int main( ) {
  setlocale( LC_ALL, "ru" );

  Account32 acc( "Petrov", "1234252345", 6.9, 123598.59, "01.01.2019" );
  acc.Display( );
  std::cout << acc.ToChislitelnoe( ) << std::endl;

  acc -= 98;
  acc.Display( );
  acc -= 0.59;
  acc.Display( );

  acc.AddingProcentToDayCount( Date29( "01.01.2020" ) );
  acc.Display( );

  std::cout << "XXXXXXXXXXXXXXXXXXXXAcc43XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
            << std::endl;

  AccountPrivate pacc( "Petrov", "1234252345", 6.9, 123598.59, "01.01.2019" );
  pacc.Display( );
  std::cout << pacc.ToChislitelnoe( ) << std::endl;

  pacc -= 98;
  pacc.Display( );
  pacc -= 0.59;
  pacc.Display( );

  pacc.AddingProcentToDayCount( Date29( "01.01.2020" ) );
  pacc.Display( );
}
