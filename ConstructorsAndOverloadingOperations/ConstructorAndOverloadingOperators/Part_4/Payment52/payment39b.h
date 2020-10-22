#ifndef PAYMENT39B_H
#define PAYMENT39B_H
#include <string>

#include "date29.h"

class Payment39B {
 public:
  Payment39B( const std::string &name, double oklad,
              const std::string &date_start, double proc, int16_t work_day,
              int16_t days_in_mon );
  void Display( );
  // void Read( );
  std::string ToString( );

  double Nachislleno( );
  double Udergano( );
  double HandOut( );
  int StagYear( const std::string &cur_date );

 private:
  std::string name_;
  double oklad_;
  Date29 date_start_;
  // int16_t year_start_;
  double procent_nadbavka_;
  int16_t work_day_;
  int16_t days_monats_;
};

#endif // PAYMENT39B_H
