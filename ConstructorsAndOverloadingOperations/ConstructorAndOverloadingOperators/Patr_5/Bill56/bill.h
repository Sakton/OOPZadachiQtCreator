#ifndef BILL_H
#define BILL_H
#include <string>

//#include "time30.h"

class Bill
{
 public:
  class Time30 {
   public:
    explicit Time30( int16_t h = 0, int16_t m = 0, int16_t s = 0 );
    explicit Time30( const std::string& dt );
    Time30( const Time30& dt );
    void Display( ) const;
    explicit operator std::string( ) const;

    friend int32_t operator-( const Time30& t1, const Time30& t2 );
    friend Time30 operator+( const Time30& other, int32_t sec );
    friend Time30 operator+( int32_t sec, const Time30& other );

    friend Time30 operator-( const Time30& other, int32_t sec );

    friend bool operator==( const Time30& t1, const Time30& t2 );
    friend bool operator<( const Time30& t1, const Time30& t2 );
    friend bool operator>( const Time30& t1, const Time30& t2 );

    int32_t ToSecond( ) const;
    int32_t ToMinut( ) const;
    Time30 ToTime( int32_t sec ) const;

   private:
    static constexpr int SEC_IN_DAY = 86400;
    int16_t h_;
    int16_t m_;
    int16_t s_;
  };

  Bill( const std::string& name, const std::string& phone, double tarif,
        double sale, Time30 start, Time30 end );

  void Display( ) const;
  explicit operator std::string( ) const;

  int TimeSpeak( ) const;
  double Cost( ) const;

  std::string name( ) const;
  void setName( const std::string &name );
  std::string phone( ) const;
  void setPhone( const std::string &phone );
  double tarif_minut( ) const;
  void setTarif_minut( double tarif_minut );
  double sale( ) const;
  void setSale( double sale );
  Time30 start_time( ) const;
  void setStart_time( const Time30 &start_time );
  Time30 end_time( ) const;
  void setEnd_time( const Time30 &end_time );

 private:
  std::string name_;
  std::string phone_;
  double tarif_minut_;
  double sale_;
  Time30 start_time_;
  Time30 end_time_;
  double cost_;  //не понятно зачем он нужен..
};

#endif // BILL_H
