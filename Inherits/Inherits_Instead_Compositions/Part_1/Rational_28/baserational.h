#ifndef BASERATIONAL_H
#define BASERATIONAL_H
#include <string>

class BaseRational {
 public:
  BaseRational( int32_t x = 1, int16_t y = 1 );

  friend std::string ToString( const BaseRational& rt );
  friend void Display( const BaseRational& rt );

  int32_t chis( ) const;
  void setChis( const int32_t& chis );

  int32_t znam( ) const;
  void setZnam( const int32_t& znam );

 protected:
  void reduce( );

 private:
  int32_t chis_;
  int32_t znam_;
};

#endif // BASERATIONAL_H
