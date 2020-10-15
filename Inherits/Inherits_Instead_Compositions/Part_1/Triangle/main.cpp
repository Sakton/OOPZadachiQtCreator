#include <iostream>

#include "triangle.h"
#include "triangleprivate.h"

int main()
{
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
  std::cout << "******* PROGRAMMA TRIANGLE 25 PUBLIC INHERITS ********"
            << std::endl;
  Triangle trA1( 4, 4, 6, Triangle::TYPE_INITIALISATION::SSS );

  //тут работает базовый класс
  trA1.SetA( 3 );
  trA1.Display( );
  trA1.SetA( 4 );
  trA1.Display( );

  trA1.SetB( 3 );
  trA1.Display( );
  trA1.SetB( 4 );
  trA1.Display( );

  trA1.SetC( 5 );
  trA1.Display( );
  trA1.SetC( 6 );
  trA1.Display( );

  trA1.SetAngleA( 30 );
  trA1.Display( );
  trA1.SetAngleA( 41.41 );
  trA1.Display( );

  trA1.SetAngleB( 30 );
  trA1.Display( );
  trA1.SetAngleB( 41.41 );
  trA1.Display( );

  trA1.SetAngleC( 70 );
  trA1.Display( );
  trA1.SetAngleC( 97.18 );
  trA1.Display( );

  std::cout << "H AB = " << trA1.HeightToA( ) << std::endl;
  std::cout << "H BC = " << trA1.HeightToB( ) << std::endl;
  std::cout << "H AC = " << trA1.HeightToC( ) << std::endl;
  std::cout << "S Tringle = " << trA1.Area( ) << std::endl;
  std::cout << "S Perimeter = " << trA1.Perimeter( ) << std::endl;

  std::cout << "******* PROGRAMMA TRIANGLE 25 PRIVATE INHERITS ********"
            << std::endl;

  TrianglePrivate prTr1( 4, 4, 6, Triangle::TYPE_INITIALISATION::SSS );
  prTr1.SetA( 3 );
  prTr1.Display( );
  prTr1.SetA( 4 );
  prTr1.Display( );

  prTr1.SetB( 3 );
  prTr1.Display( );
  prTr1.SetB( 4 );
  prTr1.Display( );

  prTr1.SetC( 5 );
  prTr1.Display( );
  prTr1.SetC( 6 );
  prTr1.Display( );

  prTr1.SetAngleA( 30 );
  prTr1.Display( );
  prTr1.SetAngleA( 41.41 );
  prTr1.Display( );

  prTr1.SetAngleB( 30 );
  prTr1.Display( );
  prTr1.SetAngleB( 41.41 );
  prTr1.Display( );

  prTr1.SetAngleC( 70 );
  prTr1.Display( );
  prTr1.SetAngleC( 97.18 );
  prTr1.Display( );

  std::cout << "H AB = " << prTr1.HeightToA( ) << std::endl;
  std::cout << "H BC = " << prTr1.HeightToB( ) << std::endl;
  std::cout << "H AC = " << prTr1.HeightToC( ) << std::endl;
  std::cout << "S Tringle = " << prTr1.Area( ) << std::endl;
  std::cout << "S Perimeter = " << prTr1.Perimeter( ) << std::endl;

  TriangleBase *trb1 = &trA1;
  // TriangleBase *trb2 = &prTr1;  //отношение содержит!!!!!

  //  switch ( GetType( trA1 ) ) {
  //    case Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY:
  //      std::cout << "PRYAMO_UGOLNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY:
  //      std::cout << "RAVNO_BEDRENNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY:
  //      std::cout << "RAVNO_STORONNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::OTHER:
  //      std::cout << "OTHER" << std::endl;
  //      break;
  //  }
  //  std::cout << std::endl;
  //  std::cout << std::endl;

  //  Triangle25 trA2( 3, 90, 4, Triangle25::TYPE_INITIALISATION::SUS );
  //  Display( trA2 );
  //  std::cout << "H AB = " << HeightToA( trA2 ) << std::endl;
  //  std::cout << "H BC = " << HeightToB( trA2 ) << std::endl;
  //  std::cout << "H AC = " << HeightToC( trA2 ) << std::endl;
  //  std::cout << "S Tringle = " << Area( trA2 ) << std::endl;
  //  std::cout << "S Perimeter = " << Perimeter( trA2 ) << std::endl;
  //  switch ( GetType( trA2 ) ) {
  //    case Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY:
  //      std::cout << "PRYAMO_UGOLNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY:
  //      std::cout << "RAVNO_BEDRENNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY:
  //      std::cout << "RAVNO_STORONNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::OTHER:
  //      std::cout << "OTHER" << std::endl;
  //      break;
  //  }
  //  std::cout << std::endl;
  //  std::cout << std::endl;

  //  Triangle25 trA3( 10, 90, 10, Triangle25::TYPE_INITIALISATION::SUS );

  //  Display( trA3 );
  //  std::cout << "H AB = " << HeightToA( trA3 ) << std::endl;
  //  std::cout << "H BC = " << HeightToB( trA3 ) << std::endl;
  //  std::cout << "H AC = " << HeightToC( trA3 ) << std::endl;
  //  std::cout << "S Tringle = " << Area( trA3 ) << std::endl;
  //  std::cout << "S Perimeter = " << Perimeter( trA3 ) << std::endl;
  //  switch ( GetType( trA3 ) ) {
  //    case Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY:
  //      std::cout << "PRYAMO_UGOLNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY:
  //      std::cout << "RAVNO_BEDRENNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY:
  //      std::cout << "RAVNO_STORONNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::OTHER:
  //      std::cout << "OTHER" << std::endl;
  //      break;
  //  }
  //  std::cout << std::endl;
  //  std::cout << std::endl;

  //  Triangle25 trA4( 10, 50, 10, Triangle25::TYPE_INITIALISATION::SUS );
  //  Display( trA4 );
  //  std::cout << "H AB = " << HeightToA( trA4 ) << std::endl;
  //  std::cout << "H BC = " << HeightToB( trA4 ) << std::endl;
  //  std::cout << "H AC = " << HeightToC( trA4 ) << std::endl;
  //  std::cout << "S Tringle = " << Area( trA4 ) << std::endl;
  //  std::cout << "S Perimeter = " << Perimeter( trA4 ) << std::endl;
  //  switch ( GetType( trA4 ) ) {
  //    case Triangle25::TYPE_TRIANGLE::PRYAMO_UGOLNY:
  //      std::cout << "PRYAMO_UGOLNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::RAVNO_BEDRENNY:
  //      std::cout << "RAVNO_BEDRENNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::RAVNO_STORONNY:
  //      std::cout << "RAVNO_STORONNY" << std::endl;
  //      break;
  //    case Triangle25::TYPE_TRIANGLE::OTHER:
  //      std::cout << "OTHER" << std::endl;
  //      break;
  //  }

  //  // TODO потом добавить демонстрацию на В-В-В она такая же как и на ССС

  //  std::cout <<
  //  "---------------------------------------------------------------"
  //               "--------"
  //            << std::endl;
  //  Triangle25 tr( 4, 4, 6, Triangle25::TYPE_INITIALISATION::SSS );
  //  Display( tr );
}
