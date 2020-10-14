#include <iostream>

class Data4 {
    struct Pair {
	uint16_t first;
	uint64_t second;
    };

public:
    void Init( int16_t a, int64_t b );
    void Read( );
    void Display( );
    int64_t Summa( );

private:
    Pair data_;
};

#pragma pack( push, 1 )
struct Pair {
    uint16_t first;
    uint64_t second;
};
#pragma pack( pop )

Data4 make_data4( int16_t a, int64_t b );

int main( )
{
    std::cout << "************* PROGRAMMA PAIR_4 **************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data4 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //1. Init
    Data4 a;
    a.Init( 5, 100 );
    a.Display( );
    std::cout << std::endl;
    std::cout << "a MyMethod = " << a.Summa( ) << std::endl;

    //2. Read
    Data4 b;
    b.Read( );
    b.Display( );
    std::cout << std::endl;
    std::cout << "b MyMethod = " << b.Summa( ) << std::endl;

    //3. Make
    Data4 c = make_data4( 5000, 400 );
    c.Display( );
    std::cout << std::endl;
    std::cout << "c MyMethod = " << c.Summa( ) << std::endl;

    Data4 d = make_data4( 1000, 1000000 );
    d.Display( );
    std::cout << std::endl;
    std::cout << "d MyMethod = " << d.Summa( ) << std::endl;

    //4. Arrays
    int16_t nominals[]{ 1, 2, 5, 10, 50, 100, 500, 1000, 5000 };
    Data4 ar[ 9 ];
    for ( int i = 0; i < 9; ++i ) {
	ar[ i ].Init( nominals[ i ], 1000000 );
    }
    for ( int i = 0; i < 9; ++i ) {
	std::cout << i << "  ";
	ar[ i ].Display( );
	std::cout << "[] MyMethod = " << ar[ i ].Summa( ) << std::endl
		  << std::endl;
    }

    return 0;
}

void Data4::Init( int16_t a, int64_t b )
{
    switch ( a ) {
	case 1:
	case 2:
	case 5:
	case 10:
	case 50:
	case 100:
	case 500:
	case 1000:
	case 5000:
	    data_.first = a;
	    break;
	default: {
	    std::cout << "ERROR NOMINALS" << std::endl;
	    exit( 1 );
	}
    }
    if ( 0 <= b )
	data_.second = b;
    else {
	std::cout << "ERROR COUNTS" << std::endl;
	exit( 1 );
    }
}

void Data4::Read( )
{
    int16_t a = 0;
    int64_t b = 0;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void Data4::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

int64_t Data4::Summa( )
{
    return data_.first * data_.second;
}

Data4 make_data4( int16_t a, int64_t b )
{
    Data4 p;
    p.Init( a, b );
    return p;
}
