#include <fstream>
#include <iostream>
#include <set>
#include <string>

const std::string PATH = "../../Set_44/Files/inpt.txt";

void printPovtory( const std::string &str );
void printGlasnyeInOneWord( const std::string &str );

int main( ) {
  std::ifstream fin( PATH );
  std::string str( ( std::istreambuf_iterator< char >( fin ) ), std::istreambuf_iterator< char >( ) );
  fin.close( );
  std::cout << str;
  printPovtory( str );
  std::cout << "\n\n************************************\n" << std::endl;
  printGlasnyeInOneWord( str );
}

void printPovtory( const std::string &str ) {
  std::set< char > loc;
  for ( const auto &el : str ) {
    if ( loc.find( el ) != loc.end( ) ) {
      std::cout << el << ' ';
    } else {
      loc.insert( el );
    }
  }
}

void printGlasnyeInOneWord( const std::string &str ) {
  std::multiset< char > loc;
  for ( const auto &ch : str ) {
    if ( ( ( ch != 'a' ) && ( ch != 'e' ) && ( ch != 'i' ) && ( ch != 'o' ) && ( ch != 'u' ) && ( ch != 'y' ) && ( ch != ' ' ) &&
           ( ch != '.' ) ) ) {
      loc.insert( ch );
    }
    if ( ch == ' ' || ch == '.' ) {
      std::copy( loc.cbegin( ), loc.cend( ), std::ostream_iterator< char >( std::cout, " " ) );
      std::cout << std::endl;
      loc.clear( );
    }
  }
}
