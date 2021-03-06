#ifndef DECIMALNEW_H
#define DECIMALNEW_H
#include <cstdint>
#include <string>

class DecimalNew
{
 public:
  using Uch = unsigned char;

  explicit DecimalNew( int n = 0 );
  explicit DecimalNew( int64_t num, bool );
  explicit DecimalNew( const std::string &str );
  ~DecimalNew( );
  DecimalNew( const DecimalNew &dm );
  DecimalNew &operator=( const DecimalNew &dm );

  // NUMBER 1
  Uch &operator[]( int index );
  const Uch &operator[]( int index ) const;
  //***

  DecimalNew &operator+=( const DecimalNew &dm );
  DecimalNew &operator-=( const DecimalNew &dm );
  DecimalNew &operator*=( const DecimalNew &dm );
  //  DecimalNew &operator/=( const DecimalNew &dm );

  //сравнение: или по длине, или по первой большей цифре

  friend std::ostream &operator<<( std::ostream &out, const DecimalNew &dm );

  static int getSize( );

 private:
  int lenNumber( int64_t num );

 private:
  static const int SIZE = 100;
  static const int OSNOVA = 10;

  Uch *number_;
  int count_;
};

#endif // DECIMALNEW_H
