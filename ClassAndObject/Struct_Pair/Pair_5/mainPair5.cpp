#include <iostream>
#include <string>

class Data5 {
    struct Pair {
	double first;
	uint32_t second;
    };

public:
    void Init( double price, int32_t count );
    void Read( );
    void Display( );
    double Cost( );

private:
    Pair data_;
};

Data5 make_data5( double price, int32_t count );

#pragma pack( push, 1 )
struct Pair {
    double first;
    uint32_t second;
};
#pragma pack( pop )

int main( )
{

    std::cout << "************* PROGRAMMA PAIR_5 **************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data5 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //1. Init
    Data5 a;
    a.Init( 5, 100 );
    a.Display( );
    std::cout << std::endl;
    std::cout << "a MyMethod = " << a.Cost( ) << std::endl;

    //2. Read
    Data5 b;
    b.Read( );
    b.Display( );
    std::cout << std::endl;
    std::cout << "b MyMethod = " << b.Cost( ) << std::endl;

    //3. Make
    Data5 c;
    c = make_data5( 5000, 400 );
    c.Display( );
    std::cout << std::endl;
    std::cout << "c MyMethod = " << c.Cost( ) << std::endl;

    Data5 d = make_data5( 1000, 1000000 );
    d.Display( );
    std::cout << std::endl;
    std::cout << "d MyMethod = " << d.Cost( ) << std::endl;

    //4. Arrays
    //тоже подойдет
    int16_t nominals[] { 1, 2, 5, 10, 50, 100, 500, 1000, 5000 };
    Data5 ar[ 9 ];
    for ( int i = 0; i < 9; ++i ) {
	ar[ i ].Init( nominals[ i ], 1000 );
    }
    for ( int i = 0; i < 9; ++i ) {
	std::cout << i << "  ";
	ar[ i ].Display( );
	std::cout << "[] MyMethod = " << ar[ i ].Cost( ) << std::endl
		  << std::endl;
    }

    return 0;
}

void Data5::Init( double price, int32_t count )
{
    if ( price < 0 || count < 0 ) {
	std::cout << "ERROR ARGUMENTS" << std::endl;
	exit( 1 );
    } else {
	data_.first = price;
	data_.second = count;
    }
}

void Data5::Read( )
{
    double a = 0;
    int32_t b = 0;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void Data5::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

double Data5::Cost( )
{
    return data_.first * data_.second;
}

Data5 make_data5( double price, int32_t count )
{
    Data5 p;
    p.Init( price, count );
    return p;
}
