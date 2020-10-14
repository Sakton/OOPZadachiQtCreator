#include <iostream>

class Data2 {
  struct Pair {
    Pair( );
    Pair( double f, double s );
    Pair( const Pair& oth );

    double first;
    double second;
  };

 public:
  Data2( double a, double b );
  friend void Read( );
  friend void Display( );

  double Power( );

 private:
  Pair data_;
};

Data2 make_data2( double a, double b );

#pragma pack( push, 1 )
struct Pair {
  double first;
  double second;
};
#pragma pack( pop )

int main( ) {
  std::cout << "************* PROGRAMMA PAIR_2 **************" << std::endl;
  std::cout << "1: Sizes no pragma: " << sizeof( Data2 )
            << "  with pragma: " << sizeof( Pair ) << std::endl;

  // 1. Init
  Data2 a;
  a.Init( 3.0, 3 );
  a.Display( );
  std::cout << std::endl;
  std::cout << "a MyMethod = " << a.Power( ) << std::endl;

  // 2. Read
  Data2 b;
  b.Read( );
  b.Display( );
  std::cout << std::endl;
  std::cout << "b MyMethod = " << b.Power( ) << std::endl;

  // 3. Make
  Data2 c = make_data2( 4.0, 4 );
  c.Display( );
  std::cout << std::endl;
  std::cout << "c MyMethod = " << c.Power( ) << std::endl;

  Data2 d = make_data2( 4.0, -4 );
  c.Display( );
  std::cout << std::endl;
  std::cout << "d MyMethod = " << d.Power( ) << std::endl;

  // 4. Arrays
  Data2 ar[ 10 ];
  for ( int i = 0; i < 10; ++i ) {
    ar[ i ].Init( i + 1, i + 1 );
  }
  for ( int i = 0; i < 10; ++i ) {
    std::cout << i << "  ";
    ar[ i ].Display( );
    std::cout << "[] MyMethod = " << ar[ i ].Power( ) << std::endl << std::endl;
  }

  return 0;
}

void Data2::Init( double a, double b ) {
  //проверок a, b не требуется
  data_.first = a;
  data_.second = b;
}

void Data2::Read( ) {
  double a = 0;
  double b = 0;
  std::cout << "Enter num" << std::endl;
  std::cin >> a;
  std::cout << "Enter stepen" << std::endl;
  std::cin >> b;
  // ... проверки a и b ...
  Init( a, b );
}

void Data2::Display( ) {
  std::cout << "Display "
            << "f: " << data_.first << " :: s: " << data_.second;
}

double Data2::Power( ) { return std::pow( data_.first, data_.second ); }

Data2 make_data2( double a, double b ) {
  Data2 t;
  t.Init( a, b );
  return t;
}
