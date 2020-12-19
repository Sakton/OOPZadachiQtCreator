#include <iostream>
#include <string>
#include <tuple>

int main()
{
  std::string s;
  auto x = std::make_tuple( /*std::ref( s )*/ s );
  auto y = std::tie( s );  //создает кортеж ссылок
  std::get< 0 >( x ) = "aaaa";
  std::cout << s << std::endl;
  std::get< 0 >( y ) = "bbbb";
  std::cout << s << std::endl;

  std::tuple< int, float, std::string > t( 77, 1.1, "blabla" );
  int i;
  std::string ss;
  std::tie( i, std::ignore, ss ) = t;
  std::cout << i << " " << ss;
}
