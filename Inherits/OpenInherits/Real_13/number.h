#ifndef NUMBER_H
#define NUMBER_H


class Number
{
public:
    Number( float f = 0 );

    Number & operator+=( const Number & ot );
    Number & operator/=( const Number & ot );

    float f( ) const;

private:
    float f_;
};

#endif // NUMBER_H
