#ifndef CALCULATOR47_H
#define CALCULATOR47_H
#include <string>

#include "fraction35.h"

class Calculator47
{
 public:
  Fraction35Long operator( )( const std::string& ex );

  // private:
  std::string Parse( const std::string& ex );
  Fraction35Long Calculate( const std::string& ex );
};

#endif // CALCULATOR47_H
