#include <iostream>

class Data6 {
    struct Pair {
	uint32_t first;
	double second;
    };

public:
    void Init( int32_t ccal, double mass );
    void Read( );
    void Display( );
    double Power( );

private:
    Pair data_;
};

#pragma pack( push, 1 )
struct Pair {
    uint32_t first;
    double second;
};
#pragma pack( pop )

Data6 make_Data6( int32_t ccal, double mass );

int main( )
{

    std::cout << "************* PROGRAMMA PAIR_6 **************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data6 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //1. Init
    Data6 a;
    a.Init( 5, 100 );
    a.Display( );
    std::cout << std::endl;
    std::cout << "a MyMethod = " << a.Power( ) << std::endl;

    //2. Read
    Data6 b;
    b.Read( );
    b.Display( );
    std::cout << std::endl;
    std::cout << "b MyMethod = " << b.Power( ) << std::endl;

    //3. Make
    Data6 c;
    c = make_Data6( 5000, 400 );
    c.Display( );
    std::cout << std::endl;
    std::cout << "c MyMethod = " << c.Power( ) << std::endl;

    Data6 d = make_Data6( 1000, 1000000 );
    d.Display( );
    std::cout << std::endl;
    std::cout << "d MyMethod = " << d.Power( ) << std::endl;

    //4. Arrays
    //тоже подойдет
    double nominals[]{ 1.1, 2.2, 5.5, 10.1, 50.5, 100.1, 500.5, 1000.1, 5000.5 };
    Data6 ar[ 9 ];
    for ( int i = 0; i < 9; ++i ) {
	ar[ i ].Init( nominals[ i ], 100 );
    }
    for ( int i = 0; i < 9; ++i ) {
	std::cout << i << "  ";
	ar[ i ].Display( );
	std::cout << "[] MyMethod = " << ar[ i ].Power( ) << std::endl
		  << std::endl;
    }

    return 0;
}

void Data6::Init( int32_t ccal, double mass )
{
    if ( ccal < 0 || mass < 0 ) {
	std::cout << "ERROR ARG";
	exit( 1 );
    }
    data_.first = ccal;
    data_.second = mass;
}

void Data6::Read( )
{
    int32_t a = 0;
    double b = 0;
    std::cout << "ENTER a, b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void Data6::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

double Data6::Power( )
{
    return data_.first * data_.second / 1000;
}

Data6 make_Data6( int32_t ccal, double mass )
{
    Data6 p;
    p.Init( ccal, mass );
    return p;
}
