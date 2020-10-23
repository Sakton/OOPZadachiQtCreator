//#ifndef ACCOUNT41PRIVATE_H
//#define ACCOUNT41PRIVATE_H
//#include <string>

//// TODO ????

// class Account41Private
//{
// private:
//  class Money24 {
//   public:
//    friend class Account41Private;

//    explicit Money24( int32_t rb = 0, int16_t cp = 0 );
//    explicit Money24( double sum );  //Добавлено

//    Money24& operator+=( const Money24& b );
//    Money24& operator-=( const Money24& b );
//    Money24& operator*=( double x );
//    Money24& operator/=( double x );
//    double operator/=( const Money24& b );

//    void Display( );
//    void Read( );
//    explicit operator std::string( ) const;
//    explicit operator double( ) const;  //Добавлено

//    friend Money24 operator+( const Money24& a, const Money24& b );
//    friend Money24 operator-( const Money24& a, const Money24& b );
//    friend Money24 operator*( const Money24& a, double x );
//    friend double operator/( const Money24& a, const Money24& b );
//    friend Money24 operator/( const Money24& a, double x );

//    friend bool operator==( const Money24& a, const Money24& b );
//    friend bool operator!=( const Money24& a, const Money24& b );
//    friend bool operator<=( const Money24& a, const Money24& b );
//    friend bool operator>=( const Money24& a, const Money24& b );
//    friend bool operator<( const Money24& a, const Money24& b );
//    friend bool operator>( const Money24& a, const Money24& b );

//    int32_t GetRub( ) const;
//    uint8_t GetCop( ) const;

//   private:
//    int32_t rub { 0 };
//    uint8_t cop { 0 };
//  };

//  friend class Money24;

//  Account41Private( const std::string& name, const std::string& acc,
//                    double proc, double summ );
//  void Display( );
//  operator std::string( ) const;

//  std::string name( ) const;
//  void setName( const std::string& name );

//  Account41Private& operator+=( double sm );
//  Account41Private& operator-=( double sm );

//  friend Account41Private operator+( const Account41Private& ac1, double sm );
//  friend Account41Private operator+( double sm, const Account41Private& ac2 );
//  friend Account41Private operator-( const Account41Private& ac1, double sm );
//  friend Account41Private operator-( double sm, const Account41Private& ac2 );

//  void AddProcent( );
//  double ToDollar( double cours ) const;
//  double ToEuro( double cours ) const;
//  std::string ToChislitelnoe( ) const;

// private:
//  std::string Sotni( int chislo ) const;
//  std::string Desyatki( int chislo ) const;
//  std::string Edinitsy( int chislo ) const;
//  std::string ParseSotni( int chislo ) const;
//  std::string ParseThousand( int chislo ) const;
//  std::string ParseMillion( int chislo ) const;

// private:
//  std::string name_;
//  std::string accountNum_;
//  double procent_;
//  // double summa_;
//  // Money24 summa_;
//};

//#endif // ACCOUNT41PRIVATE_H
