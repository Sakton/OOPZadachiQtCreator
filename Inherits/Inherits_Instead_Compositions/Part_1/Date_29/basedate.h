#ifndef BASEDATE_H
#define BASEDATE_H
#include <string>

class BaseDate
{
 public:
  BaseDate( int16_t y, int16_t m, int16_t d );
  BaseDate( const std::string& dt );
  BaseDate( const BaseDate& dt );
  friend void Display( const BaseDate& dt );
  friend std::string ToString( const BaseDate& dt );

  int16_t Year( ) const;
  void setYear( const int16_t& y );
  int16_t Month( ) const;
  void setMonth( const int16_t& m );
  int16_t Day( ) const;
  void setDay( const int16_t& d );

 protected:
  constexpr static int monats[ 12 ] { 31, 28, 31, 30, 31, 30,
                                      31, 31, 30, 31, 30, 31 };

 private:
  int16_t y_;
  int16_t m_;
  int16_t d_;
};

#endif // BASEDATE_H
