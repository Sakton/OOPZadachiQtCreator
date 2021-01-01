#include <ctime>
#include <fstream>
#include <iostream>

const std::string PATH = "../../IO_Part_4/File/file";
const int N = 6;

void fillFile( const std::string& fName );
void printFile( const std::string& fName );

void taska1( const std::string& fName );
void taska2( const std::string& fName );

int main( ) {
  // drivaer tasks
  fillFile( PATH );
  printFile( PATH );
  std::cout << "***********************************************" << std::endl;
  //**********
  taska2( PATH );
  //***********
  printFile( PATH );
}

void fillFile( const std::string& fName ) {
  std::ofstream ofile( fName, std::ios::binary );
  std::srand( std::time( nullptr ) );
  std::ofstream::pos_type pos = 0;
  for ( int i = 0; i < N; ++i ) {
    int rnd = std::rand( ) % 50;
    rnd *= ( rnd % 3 == 0 ) ? -1 : 1;
    ofile.write( reinterpret_cast< char* >( &rnd ), sizeof( int ) );
    pos += sizeof( int );
    ofile.seekp( pos, std::ios::beg );
  }
}

void printFile( const std::string& fName ) {
  std::ifstream ifile( fName );
  int x = 0;
  while ( ifile ) {
    ifile.read( reinterpret_cast< char* >( &x ), sizeof( int ) );
    if ( ifile ) {
      std::cout << x << '\n';
    }
  }
}

void taska1( const std::string& fName ) {
  std::fstream ffile( fName, std::ios::in | std::ios::out | std::ios::binary );
  ffile.seekg( -sizeof( int ), std::ios::end );
  int last = 0;
  ffile.read( reinterpret_cast< char* >( &last ), sizeof( int ) );
  ffile.clear( );
  ffile.seekg( std::ios::beg );
  std::cout << "last = " << last << std::endl;
  std::cout << "***********************************************" << std::endl;
  std::fstream::pos_type pos = 0;  //общий указатель буфера оба seek двигают 1 указатель, поэтому пофиг какую ф-ю использовать
  int x = 0;
  int cnt = 0;
  while ( ffile && cnt < N ) {
    // read
    ffile.read( reinterpret_cast< char* >( &x ), sizeof( int ) );
    // pos += sizeof( int );
    ffile.seekg( pos, std::ios::beg );
    // modify
    x += last;
    // write
    if ( ffile ) {
      ffile.write( reinterpret_cast< char* >( &x ), sizeof( int ) );
      pos += sizeof( int );
      ffile.seekp( pos, std::ios::beg );
    }
    ++cnt;
  }
  ffile.close( );
}

void taska2( const std::string& fName ) {
  std::fstream ff( fName, std::ios::in | std::ios::out | std::ios::binary );
  std::ios::pos_type pos = 0;
  int mid = 0;
  ff.seekg( ( sizeof( int ) * ( ( N / 2 ) ) ), std::ios::beg );
  ff.read( reinterpret_cast< char* >( &mid ), sizeof( int ) );
  ff.seekg( std::ios::beg );
  int neg = 0;
  while ( ff && neg >= 0 ) {
    ff.read( reinterpret_cast< char* >( &neg ), sizeof( int ) );
    pos += sizeof( int );
    ff.seekg( pos, std::ios::beg );
  }
  std::cout << "< 0 = " << neg << "  n/2 = " << mid << "  divider = " << ( mid + neg ) / 2 << std::endl;
  int delitel = ( mid + neg ) / 2;
  if ( delitel == 0 ) throw std::runtime_error( "DIVIDE ZERO" );
  ff.clear( );
  ff.seekg( std::ios::beg );
  pos = 0;  //обнулить pos
  int x = 0;
  while ( ff ) {
    // r
    ff.read( reinterpret_cast< char* >( &x ), sizeof( int ) );
    ff.seekg( pos, std::ios::beg );  //вернуть на позицию
    // m
    x /= delitel;
    std::cout << "x = " << x << ' ';
    // r
    ff.write( reinterpret_cast< char* >( &x ), sizeof( int ) );
    pos += sizeof( int );            //пересчитать позицию
    ff.seekg( pos, std::ios::beg );  //перейти
  }
  ff.flush( );
}
