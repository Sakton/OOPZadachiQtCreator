#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

static const std::string PATH_FILE_ = "../../Files/";
static const int32_t N = 5;

// utilities
void fillFile( const std::string& name_f ) {
  std::ofstream file( name_f );
  if ( file.is_open( ) ) {
    for ( int i = 0; i < N; ++i ) {
      int x = rand( ) % 50;
      x *= ( x % 2 ) ? -1 : 1;
      file << x << '\n';
    }
  }
  file.close( );
}

void displayFile( const std::string& name_f ) {
  std::ifstream i_file( name_f );
  std::cout << i_file.rdbuf( );
  i_file.close( );
}

// tasks
void tasks1( const std::string& in_f, const std::string& out_f );
void tasks2( const std::string& in_f, const std::string& out_f );
void tasks3( const std::string& in_f, const std::string& out_f );
void tasks4( const std::string& in_f, const std::string& out_f );
void tasks5( const std::string& in_f, const std::string& out_f );
void tasks6( const std::string& in_f, const std::string& out_f );

// ********************** main
int main( ) {
  // types and constants
  std::string file_in = PATH_FILE_ + "1.txt";
  std::string file_out = PATH_FILE_ + "2.txt";
  using task = void ( * )( const std::string&, const std::string& );
  task foo = tasks5;
  std::srand( std::time( nullptr ) );
  // *********  driver *********
  fillFile( file_in );
  std::cout << "---------original data------------" << std::endl;
  displayFile( file_in );  // original
  foo( file_in, file_out );
  std::cout << "----------result data-------------" << std::endl;
  displayFile( file_out );  // result
}
// ************************

void tasks1( const std::string& in_f, const std::string& out_f ) {
  std::ifstream file_in( in_f );
  int32_t end_x = 0;
  // (x << '\n') = (int + char)
  file_in.seekg( -( sizeof( int ) + sizeof( char ) ), std::ios::end );
  file_in >> end_x;
  std::cout << "end_x = " << end_x << std::endl;
  int32_t tmp = 0;
  file_in.seekg( std::ios::beg );
  std::ofstream file_out( out_f );
  while ( file_in ) {
    file_in >> std::skipws >> tmp;
    if ( file_in ) file_out << ( tmp * end_x ) << '\n';
  }
  file_in.close( );
  file_out.close( );
}

void tasks2( const std::string& in_f, const std::string& out_f ) {
  std::ifstream ifile( in_f );
  // find first negative and 50-th
  int32_t neg = 0;
  int32_t fifth = 0;
  int count = -1;
  while ( neg >= 0 ) {
    ++count;
    ifile >> std::skipws >> neg;
    if ( count == 50 ) {  //
      fifth = neg;
    }
  }
  // if negative was found up to fiftieth (50) elements
  if ( count < 50 ) {
    ifile.seekg( ( sizeof( int ) + sizeof( char ) ) * ( count ),
                 std::ios::beg );
    while ( count < 50 ) {
      ifile >> std::skipws >> fifth;
      ++count;
    }
  }
  //  std::cout << "first negtive  = " << neg << std::endl;
  //  std::cout << "50 el  = " << fifth << std::endl;
  //**********
  std::ofstream ofile( out_f );
  ifile.seekg( std::ios::beg );
  int32_t polusumma = ( neg + fifth ) / 2;
  std::cout << "polusumma = " << polusumma << std::endl;

  while ( ifile ) {
    ifile >> std::skipws >> neg;
    if ( !ifile.eof( ) ) ofile << neg / polusumma << '\n';
  }
  ifile.close( );
  ofile.close( );
}

void tasks3( const std::string& in_f, const std::string& out_f ) {
  std::ifstream ifile( in_f );
  // find max
  int max = 0;
  int tmp = 0;
  while ( ifile ) {
    ifile >> std::skipws >> tmp;
    if ( max < tmp ) max = tmp;
  }
  ifile.clear( );  // clear state stream
  ifile.seekg( std::ios::beg );
  std::ofstream ofile( out_f );
  if ( !ofile.is_open( ) ) {
    throw std::runtime_error( "error" );
  }
  while ( ifile ) {
    ifile >> std::skipws >> tmp;
    if ( !ifile.eof( ) ) ofile << ( tmp - max ) << '\n';
  }
  ifile.close( );
  ofile.close( );
}

void tasks4( const std::string& in_f, const std::string& out_f ) {
  std::ifstream ifile( in_f );
  // find min
  int32_t min = std::numeric_limits< int32_t >::max( );
  int32_t t = 0;
  while ( ifile ) {
    ifile >> std::skipws >> t;
    if ( t < min ) min = t;
  }
  ifile.clear( );  // clear eof (bad) state -> good state
  ifile.seekg( std::ios::beg );
  std::ofstream ofile( out_f );
  while ( ifile ) {
    ifile >> std::skipws >> t;
    if ( !ifile.eof( ) ) ofile << t * min << '\n';
  }

  ifile.close( );
  ofile.close( );
}

void tasks5( const std::string& in_f, const std::string& out_f ) {
  std::ifstream ifile( in_f );
  int32_t middle = 0;
  int32_t t = 0;
  for ( ; ifile; ) {
    ifile >> std::skipws >> t;
    middle += t;
  }
  ifile.clear( );
  ifile.seekg( std::ios::beg );
  std::cout << "middle = " << middle / N << std::endl;
  std::ofstream ofile( out_f );
  for ( ; ifile; ) {
    ifile >> std::skipws >> t;
    if ( !ifile.eof( ) ) {
      if ( std::abs( t ) % 2 ) {
        ofile << ( t * N ) / middle;
      } else {
        ofile << t;
      }
      ofile << '\n';
    }
  }
  ifile.close( );
  ofile.close( );
}

void tasks6( const std::string& in_f, const std::string& out_f ) {}
