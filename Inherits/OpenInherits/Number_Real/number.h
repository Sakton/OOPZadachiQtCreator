#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>

class Number1 {
 public:
  explicit Number1( double x = 0 );
  Number1 &operator-=( const Number1 &num );
  Number1 &operator*=( const Number1 &num );
  std::ostream &Show( std::ostream &out ) const;

  double X( ) const;

 private:
  double x_;
};

#endif // NUMBER_H
