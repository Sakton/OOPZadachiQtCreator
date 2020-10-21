#include "goods36b.h"
#include <iostream>
#include <sstream>

Goods36B::Goods36B( const std::string &name, const std::string &date,
                    int32_t id, double price, int32_t count )
    : name_ { name },
      date_( date ),
      id_nakladnoy_ { id },
      price_( price ),
      count_ { count } {}

void Goods36B::Display( ) const { std::cout << ToString( ) << std::endl; }

std::string Goods36B::ToString( ) const {
  std::stringstream ss;
  ss << Cost( );
  return ss.str( );
}

double Goods36B::Cost( ) const {
  return static_cast< double >( price_ ) * count_;
}

Money24 Goods36B::Price( ) const { return price_; }

void Goods36B::SetPrice( const Money24 &price ) {
  if ( price < Money24( 0 ) ) {
    std::cout << "ERROR DATA PRICE";
    exit( 1 );
  }
  if ( price != price_ ) price_ = price;
}

int32_t Goods36B::GetCount( ) const { return count_; }

void Goods36B::SetCount( const int32_t &value ) {
  if ( value < 0 ) {
    std::cout << "ERROR DATA COUNT";
    exit( 1 );
  }
  if ( value != count_ ) count_ = value;
}

void Goods36B::AddCount( int32_t count ) {
  if ( count < 0 ) {
    std::cout << "ERROR DATA COUNT ADD";
    exit( 1 );
  }
  count_ += count;
}

void Goods36B::SubCount( int32_t count ) {
  if ( count < 0 || count > count_ ) {
    std::cout << "ERROR DATA COUNT ADD";
    exit( 1 );
  }
  count_ -= count;
}

int Goods36B::CountDaysInSave( const std::string &dt ) const {
  return date_.Interval( Date29( dt ) );
}

void Goods36B::MarkDown( const std::string &dt ) {
  int days = date_.Interval( Date29( dt ) );
  for ( int i = 0; i < days; ++i ) {
    price_ -= price_ * 0.01;
  }
}
