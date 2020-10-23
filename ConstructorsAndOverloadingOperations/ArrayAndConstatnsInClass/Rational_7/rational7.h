#ifndef RATIONAL5_H
#define RATIONAL5_H
#include <string>

using UChar = unsigned char;

class Rational7 {
 public:
  explicit Rational7( int n );
  explicit Rational7( const std::string &drob );  //строкой через разделитель /
  Rational7( const Rational7 &rvalue );
  Rational7( Rational7 &&tmpVal );
  ~Rational7( );
  Rational7 &operator=( const Rational7 &rvalue );
  Rational7 &operator=( Rational7 &&tmpVal );

  // private:
  std::pair< UChar *, int > Summa_2_Arrays( UChar arrOne[], std::size_t sizeOne,
                                            UChar arrTwo[],
                                            std::size_t sizeTwo );
  std::pair< UChar *, int > Subtraction_2_Arrays( UChar arrOne[],
                                                  std::size_t sizeOne,
                                                  UChar arrTwo[],
                                                  std::size_t sizeTwo );
  std::pair< UChar *, int > Multiple_2_Arrays( unsigned char arrOne[],
                                               std::size_t sizeOne,
                                               UChar arrTwo[],
                                               std::size_t sizeTwo );

  void Trim( UChar *&arr, std::size_t &size );
  void TrimN( UChar *&arr, std::size_t &size );

  // private:
  static const int MAX;
  UChar *chislitel_;
  UChar *znamenatel_;
  std::size_t chislitel_size_;
  std::size_t znamenatel_size_;
};

#endif // RATIONAL5_H
