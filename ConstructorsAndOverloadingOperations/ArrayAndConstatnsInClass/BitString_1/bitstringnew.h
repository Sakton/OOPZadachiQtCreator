#ifndef BITSTRINGNEW_H
#define BITSTRINGNEW_H
#include <string>

class BitstringNew
{
 public:
  using Uch = unsigned char;

  explicit BitstringNew( int sz = 0 );
  explicit BitstringNew( const std::string& bitStr );

  // FIXME: ДЕЙСТВИЕ №1
  Uch& operator[]( int index );
  const Uch& operator[]( int index ) const;
  //*****

  static int getSIZE( );

 private:
  constexpr static int SIZE = 100;
  Uch* bitstr_;
  int count_;
};

#endif // BITSTRINGNEW_H
