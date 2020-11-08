#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

// static const std::string PATH_FILE_ = "../../Files/";
static const std::string PATH_FILE_ = "../Input_Output/Files/";
static const int32_t N = 5;

// utilities
void fillFile( const std::string& name_f ) {
  std::ofstream file( name_f );
  if ( !file.is_open( ) ) throw std::runtime_error( "NO OPEN FILE" );
  for ( int i = 0; i < N; ++i ) {
    int x = rand( ) % 50;
    x *= ( x % 2 ) ? -1 : 1;
    file << x << '\n';
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
void tasks7( const std::string& in_f, const std::string& out_f );
void tasks8( const std::string& in_f, const std::string& out_f );
void tasks9( const std::string& in_f, const std::string& out_f );
void tasks10( const std::string& in_f, const std::string& out_f );

// ********************** main
int main( ) {
  // types and constants
  try {
    std::string file_in = PATH_FILE_ + "1.txt";
    std::string file_out = PATH_FILE_ + "2.txt";
    using task = void ( * )( const std::string&, const std::string& );
    task foo = tasks9;
    std::srand( std::time( nullptr ) );
    // *********  driver *********
    fillFile( file_in );
    std::cout << "---------original data------------" << std::endl;
    displayFile( file_in );  // original
    foo( file_in, file_out );
    std::cout << "----------result data-------------" << std::endl;
    displayFile( file_out );  // result
  } catch ( std::runtime_error& e ) {
    std::cerr << e.what( ) << std::endl;
  }
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

void tasks6( const std::string& in_f, const std::string& out_f ) {
  std::ifstream ifile( in_f );
  int tmp = 0;
  int sum = 0;
  while ( ifile ) {
    ifile >> std::skipws >> tmp;
    if ( !ifile.eof( ) ) sum += tmp;
  }
  ifile.clear( );                // clear bad or eof state;
  ifile.seekg( std::ios::beg );  // pointer on start
  std::ofstream ofile( out_f );
  std::cout << "summ = " << sum;
  while ( ifile ) {
    ifile >> std::skipws >> tmp;
    if ( !ifile.eof( ) ) {
      ofile << ( tmp - sum ) << '\n';
    }
  }
  ofile.close( );
  ifile.close( );
}

void tasks7( const std::string& in_f, const std::string& out_f ) {
  std::ifstream in_file( in_f );
  if ( !in_file.is_open( ) ) throw std::runtime_error( "ERROR OPEN FILE" );
  int res = 0;
  int t = 0;
  while ( in_file ) {
    in_file >> std::skipws >> t;
    if ( t < 0 ) {
      res = t;
      break;
    }
  }
  int iback = 1;
  while ( in_file ) {
    in_file.seekg( -( sizeof( int ) + sizeof( char ) ) * iback, std::ios::end );
    in_file >> std::skipws >> t;
    if ( t < 0 ) {
      res += t;
      break;
    }
    ++iback;
  }
  std::cout << "res = " << res;
  in_file.clear( );
  in_file.seekg( std::ios::beg );
  std::ofstream ofile( out_f );
  int everyThird = 1;
  while ( in_file ) {
    in_file >> std::skipws >> t;
    if ( !in_file.eof( ) ) {
      if ( !( everyThird % 3 ) )
        ofile << ( t * res ) << '\n';
      else
        ofile << t << '\n';
      ++everyThird;
    }
  }
}

void tasks8( const std::string& in_f, const std::string& out_f ) {
  std::ifstream inFile( in_f );
  if ( !inFile.is_open( ) ) throw std::runtime_error( "ERROR OPEN FILE" );
  int t = 0;
  while ( inFile ) {
    inFile >> std::skipws >> t;
    if ( std::abs( t ) % 2 ) break;
  }
  inFile.seekg( std::ios::beg );
  std::ofstream outFile( out_f );
  if ( !outFile.is_open( ) ) throw std::runtime_error( "ERROR OPEN FILE" );
  int tt = t;
  while ( inFile ) {
    inFile >> std::skipws >> t;
    if ( !inFile.eof( ) ) {
      outFile << ( t + tt ) << '\n';
    }
  }
}

void tasks9( const std::string& in_f, const std::string& out_f ) {
  std::ifstream ifile( in_f );
  if ( !ifile.is_open( ) ) throw std::runtime_error( "ERROR OPEN FILE" );
  int first_negative = 0;
  while ( ifile ) {
    ifile >> std::skipws >> first_negative;
    if ( first_negative < 0 ) break;
  }
  ifile.clear( );
  ifile.seekg( std::ifstream::beg );
  std::ofstream outfile( out_f );
  int t = 0;
  while ( ifile ) {
    ifile >> std::skipws >> t;
    if ( !ifile.eof( ) ) {
      outfile << ( t * first_negative ) << '\n';
    }
  }
}

void tasks10( const std::string& in_f, const std::string& out_f ) {}
