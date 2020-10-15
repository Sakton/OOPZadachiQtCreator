#include <iostream>

#include "triangle25.h"

int main( ) {
  /*
  std::cout << TheoremaCos( 4, 3, 117 ) << std::endl;
  std::cout << AnglePoTheoremeCos( 4, 3, 6 ) << std::endl;
  std::cout << ToRadian( 180 ) << std::endl;
  std::cout << ToAngle( 3.14159 ) << std::endl;
  std::cout << TheoremaSinAngle( 6, 117.28, 3 ) << std::endl;
  std::cout << TheoremaSinAngle( 3, 26.38, 6 ) << std::endl;
  std::cout << TheoremaSinAngle( 6, 117.28, 4 ) << std::endl;
  std::cout << TheoremaSinAngle( 4, 36.34, 6 ) << std::endl;

  std::cout << std::sin( ToRadian( 117 ) ) << std::endl;
  std::cout << ToAngle( std::asin( std::sin( ToRadian( 117 ) ) ) ) << std::endl;
  std::cout << std::cos( ToRadian( 117 ) ) << std::endl;
  std::cout << ToAngle( std::acos( std::cos( ToRadian( 170 ) ) ) ) << std::endl;

  double a = 3;
  double b = 3;
  double alfa = 117;
  std::cout << ( std::pow( a, 2 ) + std::pow( b, 2 ) -
                 2 * a * b * std::cos( ToRadian( alfa ) ) )
            << std::endl;
*/
  // Methods demonstration
  // inits
  std::cout << "******* PROGRAMMA TRIANGLE 25 A-A-A ********" << std::endl;
  Triangle25 trA1( 4, 4, 6, Triangle25::TYPE_INITIALISATION::SSS );

  SetA( trA1, 3 );
  Display( trA1 );
  SetA( trA1, 4 );
  Display( trA1 );

  SetB( trA1, 3 );
  Display( trA1 );
  SetB( trA1, 4 );
  Display( trA1 );

  SetC( trA1, 5 );
  Display( trA1 );
  SetC( trA1, 6 );
  Display( trA1 );

  SetAngleA( trA1, 30 );
  Display( trA1 );
  SetAngleA( trA1, 41.41 );
  Display( trA1 );

  SetAngleB( trA1, 30 );
  Display( trA1 );
  SetAngleB( trA1, 41.41 );
  Display( trA1 );

  SetAngleC( trA1, 70 );
  Display( trA1 );
  SetAngleC( trA1, 97.18 );
  Display( trA1 );

  std::cout << "H AB = " << HeightToA( trA1 ) << std::endl;
  std::cout << "H BC = " << HeightToB( trA1 ) << std::endl;
  std::cout << "H AC = " << HeightToC( trA1 ) << std::endl;
  std::cout << "S Tringle = " << Area( trA1 ) << std::endl;
  std::cout << "S Perimeter = " << Perimeter( trA1 ) << std::endl;

  switch ( GetType( trA1 ) ) {
    case Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY:
      std::cout << "PRYAMO_UGOLNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY:
      std::cout << "RAVNO_BEDRENNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY:
      std::cout << "RAVNO_STORONNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::OTHER:
      std::cout << "OTHER" << std::endl;
      break;
  }
  std::cout << std::endl;
  std::cout << std::endl;

  Triangle25 trA2( 3, 90, 4, Triangle25::TYPE_INITIALISATION::SUS );
  Display( trA2 );
  std::cout << "H AB = " << HeightToA( trA2 ) << std::endl;
  std::cout << "H BC = " << HeightToB( trA2 ) << std::endl;
  std::cout << "H AC = " << HeightToC( trA2 ) << std::endl;
  std::cout << "S Tringle = " << Area( trA2 ) << std::endl;
  std::cout << "S Perimeter = " << Perimeter( trA2 ) << std::endl;
  switch ( GetType( trA2 ) ) {
    case Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY:
      std::cout << "PRYAMO_UGOLNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY:
      std::cout << "RAVNO_BEDRENNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY:
      std::cout << "RAVNO_STORONNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::OTHER:
      std::cout << "OTHER" << std::endl;
      break;
  }
  std::cout << std::endl;
  std::cout << std::endl;

  Triangle25 trA3( 10, 90, 10, Triangle25::TYPE_INITIALISATION::SUS );

  Display( trA3 );
  std::cout << "H AB = " << HeightToA( trA3 ) << std::endl;
  std::cout << "H BC = " << HeightToB( trA3 ) << std::endl;
  std::cout << "H AC = " << HeightToC( trA3 ) << std::endl;
  std::cout << "S Tringle = " << Area( trA3 ) << std::endl;
  std::cout << "S Perimeter = " << Perimeter( trA3 ) << std::endl;
  switch ( GetType( trA3 ) ) {
    case Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY:
      std::cout << "PRYAMO_UGOLNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY:
      std::cout << "RAVNO_BEDRENNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY:
      std::cout << "RAVNO_STORONNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::OTHER:
      std::cout << "OTHER" << std::endl;
      break;
  }
  std::cout << std::endl;
  std::cout << std::endl;

  Triangle25 trA4( 10, 50, 10, Triangle25::TYPE_INITIALISATION::SUS );
  Display( trA4 );
  std::cout << "H AB = " << HeightToA( trA4 ) << std::endl;
  std::cout << "H BC = " << HeightToB( trA4 ) << std::endl;
  std::cout << "H AC = " << HeightToC( trA4 ) << std::endl;
  std::cout << "S Tringle = " << Area( trA4 ) << std::endl;
  std::cout << "S Perimeter = " << Perimeter( trA4 ) << std::endl;
  switch ( GetType( trA4 ) ) {
    case Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY:
      std::cout << "PRYAMO_UGOLNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY:
      std::cout << "RAVNO_BEDRENNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY:
      std::cout << "RAVNO_STORONNY" << std::endl;
      break;
    case Triangle25::TYPE_TRIANGLE::OTHER:
      std::cout << "OTHER" << std::endl;
      break;
  }

  // TODO потом добавить демонстрацию на В-В-В она такая же как и на ССС

  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;
  Triangle25 tr( 4, 4, 6, Triangle25::TYPE_INITIALISATION::SSS );
  Display( tr );

  return 0;
}
