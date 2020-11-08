#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

static const std::string PATH = "../../stl_part1/Files/";
static constexpr int N = 6;

using type_container = std::vector< int >;
using reference_container = type_container &;
using const_reference_container = const type_container &;

const std::string createFile( const std::string &name_file );
type_container inputFile( const std::string &name_file );
void tasks( reference_container ( *modificator )( reference_container c ) );

// modoficators
reference_container modify1( reference_container c );
reference_container modify2( reference_container c );

int main( ) {
  using modify = reference_container ( * )( reference_container c );
  // change this
  modify modificator = modify2;
  //***
  try {
    tasks( modificator );
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( ) << std::endl;
  } catch ( ... ) {
    std::cerr << "OTHER ERROR" << std::endl;
  }

  return 0;
}

const std::string createFile( const std::string &name_file ) {
  std::ofstream ofile( PATH + name_file );
  if ( !ofile.is_open( ) ) throw std::runtime_error( "NO OPEN FILE" );
  std::srand( std::time( nullptr ) );
  for ( int i = 0; i < N; ++i ) {
    int rand = std::rand( ) % 50;
    if ( !( rand % 3 ) ) rand *= -1;
    ofile << rand << '\n';
  }
  return PATH + name_file;
}

type_container inputFile( const std::string &name_file ) {
  type_container res;
  std::ifstream ifile( name_file );
  if ( !ifile.is_open( ) ) throw std::runtime_error( "ERROR OPEN FILE" );
  int x = 0;
  while ( ifile ) {
    ifile >> std::skipws >> x;
    if ( !ifile.eof( ) )
      res.push_back( x );  // in order not to write the last one twice
  }
  return res;
}

// tasks driver
void tasks( reference_container ( *modificator )( reference_container c ) ) {
  type_container v = inputFile( createFile( "input.txt" ) );
  std::copy( v.begin( ), v.end( ),
             std::ostream_iterator< int >( std::cout, " " ) );
  std::cout << '\n'
            << "***************************************************************"
               "************"
            << std::endl;
  modificator( v );
  std::copy( v.begin( ), v.end( ),
             std::ostream_iterator< int >( std::cout, " " ) );
}

reference_container modify1( reference_container c ) {
  auto max_iterator = std::max_element( c.cbegin( ), c.cend( ) );
  auto factor = std::sqrt( std::abs( ( *max_iterator ) * c.back( ) ) );
  for ( auto &el : c ) el *= factor;
  return c;
}

struct Pred2 {
  bool operator( )( int a ) { return a < 0; }
};

reference_container modify2( reference_container c ) {
  auto el = std::find_if( c.cbegin( ), c.cend( ), Pred2( ) );
  if ( el == c.end( ) ) throw std::runtime_error( "NO NEGATIVE ELEMENT" );
  //  std::cout << "elem < 0 => " << *el << std::endl;
  type_container::const_iterator it = c.cbegin( );
  for ( int i = 0; i < N / 2; ++i )
    ++it;  //??? может как то лучше можно прыгнуть сразу в середину любого
           //контейнера
  //  std::cout << "elem2 n/2 " << *it << std::endl;
  auto polusumma = ( *el + *it ) / 2;
  if ( polusumma == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
  for ( auto &el : c ) el /= polusumma;
  return c;
}
