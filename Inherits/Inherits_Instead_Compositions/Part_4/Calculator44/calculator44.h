#ifndef CALCULATOR44_H
#define CALCULATOR44_H
#include "fraction35.h"
#include "string"

class Calculator44 : public Fraction35B {
 public:
  Fraction35B operator( )( const std::string& expr );

 private:
  std::string Postfix( const std::string& expr );
  Fraction35B Raschet( const std::string& expr );
};
#endif // CALCULATOR44_H
