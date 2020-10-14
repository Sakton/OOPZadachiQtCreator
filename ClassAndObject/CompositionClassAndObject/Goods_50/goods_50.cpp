#include "goods_50.h"

#include <iostream>
#include <sstream>

void Goods50::Init( const std::string& name, const std::string& date,
		    int32_t id, double price, int32_t count ) {
  name_ = name;
  date_ = date;
  id_nakladnoy_ = id;
  price_.Init( price );
  count_ = count;
}

void Goods50::Display( ) const { std::cout << ToString( ) << std::endl; }

std::string Goods50::ToString( ) const {
  std::stringstream ss;
  ss << Cost( );
  return ss.str( );
}

double Goods50::Cost( ) const { return price_.GetSumm( ) * count_; }

double Goods50::Price( ) const { return price_.GetSumm( ); }

void Goods50::SetPrice( double price ) {
  if ( price < 0 ) {
    std::cout << "ERROR DATA PRICE";
    exit( 1 );
  }
  price_.Init( price );
}

int32_t Goods50::GetCount( ) const { return count_; }

void Goods50::SetCount( const int32_t& value ) {
  if ( value < 0 ) {
    std::cout << "ERROR DATA COUNT";
    exit( 1 );
  }
  if ( value != count_ ) count_ = value;
}

void Goods50::AddCount( int32_t count ) {
  if ( count < 0 ) {
    std::cout << "ERROR DATA COUNT ADD";
    exit( 1 );
  }
  count_ += count;
}

void Goods50::SubCount( int32_t count ) {
  if ( count < 0 || count > count_ ) {
    std::cout << "ERROR DATA COUNT ADD";
    exit( 1 );
  }
  count_ -= count;
}

void Goods50::Sale( int16_t days ) {
  double pr = price_.GetSumm( );

  for ( int i = 0; i < days; ++i ) {
    pr -= 0.01 * pr;
  }
  price_.Init( pr );
}
