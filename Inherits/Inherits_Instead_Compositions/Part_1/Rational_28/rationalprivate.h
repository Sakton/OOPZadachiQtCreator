#ifndef RATIONALPRIVATE_H
#define RATIONALPRIVATE_H
#include "baserational.h"

class RationalPrivate : BaseRational {
 public:
  explicit RationalPrivate( int32_t x = 1, int16_t y = 1 );

  friend void Display( const RationalPrivate& rp );
  friend std::string ToString( const RationalPrivate& rp );

  RationalPrivate& operator+=( const RationalPrivate& rt );
  RationalPrivate& operator-=( const RationalPrivate& rt );
  RationalPrivate& operator*=( const RationalPrivate& rt );
  RationalPrivate& operator/=( const RationalPrivate& rt );

  friend RationalPrivate operator+( const RationalPrivate& rt1,
                                    const RationalPrivate& rt2 );
  friend RationalPrivate operator-( const RationalPrivate& rt1,
                                    const RationalPrivate& rt2 );
  friend RationalPrivate operator*( const RationalPrivate& rt1,
                                    const RationalPrivate& rt2 );
  friend RationalPrivate operator/( const RationalPrivate& rt1,
                                    const RationalPrivate& rt2 );

  friend bool operator<( const RationalPrivate& rt1,
                         const RationalPrivate& rt2 );
  friend bool operator<=( const RationalPrivate& rt1,
                          const RationalPrivate& rt2 );
  friend bool operator>( const RationalPrivate& rt1,
                         const RationalPrivate& rt2 );
  friend bool operator>=( const RationalPrivate& rt1,
                          const RationalPrivate& rt2 );
  friend bool operator==( const RationalPrivate& rt1,
                          const RationalPrivate& rt2 );
  friend bool operator!=( const RationalPrivate& rt1,
                          const RationalPrivate& rt2 );
};

#endif // RATIONALPRIVATE_H
