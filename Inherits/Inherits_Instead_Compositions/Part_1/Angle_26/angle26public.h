#ifndef ANGLE26PUBLIC_H
#define ANGLE26PUBLIC_H
#include "angle26base.h"

class Angle26public : public Angle26Base {
 public:
  explicit Angle26public( int16_t g = 0, int16_t m = 0 );
  explicit Angle26public( double angl );

  friend Angle26public operator+( const Angle26public& an1,
                                  const Angle26public& an2 );
  friend Angle26public operator-( const Angle26public& an1,
                                  const Angle26public& an2 );

  friend bool operator<( const Angle26public& an1, const Angle26public& an2 );
  friend bool operator<=( const Angle26public& an1, const Angle26public& an2 );
  friend bool operator>( const Angle26public& an1, const Angle26public& an2 );
  friend bool operator>=( const Angle26public& an1, const Angle26public& an2 );
  friend bool operator==( const Angle26public& an1, const Angle26public& an2 );
  friend bool operator!=( const Angle26public& an1, const Angle26public& an2 );
};

#endif // ANGLE26PUBLIC_H
