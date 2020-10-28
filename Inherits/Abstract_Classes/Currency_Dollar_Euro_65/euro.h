#ifndef EURO_H
#define EURO_H
#include "currency.h"

class Euro : public Currency {
 public:
  explicit Euro( double sum );

  // Currency interface
 public:
  double change( ) const override;
  void display( ) const override;

 private:
  double sum_;
};

#endif // EURO_H
