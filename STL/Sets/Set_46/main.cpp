#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <algorithm>
#include <iostream>
#include <locale>
#include <set>

void printGlasnye( const std::wstring &ws );
void printSerRaznitsa( const std::wstring &ws );

int main(int argc, char *argv[])
{
  QCoreApplication a( argc, argv );

  setlocale( LC_ALL, "Ru_CH" );
  std::wstring rus( L"������� �����" );

  printGlasnye( rus );
  std::wcout << std::endl;
  printSerRaznitsa( rus );

  return a.exec( );
}

void printGlasnye( const std::wstring &ws ) {
  std::set< wchar_t > set;
  for ( auto const &el : ws ) {
    auto ch = el;
    if ( ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) ||
         ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) ||
         ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) || ( ch == L'�' ) ) {
      set.insert( ch );
    }
  }
  std::copy( set.cbegin( ), set.cend( ), std::ostream_iterator< wchar_t, wchar_t >( std::wcout, L" " ) );
}

void printSerRaznitsa( const std::wstring &ws ) {
  std::wstring russymbolglasn( L"������������������������������������������" );
  std::set< wchar_t > all( russymbolglasn.cbegin( ), russymbolglasn.cend( ) );
  std::set< wchar_t > set;
  for ( auto const &el : ws ) {
    set.insert( el );
  }
  std::set< wchar_t > res;
  std::set_difference( all.cbegin( ), all.cend( ), set.cbegin( ), set.cend( ), std::inserter( res, res.end( ) ) );
  std::copy( res.cbegin( ), res.cend( ), std::ostream_iterator< wchar_t, wchar_t >( std::wcout, L" " ) );
}
