#include <iostream>

#include "real.h"

//#include "number.h"

//итерационная формула герона нахождения корня 2 степени
// double root2( double num ) {
//  double root = num / 2;
//  double eps = 0.01;
//  int iter = 0;
//  while ( root - num / root > eps ) {
//    iter++;
//    root = /*0.5 * */ ( root + num / root ) / 2;
//    printf( "Iteration: %d : root = %f\n", iter, root );
//  }
//  printf( "root = %f\n", root );
//  return root;
//}

int main( ) {
  //  Number1 num( 200 );
  //  num.Show( std::cout );

  //  std::cout << root2( 10 ) << std::endl;

  Real a( 10.0 );

  std::cout << a.PowPi( 2 ) << std::endl;
  std::cout << a.Sqrt( 2 ) << std::endl;
  //  std::cout << std::pow( 1.02332, 125 ) << std::endl;
  //  std::cout << std::pow( 10, 1.25 ) << std::endl;
  //  std::cout << std::pow( 10, 0.4 ) << std::endl;
  std::cout << a.Pow( 2.25, 3 ) << std::endl;
  std::cout << a.Pow( 3.14, 2 ) << std::endl;
}
