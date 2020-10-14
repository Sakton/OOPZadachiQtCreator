#include <iostream>

class Data3 {
    struct Pair {
	int64_t first;
	int64_t second;
    };

public:
    void Init( int64_t a, int64_t b );
    void Read( );
    void Display( );
    int64_t Ipart( );

private:
    Pair data_;
};

#pragma pack( push, 1 )
struct Pair {
    int64_t first;
    int64_t second;
};
#pragma pack( pop )

Data3 make_data3( int64_t a, int64_t b );

int main( )
{
    std::cout << "************* PROGRAMMA PAIR_3 **************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data3 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //1. Init
    Data3 a;
    a.Init( 3.0, 3 );
    a.Display( );
    std::cout << std::endl;
    std::cout << "a MyMethod = " << a.Ipart( ) << std::endl;

    //2. Read
    Data3 b;
    b.Read( );
    b.Display( );
    std::cout << std::endl;
    std::cout << "b MyMethod = " << b.Ipart( ) << std::endl;

    //3. Make
    Data3 c = make_data3( 4.0, 4 );
    c.Display( );
    std::cout << std::endl;
    std::cout << "c MyMethod = " << c.Ipart( ) << std::endl;

    Data3 d = make_data3( 4.0, -4 );
    d.Display( );
    std::cout << std::endl;
    std::cout << "d MyMethod = " << d.Ipart( ) << std::endl;

    //4. Arrays
    Data3 ar[ 10 ];
    for ( int i = 0; i < 10; ++i ) {
	ar[ i ].Init( i + 1, i + 1 );
    }
    for ( int i = 0; i < 10; ++i ) {
	std::cout << i << "  ";
	ar[ i ].Display( );
	std::cout << "[] MyMethod = " << ar[ i ].Ipart( ) << std::endl
		  << std::endl;
    }
    return 0;
}

void Data3::Init( int64_t a, int64_t b )
{
    //a,b любые
    data_.first = a;
    data_.second = b;
}

void Data3::Read( )
{
    int64_t a = 0;
    int64_t b = 0;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void Data3::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

int64_t Data3::Ipart( )
{
    if ( data_.second != 0 ) {
	return data_.first / data_.second;
    } else {
	std::cout << " ERROR DIVIDE ZERO!!! " << std::endl;
	exit( 1 );
    }
}

Data3 make_data3( int64_t a, int64_t b )
{
    Data3 t;
    t.Init( a, b );
    return t;
}
