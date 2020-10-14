#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <vector>

class Fraction
{
public:
    Fraction( int szCel, int szDrob );
    Fraction( const std::string & c, const std::string & d );
    //explicit Fraction( long double d ); //он бессмысленный для большого дабл
    //оператор копирования и присваивания
    Fraction( Fraction && oth ) noexcept;
    Fraction & operator=( Fraction && oth ) noexcept;

    //TODO потом на досуге
    //Операции как у Decimal_2 или Hex и т.д.
    //    Fraction & operator+=( Fraction && oth );
    //    Fraction & operator-=( Fraction && oth );
    //    Fraction & operator*=( Fraction && oth );
    //    Fraction & operator/=( Fraction && oth );

private:
    std::vector< unsigned char > cel;
    std::vector< unsigned char > drb;
};

#endif // FRACTION_H
