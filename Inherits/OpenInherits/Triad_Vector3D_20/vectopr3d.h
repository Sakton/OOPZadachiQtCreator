#ifndef VECTOPR3D_H
#define VECTOPR3D_H
#include "triad.h"

class Vectopr3D : public Triad {
 public:
  explicit Vectopr3D( int f = 0, int s = 0, int t = 0 );

  Vectopr3D &operator+=( const Vectopr3D &ot );
  Vectopr3D &operator*=( const Vectopr3D &ot );

  friend Vectopr3D operator+( const Vectopr3D &ot1, const Vectopr3D &ot2 );
  friend Vectopr3D operator*( const Vectopr3D &ot1, const Vectopr3D &ot2 );
};

#endif // VECTOPR3D_H
