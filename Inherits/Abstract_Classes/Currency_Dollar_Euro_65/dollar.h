#ifndef DOLLAR_H
#define DOLLAR_H
#include "currency.h"

class Dollar : public Currency {
 public:
  explicit Dollar( double sum );

  // Currency interface
 public:
  double change( ) const override;
  void display( ) const override;

 private:
  double sum_;
};

#endif // DOLLAR_H
