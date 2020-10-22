#ifndef PAYMENT39B_H
#define PAYMENT39B_H
#include <string>

//TODO доделать

class Payment39B {
 public:
  Payment39B( const std::string& name, double oklad, int16_t year, double proc,
              double nalog, int16_t work_day, int16_t days_in_mon );
  void Display( );
  // void Read( );
  std::string ToString( );

  double Nachislleno( );
  double Udergano( );
  double HandOut( );
  int StagYear( );

 private:
  std::string name_;
  double oklad_;
  int16_t year_;
  double procent_nadbavka_;
  double nalog_;
  int16_t work_day_;
  int16_t days_monats_;
  //  double nachisleno_;
  //  double udergano_;
};

#endif // PAYMENT39B_H
