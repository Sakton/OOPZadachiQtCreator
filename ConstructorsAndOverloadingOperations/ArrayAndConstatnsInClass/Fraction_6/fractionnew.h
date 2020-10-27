#ifndef FRACTIONNEW_H
#define FRACTIONNEW_H
#include <string>

/*
unsicned char  - как число с основанием 256
в рамках этих чисел
*/

class FractionNew {
 public:
  explicit FractionNew( int szCel, int szDrob );
  ~FractionNew( );
  FractionNew( const FractionNew &fr );
  FractionNew( FractionNew &&fr ) noexcept;

  FractionNew &operator=( const FractionNew &fr );
  FractionNew &operator=( FractionNew &&fr ) noexcept;

  unsigned char &operator[]( int16_t index );
  const unsigned char &operator[]( int16_t index ) const;

  FractionNew &operator+=( const FractionNew &fr );
  FractionNew &operator-=( const FractionNew &fr );
  FractionNew &operator*=( const FractionNew &fr );

  friend FractionNew operator+( const FractionNew &fr1,
                                const FractionNew &fr2 );
  friend FractionNew operator+( const FractionNew &fr1, long double dx );
  friend FractionNew operator+( long double dx, const FractionNew &fr1 );
  friend FractionNew operator-( const FractionNew &fr1,
                                const FractionNew &fr2 );
  friend FractionNew operator-( const FractionNew &fr1, long double dx );
  friend FractionNew operator-( long double dx, const FractionNew &fr1 );
  friend FractionNew operator*( const FractionNew &fr1,
                                const FractionNew &fr2 );
  friend FractionNew operator*( const FractionNew &fr1, long double dx );
  friend FractionNew operator*( long double dx, const FractionNew &fr1 );

  friend bool operator<( long double dx, const FractionNew &fr1 );
  friend bool operator<=( long double dx, const FractionNew &fr1 );
  friend bool operator>( long double dx, const FractionNew &fr1 );
  friend bool operator>=( long double dx, const FractionNew &fr1 );
  friend bool operator==( long double dx, const FractionNew &fr1 );
  friend bool operator!=( long double dx, const FractionNew &fr1 );

  friend std::ostream &operator<<( std::ostream &out, const FractionNew &fr );

  int16_t getSizeCel( ) const;
  int16_t getSizeDrobn( ) const;

 private:
  void debugPrint( unsigned char arr[], int16_t sz );
  int countNums( int64_t cel );
  void fillArray( unsigned char *arr, int64_t x );
  bool IndexIsValid( int index );

 private:
  static constexpr int MAXSIZE = 100;
  static constexpr int OSNOVA = 10;
  unsigned char *cel_;
  unsigned char *drobn_;
  int16_t sizeCel_;
  int16_t sizeDrobn_;
};

#endif // FRACTIONNEW_H
