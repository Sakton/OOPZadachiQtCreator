#ifndef NUMBERACCOUNT_H
#define NUMBERACCOUNT_H
#include <fstream>
#include <string>

#include "abstract_save_open_class.h"

class NumberAccount {
 public:
  enum { SIZE_NUMBER = 5 };
  explicit NumberAccount( const std::string& num = "00000" );
  std::string number( ) const;
  void setNumber( const std::string& number );

  friend std::ostream& operator<<( std::ostream& out, const NumberAccount& na );
  friend std::istream& operator>>( std::istream& in, NumberAccount& na );

 private:
  std::string validateNumber( const std::string& str ) const;

 private:
  std::string number_;
};

#endif // NUMBERACCOUNT_H
