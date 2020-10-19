#include "calculator44.h"

#include <iostream>
#include <stack>

#include "fraction35.h"

/*
double Calculator44::operator( )( const std::string &expr ) {
  // 1. Делаем постфиксную запись
  std::stack< std::string > st_;
  char cur_znak = ' ';
  for ( auto it = expr.cbegin( ); it != expr.cend( ); ++it ) {
    if ( *it == '(' ) continue;
    if ( std::isdigit( *it ) ) {
      std::string num;
      while ( std::isdigit( *it ) ) {
        num.push_back( *it++ );
      }
      st_.push( num );
    }
    if ( *it == '+' || *it == '-' || *it == '*' || *it == '/' ) {
      cur_znak = *it;
    }
    if ( *it == ')' ) {
      std::string num = st_.top( );
      st_.pop( );
      std::string res = st_.top( );
      st_.pop( );
      res += " " + num + " " + cur_znak + " ";
      st_.push( res );
    }
  }

std::string res = st_.top( );
st_.pop( );
std::cout << res << std::endl;

std::stack< Fraction35B > stack_;
return 0;
}

*/

Fraction35B Calculator44::operator( )( const std::string &expr ) {
  return Raschet( Postfix( expr ) );
}

std::string Calculator44::Postfix( const std::string &expr ) {
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

/*
double Calculator44::Raschet( const std::string &expr ) {
  std::stack< double > st;
  double res = 0;

for ( auto it = expr.cbegin( ); it != expr.cend( ); ++it ) {
  if ( std::isdigit( *it ) ) {
    double t = 0;
    while ( std::isdigit( *it ) ) {
      t = t * 10 + ( *it - '0' );
      ++it;
    }
    st.push( t );
  }

  if ( *it == '+' || *it == '-' || *it == '*' || *it == '/' ) {
    double a = st.top( );
    st.pop( );

    if ( *it == '-' && st.empty( ) ) {
      res = -a;
    } else {
      double b = st.top( );
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

*/

Fraction35B Calculator44::Raschet( const std::string &expr ) {
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
