#ifndef SET_H
#define SET_H
#include "bitstring37b.h"

//не более чем 64 элемента
//- эти элементы степени двойки

class Set
{
 public:
  explicit Set( const Bitstring37B& set );
  void Display( ) const;
  std::string ToString( ) const;

  Set& operator+=( const Set& oth );  //сложение множеств
  Set& operator-=( const Set& oth );  //вычитание
  Set& operator*=( const Set& oth );  //пересечение

  friend Set operator+( const Set& set1, const Set& set2 );
  friend Set operator-( const Set& set1, const Set& set2 );
  friend Set operator*( const Set& set1, const Set& set2 );

  int Count( );

 private:
  Bitstring37B set_;
};

#endif // SET_H
