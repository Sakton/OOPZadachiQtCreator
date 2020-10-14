#include <iostream>

class Data20 {
    struct Pair {
	double first;
	double second;
    };

public:
    void Init( double a, double r );
    void Read( );
    void Display( );
    long double ElementJ( int32_t step );

private:
    Pair data_;
};

Data20 make_data20( double a, double r );

#pragma pack( push, 1 )
struct Pair {
    double first;
    double second;
};
#pragma pack( pop )

int main( )
{
    std::cout << "************* PROGRAMMA PAIR_20 **************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data20 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //Init.
    Data20 a;
    a.Init( 0.2, 2 );
    std::cout << "My method = " << a.ElementJ( 10 ) << std::endl;

    //Read.
    //    Data20 b;
    //    b.Read( );
    //    std::cout << "Enter R 0 - x" << std::endl;
    //    int r = 0;
    //    std::cin >> r;
    //    std::cout << "My method = " << b.ElementJ( r ) << std::endl;

    //Make
    Data20 c = make_data20( 0.5, 10 );
    std::cout << "My method = " << c.ElementJ( 10 ) << std::endl;

    //Array
    Data20 arr[ 10 ];
    for ( int i = 0; i < 10; ++i )
	arr[ i ].Init( i + 1, 2 );
    for ( int i = 0; i < 10; ++i ) {
	for ( int j = 0; j < 10; ++j ) {
	    std::cout << arr[ i ].ElementJ( j ) << "  ";
	}
	std::cout << std::endl;
    }

    return 0;
}

void Data20::Init( double a, double r )
{
    //a, r - belong to the whole range of real numbers
    data_.first = a;
    data_.second = r;
}

void Data20::Read( )
{
    std::cout << "Enter a b" << std::endl;
    std::cin >> data_.first >> data_.second;
}

void Data20::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

long double Data20::ElementJ( int32_t step )
{
    if ( step >= 0 )
	return data_.first * std::pow( data_.second, step );
    else {
	std::cout << "ERROR STEPEN" << std::endl;
	exit( 1 );
    }
}

Data20 make_data20( double a, double r )
{
    Data20 p;
    p.Init( a, r );
    return p;
}
