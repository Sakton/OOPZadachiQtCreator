#include "calculator44private.h"

#include <iostream>
#include <stack>

#include "fraction35.h"

Fraction35B Calculator44private::operator( )( const std::string &expr ) {
  return Raschet( Postfix( expr ) );
}

std::string Calculator44private::Postfix( const std::string &expr ) {
  std::string res;
  std::stack< char > st;
  for ( auto it = expr.cbegin( ); it != expr.cend( ); ++it ) {
    if ( *it == ' ' ) continue;
    if ( *it == '+' || *it == '-' || *it == '*' || *it == '/' ) {
      st.push( *it );
    }
    if ( std::isdigit( *it ) ) {
      while ( std::isdigit( *it ) ) {
        res.push_back( *it++ );
      }
      res += ' ';
    }
    if ( *it == ')' ) {
      res.push_back( st.top( ) );
      st.pop( );
      res += ' ';
    }
  }
  while ( !st.empty( ) ) {
    res.push_back( st.top( ) );
    st.pop( );
    res += ' ';
  }
  return res;
}

Fraction35B Calculator44private::Raschet( const std::string &expr ) {
  std::stack< Fraction35B > st;
  Fraction35B res;

  for ( auto it = expr.cbegin( ); it != expr.cend( ); ++it ) {
    if ( std::isdigit( *it ) ) {
      double t = 0;
      while ( std::isdigit( *it ) ) {
        t = t * 10 + ( *it - '0' );
        ++it;
      }
      st.push( Fraction35B( t ) );
    }

    if ( *it == '+' || *it == '-' || *it == '*' || *it == '/' ) {
      Fraction35B a = st.top( );
      st.pop( );

      if ( *it == '-' && st.empty( ) ) {  //унарный минус перед выражением
        res = -a;
      } else {
        Fraction35B b = st.top( );
        st.pop( );
        switch ( *it ) {
          case '+':
            res = b + a;
            break;
          case '-':
            res = b - a;
            break;
          case '*':
            res = b * a;
            break;
          case '/':
            res = b / a;
            break;
        }
      }
      st.push( res );
    }
  }
  res = st.top( );
  st.pop( );
  return res;
}
