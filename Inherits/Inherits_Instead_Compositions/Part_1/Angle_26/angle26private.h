#ifndef ANGLE26PRIVATE_H
#define ANGLE26PRIVATE_H
#include "angle26base.h"

class Angle26private : Angle26Base {
 public:
  explicit Angle26private( int16_t g = 0, int16_t m = 0 );
  explicit Angle26private( double angl );

  // create public interface from private base class
  using Angle26Base::Normalise;
  using Angle26Base::Sinus;
  //***

  friend void Display( const Angle26private& an );
  friend std::string ToString( const Angle26private& ang );

  friend Angle26private operator+( const Angle26private& an1,
                                   const Angle26private& an2 );
  friend Angle26private operator-( const Angle26private& an1,
                                   const Angle26private& an2 );

  friend bool operator<( const Angle26private& an1, const Angle26private& an2 );
  friend bool operator<=( const Angle26private& an1,
                          const Angle26private& an2 );
  friend bool operator>( const Angle26private& an1, const Angle26private& an2 );
  friend bool operator>=( const Angle26private& an1,
                          const Angle26private& an2 );
  friend bool operator==( const Angle26private& an1,
                          const Angle26private& an2 );
  friend bool operator!=( const Angle26private& an1,
                          const Angle26private& an2 );
};

#endif // ANGLE26PRIVATE_H
