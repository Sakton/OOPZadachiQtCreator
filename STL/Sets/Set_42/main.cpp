#include <fstream>
#include <iostream>
#include <set>

static constexpr const char* PATH_F = "../../Set_42/File/text.txt";

int main( ) {
  std::set< char > gl;
  std::set< char > sogl;
  std::set< char > one_word;

  std::ifstream ifile( PATH_F );
  char ch = ' ';

  while ( ifile.get( ch ) && ch != '.' ) {
    // std::cout << ch;
    ch = tolower( ch );
    if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' ) {
      // std::cout << ch;
      gl.insert( ch );
    } else if ( isalpha( ch ) && !( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' ) ) {
      sogl.insert( ch );
    }

    if ( ch != ' ' ) {
      one_word.insert( ch );
    } else {
      std::copy( one_word.begin( ), one_word.end( ), std::ostream_iterator< char >( std::cout ) );
      std::cout << std::endl;
      one_word.clear( );
    }
  }

  std::copy( gl.begin( ), gl.end( ), std::ostream_iterator< char >( std::cout, " " ) );
  std::cout << "\n\n" << std::endl;
  std::copy( sogl.begin( ), sogl.end( ), std::ostream_iterator< char >( std::cout, " " ) );

  ifile.close( );
}
