#ifndef BILL_H
#define BILL_H
#include <string>

#include "time30.h"

class Bill
{
 public:
  Bill( const std::string &name, const std::string &phone, double tarif,
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
