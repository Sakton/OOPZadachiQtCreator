#ifndef OZERO_H
#define OZERO_H
#include <memory>
#include "ifish.h"

class Ozero {
 public:
  std::shared_ptr< IFish > getFish( );
  std::shared_ptr< IFish > getConkreteFish( uint8_t type );
};

#endif // OZERO_H
