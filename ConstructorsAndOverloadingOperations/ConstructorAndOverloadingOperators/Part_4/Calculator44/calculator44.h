#ifndef CALCULATOR44_H
#define CALCULATOR44_H
#include "string"

class Calculator44 {
 public:
  double operator( )( const std::string& expr );

 private:
  std::string Postfix( const std::string& expr );
  double Raschet( const std::string& expr );
};
#endif // CALCULATOR44_H
