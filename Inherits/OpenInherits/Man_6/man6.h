#ifndef MAN6_H
#define MAN6_H
#include <string>

class Man6
{
public:
    Man6( const std::string & name = { }, int16_t age = 0, std::string sex = "M", int16_t weight = 0 );
    void Display( ) const;
    operator std::string( ) const;

    std::string name( ) const;
    void setName( const std::string & name );
    int16_t age( ) const;
    void setAge( const int16_t & age );
    std::string sex( ) const;
    void setSex( const std::string & sex );
    int16_t weight( ) const;
    void setWeight( const int16_t & weight );

private:
    std::string name_;
    int16_t age_;
    std::string sex_;
    int16_t weight_;
};

#endif // MAN6_H
