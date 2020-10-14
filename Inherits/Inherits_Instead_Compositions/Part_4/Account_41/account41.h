#ifndef ACCOUNT41_H
#define ACCOUNT41_H
#include "money24B.h"
#include <string>

class Account41 : private Money24B {
public:
    void Init( std::string name, std::string acc, double proc, double summ );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;

    std::string name( ) const;
    void setName( const std::string & name );
    void AddSumm( double sm );
    void SubSumm( double sm );
    void AddProcent( );
    double ToDollar( double cours );
    double ToEuro( double cours );
    std::string ToChislitelnoe( );

private:
    std::string Sotni( int chislo );
    std::string Desyatki( int chislo );
    std::string Edinitsy( int chislo );
    std::string ParseSotni( int chislo );
    std::string ParseThousand( int chislo );
    std::string ParseMillion( int chislo );

private:
    std::string name_;
    std::string accountNum_;
    double procent_;
    //double summa_;
    //Money24B summa_;
};

#endif // ACCOUNT41_H
