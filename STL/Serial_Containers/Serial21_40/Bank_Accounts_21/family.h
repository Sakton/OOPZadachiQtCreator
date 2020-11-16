#ifndef FAMILY_H
#define FAMILY_H
#include <iostream>
#include <string>

class Family
{
 public:
  Family( const std::string& fam = "None" );

  std::string family( ) const;
  void setFamily( const std::string& family );
  friend std::ostream& operator<<( std::ostream& out, const Family& fam );
  friend std::istream& operator>>( std::istream& in, Family& fam );

 private:
  const std::string& validateFamily( const std::string& fam ) const;

 private:
  std::string family_;
};

#endif // FAMILY_H
