#include <iostream>

class Data9 {
public:
    struct Pair {
	int16_t first;
	int16_t second;
    };

    void Init( int16_t h, int16_t m );
    void Read( );
    void Display( );
    int32_t Minutes( );

private:
    Pair data_;
};

Data9 make_Data9( int16_t h, int16_t m );

#pragma pack( push, 1 )
struct Pair {
    int16_t first;
    int16_t second;
};
#pragma pack( pop )

int main( )
{

    std::cout << "************* PROGRAMMA PAIR_9 **************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data9 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //1. Init
    Data9 a;
    a.Init( 5, 0 );
    a.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "a MyMethod = " << a.Minutes( ) << std::endl;

    //2. Read
    Data9 b;
    b.Read( );
    b.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "b MyMethod = " << b.Minutes( ) << std::endl;

    //3. Make
    Data9 c;
    c = make_Data9( 50, 40 );
    c.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "c MyMethod = " << c.Minutes( ) << std::endl;

    Data9 d = make_Data9( 10, 10 );
    d.Display( );
    std::cout << std::endl;
    std::cout << std::boolalpha << "d MyMethod = " << d.Minutes( ) << std::endl;

    //4. Arrays
    //тоже подойдет
    int64_t nominals[]{ 1, 2, 5, 10, 50, 45, 55, 11, 15 };
    Data9 ar[ 9 ];
    for ( int i = 0; i < 9; ++i ) {
	ar[ i ].Init( -nominals[ i ], i );
    }
    for ( int i = 0; i < 9; ++i ) {
	std::cout << i << "  ";
	ar[ i ].Display( );
	std::cout << std::boolalpha << "[] MyMethod = " << ar[ i ].Minutes( ) << std::endl
		  << std::endl;
    }
}

void Data9::Init( int16_t h, int16_t m )
{
    if ( !( 0 <= h && h < 24 ) || !( 0 <= m && m < 60 ) ) {
	std::cout << "ERROR ARG INIT";
	exit( 1 );
    }

    data_.first = h;
    data_.second = m;
}

void Data9::Read( )
{
    int16_t a, b;
    std::cout << "Enter a, b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void Data9::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

int32_t Data9::Minutes( )
{
    return data_.first * 60 + data_.second;
}

Data9 make_Data9( int16_t h, int16_t m )
{
    Data9 p;
    p.Init( h, m );
    return p;
}
