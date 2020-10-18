#include <iostream>

#include "fraction35.h"

using namespace std;

int main( ) {
  std::cout << "***********fraction35 *************\n";
  Fraction35B fr1( -1, 0 );
  Display( fr1 );

  Fraction35B fr2( 1, 9998 );

  // std::cout << std::boolalpha << fr1.Less( fr2 );

  Fraction35B fr3;
  fr3 = fr1 + fr2;
  Display( fr3 );

  Fraction35B fr4;
  fr4 = fr1 - fr2;
  Display( fr4 );

  //  Fraction35B fr5( 1, 2345 );
  //  Display( fr5 );
  //  fr5.MulDesyatki( 10 ).Display( );
  //  fr5.MulDesyatki( 100 ).Display( );
  //  fr5.MulDesyatki( 1000 ).Display( );
  //  fr5.MulDesyatki( 10000 ).Display( );
  //  fr5.MulDesyatki( 100000 ).Display( );
  //  fr5.MulDesyatki( 1000000 ).Display( );

  //  Fraction35B fr6;
  //  fr6.Init( 1, 1111 );
  //  fr6.Display( );
  //  fr6.MulOneNumber( 0 ).Display( );
  //  fr6.MulOneNumber( 1 ).Display( );
  //  fr6.MulOneNumber( 2 ).Display( );
  //  fr6.MulOneNumber( 3 ).Display( );
  //  fr6.MulOneNumber( 4 ).Display( );
  //  fr6.MulOneNumber( 5 ).Display( );
  //  fr6.MulOneNumber( 6 ).Display( );
  //  fr6.MulOneNumber( 7 ).Display( );
  //  fr6.MulOneNumber( 8 ).Display( );
  //  fr6.MulOneNumber( 9 ).Display( );

  Fraction35B fr7( 5555, 5555 );
  Fraction35B fr8( 2222, 2222 );

  // fr7.OneDivFrac( fr8 ).Display( );

  // std::cout << ( 1 / 2222.2222 );

  Display( fr7 / fr8 );
}
