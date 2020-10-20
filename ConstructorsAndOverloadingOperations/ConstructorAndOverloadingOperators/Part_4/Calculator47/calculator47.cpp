#include "calculator47.h"

#include <iostream>
#include <stack>

Fraction35Long Calculator47::operator( )( const std::string &ex ) {
  return Calculate( Parse( ex ) );
}

std::string Calculator47::Parse( const std::string &ex ) {
  std::string res;
  std::stack< char > st;
  for ( auto it = ex.cbegin( ); it != ex.cend( ); ++it ) {
    if ( *it == ' ' || *it == '(' ) continue;
    if ( std::isdigit( *it ) ) {
      while ( std::isdigit( *it ) || *it == '.' ) {
        res.push_back( *it++ );
      }
      res.push_back( ' ' );
    }
    if ( *it == '+' || *it == '-' || *it == '*' || *it == '/' ) {
      st.push( *it );
    }
    if ( *it == ')' ) {
      res.push_back( st.top( ) );
      st.pop( );
      res.push_back( ' ' );
    }
  }
  if ( !st.empty( ) && st.top( ) == '-' ) {
    res.push_back( st.top( ) );
    st.pop( );
    res.push_back( ' ' );
  }
  if ( !st.empty( ) ) {
    std::cout << "ERROR EXPRESSION";
    exit( 1 );
  }
  return res;
}

Fraction35Long Calculator47::Calculate( const std::string &ex ) {
  std::stack< Fraction35Long > st;
  for ( std::size_t i = 0; i < ex.size( ); ++i ) {
    if ( std::isdigit( ex[ i ] ) ) {
      std::size_t idx = ex.find( ' ', i );
      std::string chislo = ex.substr( i, idx - i );
      //      std::cout << chislo << ' ';
      if ( int ind = chislo.find( '.' ) != std::string::npos ) {
        std::string whole = chislo.substr( 0, ind );
        std::string drobn = chislo.substr( ind + 1, chislo.size( ) - 1 );
        st.push( Fraction35Long( LongLong38B( std::stoll( whole ) ),
                                 std::stod( drobn ) ) );
      } else {
        st.push( Fraction35Long( LongLong38B( std::stoll( chislo ) ), 0 ) );
      }
      i = idx;
    }
    if ( ex[ i ] == '+' || ex[ i ] == '-' || ex[ i ] == '*' ||
         ex[ i ] == '/' ) {
      //      if ( ( i = ex.size( ) - 1 ) && ( ex[ i ] == '-' ) ) {

      //      }

      switch ( ex[ i ] ) {
        case '+': {
          Fraction35Long b = st.top( );
          st.pop( );
          Fraction35Long a = st.top( );
          st.pop( );
          st.push( a + b );
          break;
        }
        case '-': {
          Fraction35Long b = st.top( );
          st.pop( );
          if ( !st.empty( ) ) {
            Fraction35Long a = st.top( );
            st.pop( );
            st.push( a - b );
          } else {
            st.push( -b );
          }
          break;
        }
        case '*': {
          Fraction35Long b = st.top( );
          st.pop( );
          Fraction35Long a = st.top( );
          st.pop( );
          st.push( a * b );
          break;
        }
        case '/': {
          Fraction35Long b = st.top( );
          st.pop( );
          Fraction35Long a = st.top( );
          st.pop( );
          st.push( a / b );
          break;
        }
      }
    }
  }
  Fraction35Long res = st.top( );
  st.pop( );
  return res;
}
