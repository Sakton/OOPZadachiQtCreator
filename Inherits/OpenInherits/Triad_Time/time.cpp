#include "time.h"

Time::Time( int h, int m, int s ) : Triad( ) {
  if ( h < 0 || h > 24 || m < 0 || m > 60 || s < 0 || s > 60 ) {
    std::cerr << "ERROR TIME";
    exit( 1 );
  }
  Triad::setFirst( h );
  Triad::setSecond( m );
  Triad::setThird( s );
}

int Time::HourNext( ) {
  Triad::setFirst( Triad::FirstNext( ) % 24 );
  return Triad::First( );
}

int Time::MinutNext( ) {
  Triad::setSecond( Triad::SecondNext( ) % 60 );
  if ( !Triad::Second( ) ) HourNext( );
  return Triad::Second( );
}

int Time::SecundNext( ) {
  Triad::setThird( Triad::ThirdNext( ) % 60 );
  if ( !Triad::Third( ) ) MinutNext( );
  return Triad::Third( );
}

void Time::AddSecund( int n ) {
  for ( int i = 0; i < n; ++i ) SecundNext( );
}

void Time::AddMinut( int n ) {
  for ( int i = 0; i < n; ++i ) MinutNext( );
}

std::ostream &Time::show( std::ostream &out ) {
  Triad::show( out );
  return out;
}

int Time::GetHour( ) { return Triad::First( ); }
int Time::GetMinut( ) { return Triad::Second( ); }
int Time::GetSecund( ) { return Triad::Second( ); }
