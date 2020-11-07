#ifndef FRACTIONBASE_H
#define FRACTIONBASE_H
#include <string>

class FractionBase
{
 public:
  FractionBase( int64_t w = 0, int16_t f = 0 );
  friend void display( const FractionBase &fr );
  friend std::string toString( const FractionBase &fr );

  int64_t getWhole( ) const;
  void setWhole( const int64_t &whole );

  int16_t getFractional( ) const;
  void setFractional( const int16_t &fractional );

  bool getNegative( ) const;
  void setNegative( bool value );

 private:
  int64_t whole_;
  int16_t fractional_;
  bool negative;
};

#endif // FRACTIONBASE_H
