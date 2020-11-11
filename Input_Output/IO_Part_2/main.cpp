#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

static const std::string PATH_FILE_ = "../../IO_Part_2/Files/";

static const int32_t N = 5;

void fillFile( const std::string &file_name );
void displayFile( const std::string &file_name );

void wtask01( const std::string &inf, const std::string &ouf );
void wtask02( const std::string &inf, const std::string &ouf );

int main( ) {
  // driver tsks

  fillFile( PATH_FILE_ + "input.txt" );
  displayFile( PATH_FILE_ + "input.txt" );
  wtask01( PATH_FILE_ + "input.txt", PATH_FILE_ + "output.txt" );
  std::wcout << "*************************************" << std::endl;
  displayFile( PATH_FILE_ + "output.txt" );
}

void fillFile( const std::string &file_name ) {
  std::srand( std::time( nullptr ) );
  std::wofstream wof( file_name );
  for ( int i = 0; i < N; ++i ) {
    int rnd = rand( ) % 50;
    if ( rnd % 3 == 0 ) rnd *= -1;
    wof << rnd << wof.widen( '\n' );  // wof.widen - преобразование char в wchar
    // wof << rnd << '\n';
  }
}

void displayFile( const std::string &file_name ) {
  std::wifstream wif( file_name );
  std::wcout << wif.rdbuf( ) << std::endl;
}

void wtask01( const std::string &inf, const std::string &ouf ) {
  std::wifstream wif( inf );
  wif.seekg( -( sizeof( int ) + sizeof( wchar_t ) ), std::ios::end );
  int x = 0;
  wif >> x;
  std::wcout << "x = " << x << std::endl;
  wif.clear( );
  wif.seekg( std::ios::beg );
  std::wofstream wof( ouf );
  std::transform( std::istream_iterator< int, wchar_t >( wif ), std::istream_iterator< int, wchar_t >( ),
                  std::ostream_iterator< int, wchar_t >( wof, L"\n" ), [ & ]( int el ) { return el + x; } );
}

void wtask02( const std::string &inf, const std::string &ouf ) {}
