#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

static std::string PATH = "../../stringText1/";
// WARNING PROBLEM

// string
void stringText1( const std::string& inFile, const std::string& outFile );

// wstring
void wstringText1( const std::string& inFile, const std::string& outFile );

//// c-str
// void c_stringText1( const std::string& inFile, const std::string& outFile );

//// wc-str
// void wc_stringText1( const std::string& inFile, const std::string& outFile );

int main()
{
  try {
    stringText1( PATH + "text1", PATH + "text2" );
  } catch ( std::runtime_error& e ) {
    std::cerr << e.what( );
  } catch ( ... ) {
    std::cerr << "OTHER ??";
  }

  return 0;
}

void stringText1( const std::string& inFile, const std::string& outFile ) {
  std::ifstream file( inFile );
  std::string strFile( ( std::istreambuf_iterator< char >( file ) ),
                       std::istreambuf_iterator< char >( ) );
  file.close( );
  std::cout << strFile;
  std::cout << "**************************************" << std::endl;
  std::string::size_type idx = 0;

  while ( idx != std::string::npos ) {
    idx = strFile.find( "a", idx );
    if ( idx != std::string::npos ) {
      if ( strFile[ idx - 1 ] == ' ' && strFile[ idx + 1 ] == ' ' ) {
        std::cout << "idx = " << idx << std::endl;
        strFile.replace( idx, 1, "the" );
      }
      ++idx;
    }
  }

  std::ofstream ofile( outFile );
  ofile << strFile;
  ofile.close( );
  std::cout << strFile;
}

void wstringText1( const std::string& inFile, const std::string& outFile ) {
  std::wifstream ifile( inFile );

  std::wstring strFile( ( std::istreambuf_iterator< wchar_t >( ifile ) ),
                        std::istreambuf_iterator< wchar_t >( ) );
  std::wcout << strFile;
  std::wcout << "*******************************" << std::endl;
  std::wstring::size_type idx = 0;
  while ( idx != std::wstring::npos ) {
    idx = strFile.find( L"a", idx );
    if ( idx != std::wstring::npos ) {
      if ( strFile[ idx - 1 ] == L' ' && strFile[ idx + 1 ] == L' ' ) {
        strFile.replace( idx, 1, L"the" );
      }
      ++idx;
    }
  }

  std::wofstream wof( outFile );
  wof << strFile;
  std::wcout << strFile;
}

// void c_stringText1( const std::string& inFile, const std::string& outFile ) {
//  std::ifstream ifile( inFile );
//  if ( !ifile.is_open( ) ) throw std::runtime_error( "ERROR OPEN FILE" );
//  ifile.seekg( 0, std::ios::end );
//  ifile.clear( );
//  int64_t len = ifile.tellg( );
//  ifile.seekg( 0, std::ios::beg );

//  char* buf = new char[ len + 1 ] { '\0' };
//  ifile.read( buf, len );
//  ifile.close( );
//  buf[ len ] = '\0';

//  char* s = strchr( buf, 'a' );
//  //  std::cout << s;
//  if ( *( s - 1 ) == ' ' && *( s + 1 ) == ' ' ) {
//    int len = strlen( buf );
//    char* t = new char[ len + 2 + 1 ];
//    memcpy( ( void* ) t, ( void* ) buf, ( sizeof( char ) * std::abs( s - buf ) ) );
//    strncat( &t[ std::abs( s - buf ) ], "the", 3 );

//    t[ std::abs( s - buf ) + 3 ] = '\0';
//    std::cout << t;

//    delete[] t;
//  }

//  delete[] buf;
//}
