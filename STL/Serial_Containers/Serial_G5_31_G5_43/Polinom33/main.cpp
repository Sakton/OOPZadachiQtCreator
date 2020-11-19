#include <iomanip>
#include <iostream>

#include "polinom33vec.h"

int main( ) {
  Polinom33Vec pv( 3, 3 );
  std::cout << pv << std::endl;
  double coeff[] { 10, 9, 8 };
  Polinom33Vec pol( coeff, coeff + 3 );
  std::cout << pol << std::endl;
  Polinom33Vec t1 = pol + pv;
  std::cout << t1 << std::endl;
  Polinom33Vec t2 = pol + 10;
  std::cout << t2 << std::endl;
  Polinom33Vec t3 = pol * 3;
  std::cout << t3 << std::endl;
  Polinom33Vec t4 = 4 * pol;
  std::cout << t4 << std::endl;
}
