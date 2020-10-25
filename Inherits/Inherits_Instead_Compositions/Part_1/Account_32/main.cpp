
#include <clocale>
#include <iostream>

#include "accountprivate.h"
#include "accountpublic.h"

int main( ) {
  setlocale( LC_ALL, "ru" );

  std::cout << "************ ACCOUNT PUBLIC **************" << std::endl;
  AccountPublic acc( "Петров", "1234252345", 6.9, 123598.59 );
  Display( acc );
  std::cout << acc.ToChislitelnoe( ) << std::endl;

  std::cout << "************ ACCOUNT PRIVATE **************" << std::endl;

  AccountPrivate pacc( "Петров", "1234252345", 6.9, 123598.59 );
  Display( pacc );
  std::cout << pacc.ToChislitelnoe( ) << std::endl;
}
