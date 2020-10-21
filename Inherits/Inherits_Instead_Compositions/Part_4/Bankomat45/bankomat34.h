#ifndef BANKOMAT34_H
#define BANKOMAT34_H
#include <string>

#include "money33.h"

class Bankomat34 : public Money33 {
 public:
  Bankomat34( int32_t id = 0, int32_t min = 0, int32_t max = 0,
              double cash = 0 );
  void Display( ) const;
  operator double( ) const;
  explicit operator std::string( ) const;

  void AddCash( double money );
  void SubCash( double summ );

 private:
  int32_t id_;
  int32_t min_;
  int32_t max_;
  // Money33 cash_;
};

#endif // BANKOMAT34_H
