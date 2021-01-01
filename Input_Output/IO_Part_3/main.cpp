#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

const int N = 6;
const std::string FILE_INPUT = "../../IO_Part_3/File/input";
const std::string FILE_OUTPUT = "../../IO_Part_3/File/output";

void fillFile( const std::string &file_name );
void prinrFile( const std::string &file_name );
// void prinrFileIter( const std::string &file_name );

// tasks
void task1( const std::string &inpt, const std::string &outpt );
void task2( const std::string &inpt, const std::string &outpt );

int main( ) {
  try {
    // driver tasks
    fillFile( FILE_INPUT );
    prinrFile( FILE_INPUT );
    // prinrFileIter( FILE_INPUT );
    std::cout << "\n***************************************************" << std::endl;
    task2( FILE_INPUT, FILE_OUTPUT );
    prinrFile( FILE_OUTPUT );
  } catch ( std::runtime_error &e ) {
    std::cerr << e.what( ) << std::endl;
  } catch ( ... ) {
    std::cerr << "OTHER ERR" << std::endl;
  }
}

void fillFile( const std::string &file_name ) {
  std::ofstream ofile( file_name, std::ios::binary );
  std::srand( std::time( nullptr ) );
  // 1. Установка позиции в начало файла
  std::ios::pos_type size = 0;
  for ( int i = 0; i < N; ++i ) {
    int rnd = std::rand( ) % 50;
    rnd *= ( rnd % 3 == 0 ) ? -1 : 1;
    // 2. запись в файл байтами(реинтерпретация int как массива char)
    // char - в данном случае считается как 1ца информации (типа byte нету)
    ofile.write( reinterpret_cast< char * >( &rnd ), sizeof( int ) );
    // 3. вычислить позицию файлового указателя начала следующего участка для записи
    size += sizeof( int );
    // 4. установить позицию файлового указателя на начало следующего участка для записи, ОТНОСИТЕЛЬНО начала файла
    ofile.seekp( size, std::ios::beg );
  }
}

void prinrFile( const std::string &file_name ) {
  std::ifstream ifile( file_name, std::ios::binary );
  // 1. Установить позицию для считывания в начало
  std::ios::pos_type pos = 0;
  int x = 0;
  while ( ifile ) {
    // 2. Считывание количества байт из файла по адресу реинтерпретируемому как массив байт (char = 1 байт)
    ifile.read( reinterpret_cast< char * >( &x ), sizeof( int ) );
    if ( ifile.good( ) ) {
      // 3. Вычисление следующей позиции начала считывания
      pos += sizeof( int );
      // 4. Установка в позицию файлового указателя
      ifile.seekg( pos, std::ios::beg );
      std::cout << x << '\n';
    }
  }
}

// void prinrFileIter( const std::string &file_name ) {
//  std::ifstream ifile( file_name, std::ios::binary );
//  std::copy( std::istream_iterator< char >( ifile ), std::istream_iterator< char >( ), std::ostream_iterator< char >( std::cout, " " ) );
//}

void task1( const std::string &inpt, const std::string &outpt ) {
  std::ifstream ifile( inpt, std::ios::binary );
  int last_num = 0;
  ifile.seekg( -sizeof( int ), std::ifstream::end );
  ifile.read( reinterpret_cast< char * >( &last_num ), sizeof( int ) );
  std::cout << "last_num = " << last_num << std::endl;
  ifile.clear( );
  ifile.seekg( std::ios::beg );
  std::ofstream ofile( outpt, std::ios::binary );
  std::ofstream::pos_type pos_out = 0;
  std::ifstream::pos_type pos = 0;
  int x = 0;
  while ( ifile.good( ) ) {
    // read
    ifile.read( reinterpret_cast< char * >( &x ), sizeof( int ) );
    pos += sizeof( int );
    ifile.seekg( pos, std::ios::beg );
    // modify
    x += last_num;
    // write
    ofile.write( reinterpret_cast< char * >( &x ), sizeof( int ) );
    pos_out += sizeof( int );
    ofile.seekp( pos_out, std::ios::beg );
  }
}

void task2( const std::string &inpt, const std::string &outpt ) {
  std::ifstream ifile( inpt, std::ios::binary );
  std::ifstream::pos_type pos = 0;
  int count = 0;
  bool flag1 = false;
  bool flag2 = false;
  int x = 0;
  int el = 0;
  int neg = 0;
  while ( ifile && ( !flag1 || !flag2 ) ) {
    ifile.read( reinterpret_cast< char * >( &x ), sizeof( int ) );
    pos += sizeof( int );
    ifile.seekg( pos, std::ios::beg );
    if ( x < 0 && !flag1 ) {
      neg = x;
      flag1 = !flag1;
    }
    if ( ( count++ == N / 2 ) && !flag2 ) {
      flag2 = !flag2;
      el = x;
    }
    // при работе на маленьких наборах - отрицательное может быть за N/2, а может и не быть вовсе
  }
  std::cout << "fneg = " << neg << " , N/2-th = " << el << std::endl;
  ifile.clear( );
  pos = 0;
  ifile.seekg( std::ios::beg );
  std::ofstream ofile( outpt, std::ios::binary );
  std::ofstream::pos_type out_pos = 0;
  while ( ifile ) {
    // r
    ifile.read( reinterpret_cast< char * >( &x ), sizeof( int ) );
    pos += sizeof( int );
    ifile.seekg( pos, std::ios::beg );
    // m
    if ( x == 0 ) throw std::runtime_error( "DIVIDE ZERO task2" );
    x /= ( el + neg ) / 2;
    // s
    ofile.write( reinterpret_cast< char * >( &x ), sizeof( int ) );
    out_pos += sizeof( int );
    ofile.seekp( out_pos, std::ios::beg );
  }
}
