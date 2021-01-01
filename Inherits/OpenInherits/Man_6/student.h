#ifndef STUDENT_H
#define STUDENT_H
#include "man6.h"

class Student : public Man6 {
public:
    Student( const std::string & name = { }, int16_t age = 0, std::string sex = "M", int16_t weight = 0, int16_t year = 0 );
    void Display( ) const;
    operator std::string( ) const;

    Student & operator=( const Man6 & oth );

    int16_t year( ) const;
    void setYear( const int16_t & year );

private:
    int16_t year_;
};

#endif // STUDENT_H
