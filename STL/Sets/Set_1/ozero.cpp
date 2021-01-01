#include "ozero.h"

#include <ctime>

// IFish *Ozero::getFish( ) {
//  uint8_t rand = std::rand( ) % 8;
//  return getConkreteFish( rand );
//}

// IFish *Ozero::getConkreteFish( uint8_t type ) {
//  switch ( type ) {
//    case 0:
//      return new Okun;
//    case 1:
//      return new Karas;
//    case 2:
//      return new Ersh;
//    case 3:
//      return new Lesch;
//    case 4:
//      return new Schuka;
//    case 5:
//      return new Plotva;
//    case 6:
//      return new Dorado;
//    case 7:
//      return new Zubatka;
//  }
//  return nullptr;
//}

std::shared_ptr< IFish > Ozero::getFish( ) {
  uint8_t rand = std::rand( ) % 8;
  return getConkreteFish( rand );
}

std::shared_ptr< IFish > Ozero::getConkreteFish( uint8_t type ) {
  switch ( type ) {
    case 0:
      return std::make_shared< Okun >( );
    case 1:
      return std::make_shared< Karas >( );
    case 2:
      return std::make_shared< Ersh >( );
    case 3:
      return std::make_shared< Lesch >( );
    case 4:
      return std::make_shared< Schuka >( /*аргументы конструктора*/ );
    case 5:
      return std::make_shared< Plotva >( );
    case 6:
      return std::make_shared< Dorado >( );
    case 7:
      return std::make_shared< Zubatka >( );
  }
  return nullptr;
}
