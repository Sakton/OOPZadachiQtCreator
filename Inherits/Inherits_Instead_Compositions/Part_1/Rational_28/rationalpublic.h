#ifndef RATIONALPUBLIC_H
#define RATIONALPUBLIC_H
#include "baserational.h"

class RationalPublic : public BaseRational {
 public:
  explicit RationalPublic( int32_t x = 1, int16_t y = 1 );

  RationalPublic& operator+=( const RationalPublic& rt );
  RationalPublic& operator-=( const RationalPublic& rt );
  RationalPublic& operator*=( const RationalPublic& rt );
  RationalPublic& operator/=( const RationalPublic& rt );

  friend RationalPublic operator+( const RationalPublic& rt1,
                                   const RationalPublic& rt2 );
  friend RationalPublic operator-( const RationalPublic& rt1,
                                   const RationalPublic& rt2 );
  friend RationalPublic operator*( const RationalPublic& rt1,
                                   const RationalPublic& rt2 );
  friend RationalPublic operator/( const RationalPublic& rt1,
                                   const RationalPublic& rt2 );

  friend bool operator<( const RationalPublic& rt1, const RationalPublic& rt2 );
  friend bool operator<=( const RationalPublic& rt1,
                          const RationalPublic& rt2 );
  friend bool operator>( const RationalPublic& rt1, const RationalPublic& rt2 );
  friend bool operator>=( const RationalPublic& rt1,
                          const RationalPublic& rt2 );
  friend bool operator==( const RationalPublic& rt1,
                          const RationalPublic& rt2 );
  friend bool operator!=( const RationalPublic& rt1,
                          const RationalPublic& rt2 );
};

#endif // RATIONALPUBLIC_H
