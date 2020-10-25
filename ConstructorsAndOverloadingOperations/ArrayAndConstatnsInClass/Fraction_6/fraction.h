#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <vector>

// FIXME НЕ СДЕЛАНО
//не знаковое
class Fraction {
 public:
  explicit Fraction( const std::string &str );
  explicit Fraction( long double x );
  ~Fraction( );
  Fraction( const Fraction &fr );
  Fraction( Fraction &&fr ) noexcept;

  Fraction &operator=( const Fraction &fr );
  Fraction &operator=( Fraction &&fr ) noexcept;

  unsigned char &operator[]( int16_t index );
  const unsigned char &operator[]( int16_t index ) const;

  Fraction &operator+=( const Fraction &fr );
  Fraction &operator-=( const Fraction &fr );
  Fraction &operator*=( const Fraction &fr );
  // Fraction &operator/=( const Fraction &fr );

  friend Fraction operator+( const Fraction &fr1, const Fraction &fr2 );
  friend Fraction operator+( const Fraction &fr1, long double dx );
  friend Fraction operator+( long double dx, const Fraction &fr1 );
  friend Fraction operator-( const Fraction &fr1, const Fraction &fr2 );
  friend Fraction operator-( const Fraction &fr1, long double dx );
  friend Fraction operator-( long double dx, const Fraction &fr1 );
  friend Fraction operator*( const Fraction &fr1, const Fraction &fr2 );
  friend Fraction operator*( const Fraction &fr1, long double dx );
  friend Fraction operator*( long double dx, const Fraction &fr1 );
  //  friend Fraction operator/( const Fraction &fr1, const Fraction &fr2 );
  //  friend Fraction operator/( const Fraction &fr1, long double dx );
  //  friend Fraction operator/( long double dx, const Fraction &fr1 );

  friend bool operator<( long double dx, const Fraction &fr1 );
  friend bool operator<=( long double dx, const Fraction &fr1 );
  friend bool operator>( long double dx, const Fraction &fr1 );
  friend bool operator>=( long double dx, const Fraction &fr1 );
  friend bool operator==( long double dx, const Fraction &fr1 );
  friend bool operator!=( long double dx, const Fraction &fr1 );

  int16_t getSizeCel( ) const;
  int16_t getSizeDrobn( ) const;

 private:
  std::pair< std::string, std::string > parseString(
      const std::string &str ) const;

  void debugPrint( unsigned char arr[], int16_t sz );

 private:
  static constexpr int MAXSIZE = 100;
  static constexpr int OSNOVA = 256;
  unsigned char *cel_;
  unsigned char *drobn_;
  int16_t sizeCel_;
  int16_t sizeDrobn_;
};

#endif // FRACTION_H
