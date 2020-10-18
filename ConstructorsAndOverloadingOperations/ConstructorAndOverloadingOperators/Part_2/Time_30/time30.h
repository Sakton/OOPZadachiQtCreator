#ifndef TIME30_H
#define TIME30_H
#include <string>

class Time30 {
 public:
  explicit Time30( int16_t h = 0, int16_t m = 0, int16_t s = 0 );
  explicit Time30( const std::string& dt );
  explicit Time30( int32_t sec );
  Time30( const Time30& dt );
  friend void Display( const Time30& dt );
  operator std::string( ) const;

  friend int32_t operator-( const Time30& t1, const Time30& t2 );
  friend Time30 operator+( const Time30& other, int32_t sec );
  friend Time30 operator+( int32_t sec, const Time30& other );

  friend Time30 operator-( const Time30& other, int32_t sec );

  friend bool operator==( const Time30& t1, const Time30& t2 );
  friend bool operator<( const Time30& t1, const Time30& t2 );
  friend bool operator>( const Time30& t1, const Time30& t2 );

  friend int32_t ToSecond( const Time30& t1 );
  friend int32_t ToMinut( const Time30& t1 );

  Time30 ToTime( int32_t sec );

 private:
  static constexpr int SEC_IN_DAY = 86400;
  int16_t h_;
  int16_t m_;
  int16_t s_;
};

#endif // TIME30_H
