#ifndef FABRIQUECULTURE_H
#define FABRIQUECULTURE_H
#include <memory>

#include "abstractculture.h"

class FabriqueCulture
{
 public:
  using tp = std::shared_ptr< AbstractCulture >;
  //**gets
  tp getKartofel( ) const;
  tp getUkrop( ) const;
  tp getMorkov( ) const;
  tp getGorokh( ) const;
  tp getKapusta( ) const;
  tp getRedis( ) const;

  tp random( ) const;

 private:
  static const int CNT = 6;
};

#endif // FABRIQUECULTURE_H
