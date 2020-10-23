#ifndef RATIONAL5_H
#define RATIONAL5_H
#include <string>

class Rational7 {
 public:
  explicit Rational7( int n );
  explicit Rational7( const std::string &drob );  //строкой через разделитель /
  //  Rational7( const Rational7 &rvalue );
  //  Rational7( Rational7 &&tmpVal );
  ~Rational7( );
  //  Rational7 &operator=( const Rational7 &rvalue );
  //  Rational7 &operator=( Rational7 &&tmpVal );

 private:
  static const int MAX;
  int *chislitel_;
  int *znamenatel_;
};

#endif // RATIONAL5_H
