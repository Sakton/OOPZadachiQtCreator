#include "goods36b.h"
#include <iostream>
#include <sstream>

Goods36B::Goods36B( const std::string &name, const std::string &date,
                    int32_t id, double price, int32_t count )
    : name_ { name },
      date_ { date },
      id_nakladnoy_ { id },
      price_ { price },
      count_ { count } {}

void Display( const Goods36B &gd ) { std::cout << ToString( gd ) << std::endl; }

std::string ToString( const Goods36B &gd ) {
  std::stringstream ss;
  ss << Cost( gd );
  return ss.str( );
}

double Cost( const Goods36B &gd ) { return gd.price_ * gd.count_; }

double Price( const Goods36B &gd ) { return gd.price_; }

void SetPrice( Goods36B &gd, double price ) {
  if ( price < 0 ) {
    std::cout << "ERROR DATA PRICE";
    exit( 1 );
  }
  if ( price != gd.price_ ) gd.price_ = price;
}

int32_t GetCount( const Goods36B &gd ) { return gd.count_; }

void SetCount( Goods36B &gd, const int32_t &value ) {
  if ( value < 0 ) {
    std::cout << "ERROR DATA COUNT";
    exit( 1 );
  }
  if ( value != gd.count_ ) gd.count_ = value;
}

void AddCount( Goods36B &gd, int32_t count ) {
  if ( count < 0 ) {
    std::cout << "ERROR DATA COUNT ADD";
    exit( 1 );
  }
  gd.count_ += count;
}

void SubCount( Goods36B &gd, int32_t count ) {
  if ( count < 0 || count > gd.count_ ) {
    std::cout << "ERROR DATA COUNT ADD";
    exit( 1 );
  }
  gd.count_ -= count;
}
