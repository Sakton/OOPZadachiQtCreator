#ifndef MONEYPUBLIC_H
#define MONEYPUBLIC_H
#include "basemoney.h"

class MoneyPublic : public BaseMoney {
 public:
  explicit MoneyPublic( double sum = 0.0 );

  friend MoneyPublic operator+( const MoneyPublic& b1, const MoneyPublic& b2 );
  friend MoneyPublic operator-( const MoneyPublic& b1, const MoneyPublic& b2 );
  friend MoneyPublic operator*( const MoneyPublic& b1, const MoneyPublic& b2 );
  friend MoneyPublic operator/( const MoneyPublic& b1, const MoneyPublic& b2 );
  friend MoneyPublic operator/( const MoneyPublic& b1, double x );

  friend bool operator<( const MoneyPublic& b1, const MoneyPublic& b2 );
  friend bool operator<=( const MoneyPublic& b1, const MoneyPublic& b2 );
  friend bool operator>( const MoneyPublic& b1, const MoneyPublic& b2 );
  friend bool operator>=( const MoneyPublic& b1, const MoneyPublic& b2 );
  friend bool operator==( const MoneyPublic& b1, const MoneyPublic& b2 );
  friend bool operator!=( const MoneyPublic& b1, const MoneyPublic& b2 );
};

#endif // MONEYPUBLIC_H
