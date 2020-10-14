#ifndef CAR_H
#define CAR_H
#include <string>

class Car {
public:
    Car( const std::string & name = "", int16_t cyl = 0, int16_t pow = 0 );
    void Display( );

    operator std::string( ) const;

    int16_t power( ) const;
    void setPower( const int16_t & power );
    std::string name( ) const;
    void setName( const std::string & name );
    int16_t count_cylinder( ) const;
    void setCount_cylinder( const int16_t & count_cylinder );

private:
    std::string name_;
    int16_t count_cylinder_;
    int16_t power_;
};

#endif // CAR_H
