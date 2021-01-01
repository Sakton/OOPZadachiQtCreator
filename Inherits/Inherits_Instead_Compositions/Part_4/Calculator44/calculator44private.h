#ifndef CALCULATOR44PRIVATE_H
#define CALCULATOR44PRIVATE_H
#include "fraction35.h"
#include "string"

class Calculator44private : private Fraction35B {
 public:
  Fraction35B operator( )( const std::string& expr );

 private:
  std::string Postfix( const std::string& expr );
  Fraction35B Raschet( const std::string& expr );
};

#endif // CALCULATOR44PRIVATE_H
