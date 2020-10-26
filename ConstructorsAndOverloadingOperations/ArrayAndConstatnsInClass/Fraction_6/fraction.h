#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <vector>

/*
Как то не корректно написано задание
Дибильно
*/

/*
Храним в массиве числа по основанию 100, так как unsigned char [0 .. 255]
тоесть число 999999999999999 будет хранится как 9,99,99,99,99,99,99,99 в массиве
тогда доступны алгоритмы фюрера и тд.

Проблема решения считывания цифр -> "108" -> "1","08" -> 1; 8
Решение по основанию 100 не годится

Произведение чисел: вылет за пределы (переполнение) ... нужно основание 10000;
Проблема
*/

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

  friend std::ostream &operator<<( std::ostream &out, const Fraction &fr1 );

  int16_t getSizeCel( ) const;
  int16_t getSizeDrobn( ) const;

 private:
  std::pair< std::string, std::string > parseString(
      const std::string &str ) const;

  void readChislitel( const std::string &str );
  void readZnamenatel( const std::string &str );

  void debugPrint( unsigned char arr[], int16_t sz );

 private:
  static constexpr int MAXSIZE = 100;
  static constexpr int OSNOVA = 100;
  unsigned char *cel_;
  unsigned char *drobn_;
  int16_t sizeCel_;
  int16_t sizeDrobn_;
};

#endif // FRACTION_H
