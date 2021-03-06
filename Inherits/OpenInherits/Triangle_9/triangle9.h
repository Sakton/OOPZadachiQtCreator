#ifndef TRIANGLE9_H
#define TRIANGLE9_H
#include <string>

class Triangle9
{
public:
    Triangle9( int32_t ab = 0, int32_t bc = 0, int32_t ac = 0 );
    void Display( ) const;
    operator std::string( ) const;

    double Perimetr( ) const;
    double angA( ) const;
    double angB( ) const;
    double angC( ) const;

    void setAb( const int32_t & ab );
    void setBc( const int32_t & bc );
    void setAc( const int32_t & ac );

    int32_t ab( ) const;
    int32_t bc( ) const;
    int32_t ac( ) const;

private:
    int32_t ab_;
    int32_t bc_;
    int32_t ac_;
};

#endif // TRIANGLE9_H
