#ifndef POLINOM5_H
#define POLINOM5_H
#include <memory>
#include <vector>
//тут просто хранение коэффициентов многочлена
//интегрирование = домножение на (нов степень / старая степень) и смещение на 1 индекс вправо (увеличение степени)
//дифференцирование = домножение на ( степень ) и смещение на 1 влево (уменьшение степени)

class Polinom5 {
public:
    explicit Polinom5( int n );
    explicit Polinom5( const std::vector< double > & v );
    explicit Polinom5( const double array[], int n );
    explicit Polinom5( std::unique_ptr< double[] > & arr, int n );
    Polinom5( const Polinom5 & oth );
    Polinom5( Polinom5 && oth ) noexcept;
    Polinom5 & operator=( const Polinom5 & oth );
    Polinom5 & operator=( Polinom5 && oth ) noexcept;

    Polinom5 & operator+=( const Polinom5 & other );
    Polinom5 & operator-=( const Polinom5 & other );
    Polinom5 & operator*=( const Polinom5 & other );
    //    Polinom5 & operator/=( const Polinom5 & other );

    void Read( );
    void Display( ) const;

    double & operator[]( int ind );
    const double & operator[]( int ind ) const;

    long double Estimation( double x ) const; //вычисление

    //получив новый полином можно вычислять значение при Х у нового полинома
    Polinom5 Differentiation( );
    Polinom5 Integration( );

    //private:
    double FastPow( double x, int y ) const;
    double DiffOne( double coeff, int stepen );
    double IntegrOne( double coeff, int stepen );

private:
    static const int MAX_IND = 100;
    std::unique_ptr< double[] > data_;
    int size_;
};

#endif // POLINOM5_H
