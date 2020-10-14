#ifndef DATE29B_H
#define DATE29B_H
#include <string>

//В ЗАДАЧЕ НЕТ УТОЧНЕНИЯ ВКЛЮЧАЯ ТЕКУЩИЙ ДЕНЬ ИЛИ НЕТ

class Date29B
{
    constexpr static int monats[ 12 ]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
    void Init( int16_t y, int16_t m, int16_t d );
    void Init( const std::string & dt );
    void Init( const Date29B & dt );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;

    Date29B AddDay( int days ) const;
    Date29B SubDay( int days ) const;
    int16_t Interval( const Date29B & other );
    bool IsVisokosny( ) const;

    int16_t Year( ) const;
    void setYear( const int16_t & y );
    int16_t Month( ) const;
    void setMonth( const int16_t & m );
    int16_t Day( ) const;
    void setDay( const int16_t & d );

private:
    int16_t y_;
    int16_t m_;
    int16_t d_;
};

#endif // DATE29B_H
