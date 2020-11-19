#ifndef OZERO_H
#define OZERO_H
#include <memory>

#include "ifish.h"

class Ozero {
 public:
  IFish* getFish( );
  IFish* getConkreteFish( uint8_t type );
};

#endif // OZERO_H
