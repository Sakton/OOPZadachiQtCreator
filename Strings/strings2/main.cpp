#include <fstream>
#include <iostream>
#include <locale>
#include <string>

const std::string PATH_IN = "../../strings2/File/inpt2.txt";
const std::string PATH_OUT = "../../strings2/File/outpt2.txt";

std::wstring fileToStr( const std::string& file_name );

int main( ) {
  setlocale( LC_ALL, "rus" );
  std::wcout.imbue( std::locale( "rus.1251" ) );
  //  std::wcout << fileToStr( PATH_IN );
  // std::wstring rus = L"Русская строка";
  std::wcout << L"Руссишшь";
  // std::wcout << rus;
}

std::wstring fileToStr( const std::string& file_name ) {
  std::wifstream fin( file_name );
  fin.imbue( std::locale( "rus_rus.866" ) );
  std::wstring str;
  std::copy( std::istream_iterator< wchar_t, wchar_t >( fin ), std::istream_iterator< wchar_t, wchar_t >( ), std::back_inserter( str ) );
  return str;
}
