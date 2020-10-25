#include "moneypublic.h"

#include <cmath>

MoneyPublic::MoneyPublic( double sum ) : BaseMoney( sum ) {}

MoneyPublic operator+( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return MoneyPublic( static_cast< double >( b1 ) +
                      static_cast< double >( b2 ) );
}

MoneyPublic operator-( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return MoneyPublic( static_cast< double >( b1 ) -
                      static_cast< double >( b2 ) );
}
MoneyPublic operator*( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return MoneyPublic( static_cast< double >( b1 ) *
                      static_cast< double >( b2 ) );
}
MoneyPublic operator/( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return MoneyPublic( static_cast< double >( b1 ) /
                      static_cast< double >( b2 ) );
}
MoneyPublic operator/( const MoneyPublic& b1, double x ) {
  return MoneyPublic( static_cast< double >( b1 ) / x );
}

bool operator<( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return static_cast< double >( b1 ) < static_cast< double >( b2 );
}
bool operator<=( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return ( b1 == b2 ) || ( b1 < b2 );
}
bool operator>( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return !( b1 <= b2 );
}
bool operator>=( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return ( b1 > b2 ) || ( b1 == b2 );
}
bool operator==( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return ( std::fabs( static_cast< double >( b1 ) -
                      static_cast< double >( b2 ) ) ) < 1e-3;
}
bool operator!=( const MoneyPublic& b1, const MoneyPublic& b2 ) {
  return !( b1 == b2 );
}
