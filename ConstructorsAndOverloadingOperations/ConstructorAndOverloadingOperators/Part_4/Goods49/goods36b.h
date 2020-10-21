#ifndef GOODS36B_H
#define GOODS36B_H
#include <string>

#include "date29.h"

class Goods36B {
 public:
  Goods36B( const std::string& name = "",
            const std::string& date = "01.01.1970", int32_t id = 0,
            double price = 0.0, int32_t count = 0 );

  void Display( ) const;
  std::string ToString( ) const;

  double Cost( ) const;

  double Price( ) const;
  void SetPrice( double price );

  int32_t GetCount( ) const;
  void SetCount( const int32_t& value );

  void AddCount( int32_t count );
  void SubCount( int32_t count );

  int CountDaysInSave( const std::string& dt ) const;

 private:
  std::string name_;
  // std::string date_;
  Date29 date_;
  int32_t id_nakladnoy_;
  double price_;
  int32_t count_;
};

#endif // GOODS36B_H
