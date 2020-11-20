#include "fabriqueculture.h"
// WARNING http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r22-use-make_shared-to-make-shared_ptrs

FabriqueCulture::tp FabriqueCulture::getKartofel( ) const { return std::make_shared< Kartofel >( /* arg ctor */ ); }
FabriqueCulture::tp FabriqueCulture::getUkrop( ) const { return std::make_shared< Ukrop >( ); }
FabriqueCulture::tp FabriqueCulture::getMorkov( ) const { return std::make_shared< Morkov >( ); }
FabriqueCulture::tp FabriqueCulture::getGorokh( ) const { return std::make_shared< Gorokh >( ); }
FabriqueCulture::tp FabriqueCulture::getKapusta( ) const { return std::make_shared< Kapusta >( ); }
FabriqueCulture::tp FabriqueCulture::getRedis( ) const { return std::make_shared< Redis >( ); }

FabriqueCulture::tp FabriqueCulture::random( ) const {
  auto rnd = std::rand( ) % 6;
  switch ( rnd ) {
    case 0:
      return getKartofel( );
    case 1:
      return getUkrop( );
    case 2:
      return getMorkov( );
    case 3:
      return getGorokh( );
    case 4:
      return getKapusta( );
    case 5:
      return getRedis( );
    default:
      return nullptr;
  }
}
