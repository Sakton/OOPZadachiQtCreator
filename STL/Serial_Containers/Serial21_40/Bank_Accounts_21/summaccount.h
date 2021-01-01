#ifndef SUMMACCOUNT_H
#define SUMMACCOUNT_H
#include <iostream>

class SummAccount
{
 public:
  using value_type = double;
  SummAccount( const value_type &summa = value_type( ) );

  value_type summa( ) const;
  void setSumma( const value_type &summa );

 private:
  const value_type &validateSumma( const value_type &summ ) const;

 private:
  value_type summa_;
};

std::ostream &operator<<( std::ostream &out, const SummAccount &ak );

#endif // SUMMACCOUNT_H
