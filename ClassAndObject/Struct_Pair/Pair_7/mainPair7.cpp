#include <iostream>

struct Data7 {
    struct Pair {
	double first;
	double second;
    };

public:
    void Init( double l, double r );
    void Read( );
    void Display( );
    bool RangeCheck( double x );

private:
    Pair data_;
};

Data7 make_Data7( double l, double r );

#pragma pack( push, 1 )
struct Pair {
    double first;
    double second;
};
#pragma pack( pop )

int main( )
{
    std::cout << "************* PROGRAMMA PAIR_7 **************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data7 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //1. Init
    Data7 a;
    a.Init( 5, 100 );
    a.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "a MyMethod = " << a.RangeCheck( 50 ) << std::endl;

    //2. Read
    Data7 b;
    b.Read( );
    b.Display( );
    std::cout << "Enter X: ";
    double x = 0;
    std::cin >> x;
    std::cout << std::endl;
    std::cout << std::boolalpha << "b MyMethod = " << b.RangeCheck( x ) << std::endl;

    //3. Make
    Data7 c;
    c = make_Data7( 5000, 400 );
    c.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "c MyMethod = " << c.RangeCheck( 0 ) << std::endl;

    Data7 d = make_Data7( 1000, 1000000 );
    d.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "d MyMethod = " << d.RangeCheck( 1000 ) << std::endl;

    //4. Arrays
    //тоже подойдет
    double nominals[]{ 1.1, 2.2, 5.5, 10.1, 50.5, 100.1, 500.5, 1000.1, 5000.5 };
    Data7 ar[ 9 ];
    for ( int i = 0; i < 9; ++i ) {
	ar[ i ].Init( nominals[ i ], i / 10 );
    }
    for ( int i = 0; i < 9; ++i ) {
	std::cout << i << "  ";
	ar[ i ].Display( );
	std::cout << std::boolalpha << "[] MyMethod = " << ar[ i ].RangeCheck( i ) << std::endl
		  << std::endl;
    }
}

void Data7::Init( double l, double r )
{
    if ( r < l )
	std::swap( l, r );
    data_.first = l;
    data_.second = r;
}

void Data7::Read( )
{
    double a = 0.;
    double b = 0.;
    std::cout << "enter l r" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void Data7::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

bool Data7::RangeCheck( double x )
{
    //[l, r], поэтому включены проверки на краях
    return ( data_.first < x && x < data_.second ) || ( std::abs( data_.first - x ) < 1e-6 ) || ( std::abs( data_.second - x ) < 1e-6 );
}

Data7 make_Data7( double l, double r )
{
    Data7 p;
    p.Init( l, r );
    return p;
}
