#ifndef BASETIME_H
#define BASETIME_H
#include <cstdint>
#include <string>

class BaseTime
{
 public:
  explicit BaseTime( int16_t h = 0, int16_t m = 0, int16_t s = 0 );
  explicit BaseTime( const std::string& dt );
  explicit BaseTime( int32_t sec );
  friend void Display( const BaseTime& dt );
  friend std::string ToString( const BaseTime& dt );

  BaseTime ToTime( int32_t sec ) const;
  int32_t ToSecond( ) const;
  int32_t ToMinut( ) const;

 protected:
  static constexpr int SEC_IN_DAY = 86400;

 private:
  int16_t h_;
  int16_t m_;
  int16_t s_;
};

#endif // BASETIME_H
