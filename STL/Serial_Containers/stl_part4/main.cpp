#include <fstream>
#include <iostream>

#include "modificators_class.h"

static const std::string PATH = "../../stl_part4/Files/";

struct Generator {
  type operator( )( ) {
    type rnd = std::rand( ) % 50;
    if ( rnd % 3 == 0 ) rnd *= -1;
    return rnd;
  }
};

void save_file( const std::string &name_file, const_reference_container cont );

// driver tasks
void tasks( ) {
  std::srand( std::time( nullptr ) );
  type_container cnt;
  std::generate_n( std::back_inserter( cnt ), N, Generator( ) );
  std::copy( cnt.cbegin( ), cnt.cend( ),
             std::ostream_iterator< type >( std::cout, " " ) );
  //****************************************************
  Modificators *modificator = new Modify13( cnt );
  //****************************************************
  std::for_each( cnt.begin( ), cnt.end( ),
                 [ & ]( type &elem ) { modificator->operator( )( elem ); } );
  std::cout << '\n' << "**********************************" << std::endl;
  std::copy( cnt.cbegin( ), cnt.cend( ),
             std::ostream_iterator< type >( std::cout, " " ) );
  save_file( PATH + "output.txt", cnt );
}

int main( ) {
  try {
    tasks( );
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( ) << std::endl;
  }
}

void save_file( const std::string &name_file, const_reference_container cont ) {
  std::ofstream ofile( name_file );
  if ( !ofile.is_open( ) ) throw std::runtime_error( "ERROR OPEN SAVE FILE" );
  std::copy( cont.begin( ), cont.end( ),
             std::ostream_iterator< type >( ofile, "\n" ) );
}
