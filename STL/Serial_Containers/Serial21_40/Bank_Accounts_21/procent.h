#ifndef PROCENT_H
#define PROCENT_H
#include <iostream>

class Procent
{
 public:
  using value_type = double;
  explicit Procent( value_type proc = 5.0 );

  value_type validProcent( value_type proc ) const;
  friend std::ostream &operator<<( std::ostream &out, const Procent &proc );
  friend std::istream &operator>>( std::istream &in, const Procent &proc );

 private:
  value_type procent_;
};

#endif // PROCENT_H
