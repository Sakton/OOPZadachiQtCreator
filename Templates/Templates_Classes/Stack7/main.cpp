#include <iostream>

#include "Stack7.h"

int main()
{
  Stack7< int > st;
  st.push( 100 );
  st.push( 200 );
  st.push( 300 );
  st.push( 400 );
  st.push( 500 );
  st.push( 600 );
  st.push( 700 );
  st.push( 800 );
  st.push( 900 );
  st.push( 1000 );
  st.push( 1100 );
  st.push( 1200 );
  st.push( 1300 );
  st.push( 1400 );
  st.push( 1500 );

  while ( !st.empty( ) ) {
    std::cout << st.top( ) << " ";
    st.pop( );
  }

  return 0;
}
