#ifndef BITSTRINGNEW_H
#define BITSTRINGNEW_H
#include <string>

class BitstringNew
{
 public:
  using Uch = unsigned char;

  explicit BitstringNew( int sz = 0 );
  explicit BitstringNew( const std::string& bitStr );
  explicit BitstringNew( int64_t num, bool );
  ~BitstringNew( );
  //  BitstringNew( const BitstringNew& bs );
  //  BitstringNew( BitstringNew&& bs ) noexcept;

  //  BitstringNew& operator=( const BitstringNew& bs );
  //  BitstringNew& operator=( BitstringNew&& bs );

  // FIXME: ДЕЙСТВИЕ №1
  Uch& operator[]( int index );
  const Uch& operator[]( int index ) const;
  //*****
  BitstringNew& operator<<( int n );
  BitstringNew& operator>>( int n );
  BitstringNew& operator|( const BitstringNew& bs );
  BitstringNew& operator&( const BitstringNew& bs );
  BitstringNew& operator^( const BitstringNew& bs );
  BitstringNew& operator~( );

  friend std::ostream& operator<<( std::ostream& out, const BitstringNew& bs );

  static int getSIZE( );
  int getCount( ) const;

 private:
  std::string parseStringToBit( int64_t num );

 private:
  constexpr static int SIZE = 100;
  Uch* bitstr_;
  int count_;
};

#endif // BITSTRINGNEW_H
