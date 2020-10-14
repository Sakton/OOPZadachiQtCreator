#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>

class Number
{
 public:
  virtual ~Number( ) {}
  virtual Number& operator+=( const Number& oth ) = 0;
  virtual Number& operator-=( const Number& oth ) = 0;
  virtual Number& operator*=( const Number& oth ) = 0;
  virtual Number& operator/=( const Number& oth ) = 0;
};

#endif // NUMBER_H
