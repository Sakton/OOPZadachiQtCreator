#include "moneyprivate.h"

#include <cmath>
#include <iostream>

MoneyPrivate::MoneyPrivate( double sum ) : BaseMoney( sum ) {}

MoneyPrivate::operator std::string( ) const {
  return static_cast< const BaseMoney& >( *this ).operator std::string( );
}

void Display( const MoneyPrivate& mp ) {
  std::cout << static_cast< std::string >( mp ) << std::endl;
}

MoneyPrivate operator+( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return MoneyPrivate( static_cast< double >( b1 ) +
                       static_cast< double >( b2 ) );
}

MoneyPrivate operator-( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return MoneyPrivate( static_cast< double >( b1 ) -
                       static_cast< double >( b2 ) );
}
MoneyPrivate operator*( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return MoneyPrivate( static_cast< double >( b1 ) *
                       static_cast< double >( b2 ) );
}
MoneyPrivate operator/( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return MoneyPrivate( static_cast< double >( b1 ) /
                       static_cast< double >( b2 ) );
}
MoneyPrivate operator/( const MoneyPrivate& b1, double x ) {
  return MoneyPrivate( static_cast< double >( b1 ) / x );
}

bool operator<( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return static_cast< double >( b1 ) < static_cast< double >( b2 );
}
bool operator<=( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return ( b1 == b2 ) || ( b1 < b2 );
}
bool operator>( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return !( b1 <= b2 );
}
bool operator>=( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return ( b1 > b2 ) || ( b1 == b2 );
}
bool operator==( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return ( std::fabs( static_cast< double >( b1 ) -
                      static_cast< double >( b2 ) ) ) < 1e-3;
}
bool operator!=( const MoneyPrivate& b1, const MoneyPrivate& b2 ) {
  return !( b1 == b2 );
}
