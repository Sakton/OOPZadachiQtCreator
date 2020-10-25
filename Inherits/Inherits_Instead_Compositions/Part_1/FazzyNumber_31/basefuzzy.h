#ifndef BASEFUZZY_H
#define BASEFUZZY_H
#include <string>

class BaseFuzzy
{
 public:
  BaseFuzzy( double e1, double x, double e2 );
  friend void Display( const BaseFuzzy& fn );
  friend std::string ToString( const BaseFuzzy& fn );

 protected:
  double e1_;
  double x_;
  double e2_;
};

#endif // BASEFUZZY_H
