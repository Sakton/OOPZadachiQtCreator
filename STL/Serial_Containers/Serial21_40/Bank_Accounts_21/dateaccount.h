#ifndef DATEACCOUNT_H
#define DATEACCOUNT_H
#include <cstdint>
#include <iostream>

class Month;

class Day {
 public:
  using value_type = uint16_t;
  explicit Day( value_type d = 1 );
  friend std::ostream &operator<<( std::ostream &out, const Day &d );

 private:
  value_type validDay( value_type d ) const;

 private:
  value_type day_;
};

class Month {
 public:
  using value_type = uint16_t;
  static Month Jan( ) { return Month( 1 ); }
  static Month Feb( ) { return Month( 2 ); }
  static Month Mar( ) { return Month( 3 ); }
  static Month Apr( ) { return Month( 4 ); }
  static Month May( ) { return Month( 5 ); }
  static Month Yun( ) { return Month( 6 ); }
  static Month Yul( ) { return Month( 7 ); }
  static Month Aug( ) { return Month( 8 ); }
  static Month Sep( ) { return Month( 9 ); }
  static Month Okt( ) { return Month( 10 ); }
  static Month Nov( ) { return Month( 11 ); }
  static Month Dec( ) { return Month( 12 ); }

  value_type month( ) const;
  friend std::ostream &operator<<( std::ostream &out, const Month &m );

 private:
  explicit Month( value_type m );

 private:
  value_type m_;
};

class Year {
 public:
  using value_type = uint16_t;
  Year( value_type year = 1970 );

  friend std::ostream &operator<<( std::ostream &out, const Year &y );

 private:
  value_type validateYear( value_type year ) const;

 private:
  value_type year_;
};

class DateAccount
{
 public:
  DateAccount( );
  DateAccount( const Day &day, const Month &m, const Year &year );
  DateAccount( const DateAccount &oth );
  friend std::ostream &operator<<( std::ostream &out, const DateAccount &da );

 private:
  Day day_;
  Month month_;
  Year year_;
};

#endif // DATEACCOUNT_H
