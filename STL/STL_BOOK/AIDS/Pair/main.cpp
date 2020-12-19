#include <functional>
#include <iostream>
#include <tuple>
#include <typeinfo>
#include <utility>

class Foo {
 public:
  Foo( std::tuple< int, float > ) { std::cout << "Foo::Foo(tuple)" << std::endl; }
  template < typename... Args >
  Foo( Args... args ) {
    std::cout << "Foo::Foo(args...)" << std::endl;
  }
};

int main( ) {
  int a = 1;
  int b = 2;
  std::tuple< int, int, int > tpl( a, b, 100 );
  std::tuple< int, int, int > tpl1( a, b, 100 );

  using ppp = std::pair< int, const char* >;
  ppp p1( a, "aaaaa" );
  std::pair< int, int > p2( 3, 4 );
  // std::pair< int, int > p3( std::piecewise_construct, tpl, tpl1 );

  std::cout << p1.first << "  " << p1.second << std::endl;
  std::cout << std::get< 0 >( p2 ) << "  " << std::get< 1 >( p2 ) << std::endl;

  std::cout << "std::tuple_size = " << std::tuple_size< ppp >::value << std::endl;
  std::cout << "std::tuple_size = " << typeid( std::tuple_element< 0, ppp >::type ).name( ) << std::endl;
  std::cout << "std::tuple_size = " << typeid( std::tuple_element< 1, ppp >::type ).name( ) << std::endl;

  std::tuple< int, float > t( 1, 2.22 );
  std::pair< int, Foo > pfoo( 42, t );
  std::pair< int, Foo > pfoo2( std::piecewise_construct, std::make_tuple( 42 ), t );

  int x = 0;
  // auto pp = std::make_pair( std::ref( x ), std::ref( x ) );
  // auto pp = std::make_pair( x, x );
  std::pair< int&, int& > pp( x, x );  //а можно просто ссылки
  pp.first++;
  pp.second++;
  std::cout << "x = " << x << std::endl;
}
