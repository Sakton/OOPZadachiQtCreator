#include <iostream>

class Data8 {
public:
    struct Pair {
	int64_t first;
	int64_t second;
    };
    void Init( double l, double r );
    void Read( );
    void Display( );
    bool RangeCheck( int64_t x );

private:
    Pair data_;
};

Data8 make_Data8( double l, double r );

#pragma pack( push, 1 )
struct Pair {
    int64_t l;
    int64_t r;
};
#pragma pack( pop )

int main( )
{
    std::cout << "************* PROGRAMMA PAIR_8 **************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data8 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //1. Init
    Data8 a;
    a.Init( 5, 100 );
    a.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "a MyMethod = " << a.RangeCheck( 50 ) << std::endl;

    //2. Read
    Data8 b;
    b.Read( );
    b.Display( );
    std::cout << "Enter X: ";
    double x = 0;
    std::cin >> x;
    std::cout << std::endl;
    std::cout << std::boolalpha << "b MyMethod = " << b.RangeCheck( x ) << std::endl;

    //3. Make
    Data8 c;
    c = make_Data8( 5000, 400 );
    c.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "c MyMethod = " << c.RangeCheck( 0 ) << std::endl;

    Data8 d = make_Data8( 1000, 1000000 );
    d.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "d MyMethod = " << d.RangeCheck( 1000 ) << std::endl;

    //4. Arrays
    //тоже подойдет
    int64_t nominals[]{ 1, 2, 5, 10, 50, 100, 500, 1000, 5000 };
    Data8 ar[ 9 ];
    for ( int i = 0; i < 9; ++i ) {
	ar[ i ].Init( -nominals[ i ] * 10, i * 10000 );
    }
    for ( int i = 0; i < 9; ++i ) {
	std::cout << i << "  ";
	ar[ i ].Display( );
	std::cout << std::boolalpha << "[] MyMethod = " << ar[ i ].RangeCheck( i ) << std::endl
		  << std::endl;
    }
}

void Data8::Init( double l, double r )
{
    //l, r - весь диапазон
    data_.first = l;
    data_.second = r;
}

void Data8::Read( )
{
    int64_t a, b;
    std::cout << "Enter l, r" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void Data8::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

bool Data8::RangeCheck( int64_t x )
{
    return ( data_.first < x && x <= data_.second );
}

Data8 make_Data8( double l, double r )
{
    Data8 p;
    p.Init( l, r );
    return p;
}
