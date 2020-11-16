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
  friend std::ostream &operator<<( std::ostream &out, const SummAccount &ak );
  friend std::istream &operator>>( std::istream &in, SummAccount &ak );

 private:
  const value_type &validateSumma( const value_type &summ ) const;

 private:
  value_type summa_;
};

#endif // SUMMACCOUNT_H
