#ifndef GOODS_50_H
#define GOODS_50_H
#include <string>

#include "money24b.h"

class Goods50 {
public:
  void Init( const std::string& name = "", const std::string& date = "",
	     int32_t id = 0, double price = 0.0, int32_t count = 0 );

  void Display( ) const;
  std::string ToString( ) const;
  // void Read(  );

  double Cost( ) const;

  double Price( ) const;
  void SetPrice( double price );

  int32_t GetCount( ) const;
  void SetCount( const int32_t& value );

  void AddCount( int32_t count );
  void SubCount( int32_t count );

  void Sale( int16_t days );

private:
  std::string name_;
  std::string date_;
  int32_t id_nakladnoy_;
  // double price_;
  Money24B price_;
  int32_t count_;
};

#endif // GOODS_50_H
