#ifndef DATE29_H
#define DATE29_H
#include <string>

class Date29 {
  constexpr static int monats[ 12 ] { 31, 28, 31, 30, 31, 30,
                                      31, 31, 30, 31, 30, 31 };

 public:
  Date29( int16_t y = 1970, int16_t m = 1, int16_t d = 1 );
  Date29( const std::string& dt );
  Date29( const Date29& dt );
  void Read( );
  void Display( ) const;
  std::string ToString( ) const;

  Date29 AddDay( int days ) const;
  Date29 SubDay( int days ) const;
  int16_t Interval( const Date29& other ) const;
  bool IsVisokosny( ) const;

  int16_t Year( ) const;
  void setYear( const int16_t& y );
  int16_t Month( ) const;
  void setMonth( const int16_t& m );
  int16_t Day( ) const;
  void setDay( const int16_t& d );

 private:
  int16_t y_;
  int16_t m_;
  int16_t d_;
};

#endif // DATE29_H
