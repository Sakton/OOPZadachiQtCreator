#include "dateprivate.h"

DatePrivate::DatePrivate( int16_t y, int16_t m, int16_t d )
    : BaseDate( y, m, d ) {}

DatePrivate::DatePrivate( const std::string& dt ) : BaseDate( dt ) {}

DatePrivate DatePrivate::AddDay( int days ) const {
  DatePrivate t = *this;
  //Переменная отвечает за проверку високосности в году прибытия
  //если будут переходы через года то високосность учтется в годовой
  //корректировке поэтому ее считать в корректировке по месяцам не надо
  bool yearChanged = ( days > 365 );
  days += t.Day( );

  while ( days >= 365 ) {
    // WARNING тут была ошибка в порядке следования проверки на високосность!!!
    if ( t.IsVisokosny( ) ) t.setDay( t.Day( ) - 1 );
    t.setYear( t.Year( ) + 1 );
    //Год меняется и текущий уже не високосный!!! копится ошибка дней по
    //високосным годам!!! 	if ( t.IsVisokosny( ) )
    //	    --days;
    days -= 365;
  }

  int countDayInMonth = monats[ t.Month( ) - 1 ];
  if ( ( t.Month( ) - 1 ) == 1 && t.IsVisokosny( ) && !yearChanged )
    ++countDayInMonth;

  while ( days > countDayInMonth ) {
    days -= countDayInMonth;
    if ( t.Month( ) + 1 == 13 ) {
      t.setMonth( 1 );
      t.setYear( t.Year( ) + 1 );
    }
    countDayInMonth = monats[ t.Month( ) - 1 ];
  }
  t.setDay( days );
  return t;
}

DatePrivate DatePrivate::SubDay( int days ) const {
  DatePrivate t = *this;

  int index = t.Month( ) - 1;
  if ( index < 0 ) index = 11;

  days += ( monats[ index ] - t.Month( ) );  //загвоздка тут
  bool yearChanged = ( days > 365 );

  if ( days >= 365 ) {
    if ( t.IsVisokosny( ) && t.Month( ) >= 3 ) {
      --days;
    }
    t.setYear( t.Year( ) - 1 );
    days -= 365;
  }

  while ( days >= monats[ index ] ) {
    days -= monats[ index ];
    if ( index == 1 && t.IsVisokosny( ) && !yearChanged ) --days;
    if ( t.Month( ) == 0 ) {
      t.setMonth( 12 );
      t.setYear( t.Year( ) - 1 );
    }
    index = t.Month( ) - 1;
  }

  t.setDay( monats[ index ] - days );
  return t;
}

int16_t DatePrivate::Interval( const DatePrivate& other ) const {
  //считаем что дата other - последующая всегда
  //тоесть интервал от меньшего времени к большему
  int startY = Year( );
  int endY = other.Year( );
  if ( startY > endY ) std::swap( startY, endY );
  int coutYears = endY - startY;
  int countVisokosnyLet = coutYears / 4;
  //крайние года не попадают в интервал
  int res = countVisokosnyLet * 366 + ( coutYears - countVisokosnyLet ) * 365;

  // MONATS
  if ( Year( ) != other.Year( ) ) {
    for ( int i = Month( ) + 1; i < 12; ++i ) {
      res += monats[ i ];
      if ( i == 1 && IsVisokosny( ) ) ++res;
    }
    for ( int i = 0; i <= other.Month( ); ++i ) {
      res += monats[ i ];
      if ( i == 1 && IsVisokosny( ) ) ++res;
    }
  } else {
    for ( int i = Month( ) + 1; i < other.Month( ); ++i ) {
      res += monats[ i ];
      if ( i == 1 && IsVisokosny( ) ) ++res;
    }
  }

  // DAYS
  if ( Month( ) != other.Month( ) ) {
    res += ( monats[ Month( ) - 1 ] - Day( ) ) + other.Day( );
  } else {
    res += other.Day( ) - Day( );
  }

  return res;
}

bool DatePrivate::IsVisokosny( ) const {
  return ( ( Year( ) % 4 == 0 ) ||
           ( ( Year( ) % 100 == 0 ) && ( Year( ) % 400 == 0 ) ) );
}

void Display( const DatePrivate& dp ) {
  return ::Display( static_cast< const BaseDate& >( dp ) );
}

std::string ToString( const DatePrivate& dp ) {
  return ::ToString( static_cast< const BaseDate& >( dp ) );
}
