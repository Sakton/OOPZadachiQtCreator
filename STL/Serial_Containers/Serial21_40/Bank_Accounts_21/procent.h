#ifndef PROCENT_H
#define PROCENT_H
#include <iostream>

class Procent
{
 public:
  using value_type = double;
  explicit Procent( value_type proc = 5.0 );

  value_type validProcent( value_type proc ) const;

  value_type procent( ) const;

 private:
  value_type procent_;
};

std::ostream &operator<<( std::ostream &out, const Procent &proc );

#endif // PROCENT_H
