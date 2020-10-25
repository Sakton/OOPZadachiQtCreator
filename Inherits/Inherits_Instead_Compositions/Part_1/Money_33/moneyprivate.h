#ifndef MONEYPRIVATE_H
#define MONEYPRIVATE_H
#include "basemoney.h"

class MoneyPrivate : BaseMoney {
 public:
  explicit MoneyPrivate( double sum = 0.0 );

  friend void Display( const MoneyPrivate& mp );
  explicit operator std::string( ) const;

  friend MoneyPrivate operator+( const MoneyPrivate& b1,
                                 const MoneyPrivate& b2 );
  friend MoneyPrivate operator-( const MoneyPrivate& b1,
                                 const MoneyPrivate& b2 );
  friend MoneyPrivate operator*( const MoneyPrivate& b1,
                                 const MoneyPrivate& b2 );
  friend MoneyPrivate operator/( const MoneyPrivate& b1,
                                 const MoneyPrivate& b2 );
  friend MoneyPrivate operator/( const MoneyPrivate& b1, double x );

  friend bool operator<( const MoneyPrivate& b1, const MoneyPrivate& b2 );
  friend bool operator<=( const MoneyPrivate& b1, const MoneyPrivate& b2 );
  friend bool operator>( const MoneyPrivate& b1, const MoneyPrivate& b2 );
  friend bool operator>=( const MoneyPrivate& b1, const MoneyPrivate& b2 );
  friend bool operator==( const MoneyPrivate& b1, const MoneyPrivate& b2 );
  friend bool operator!=( const MoneyPrivate& b1, const MoneyPrivate& b2 );
};

#endif // MONEYPRIVATE_H
