#ifndef BASEACCOUNT_H
#define BASEACCOUNT_H
#include <string>

class BaseAccount
{
 public:
  BaseAccount( const std::string& name, const std::string& acc, double proc,
               double summ );
  friend void Display( const BaseAccount& ac );
  friend std::string ToString( const BaseAccount& ac );

  std::string getName( ) const;
  void setName( const std::string& name );
  std::string getAccountNum( ) const;
  void setAccountNum( const std::string& accountNum );
  double getProcent( ) const;
  void setProcent( double procent );
  double getSumma( ) const;
  void setSumma( double summa );

 private:
  std::string name_;
  std::string accountNum_;
  double procent_;
  double summa_;
};

#endif // BASEACCOUNT_H
