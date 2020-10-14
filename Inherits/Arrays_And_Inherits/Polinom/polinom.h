#ifndef POLINOM_H
#define POLINOM_H
#include "array.h"
#include <vector>

class Polinom : public Array< double > {
public:
public:
    explicit Polinom( int n );
    explicit Polinom( const std::vector< double > & v );
    explicit Polinom( const double array[], int n );
    explicit Polinom( std::unique_ptr< double[] > & arr, int n );
    Polinom( const Polinom & oth );
    Polinom( Polinom && oth ) noexcept;
    Polinom & operator=( const Polinom & oth );
    Polinom & operator=( Polinom && oth ) noexcept;

    Polinom & operator+=( const Polinom & other );
    Polinom & operator-=( const Polinom & other );
    Polinom & operator*=( const Polinom & other );
    //    Polinom & operator/=( const Polinom & other );

    void Read( );
    void Display( ) const;

    double & operator[]( int ind );
    const double & operator[]( int ind ) const;

    long double Estimation( double x ) const; //вычисление

    //получив новый полином можно вычислять значение при Х у нового полинома
    Polinom Differentiation( );
    Polinom Integration( );

    //private:
    double FastPow( double x, int y ) const;
    double DiffOne( double coeff, int stepen );
    double IntegrOne( double coeff, int stepen );
};

#endif // POLINOM_H
