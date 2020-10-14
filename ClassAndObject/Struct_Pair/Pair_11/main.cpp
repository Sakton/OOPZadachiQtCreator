#include <iostream>

class Data11 {
    struct Pair {
	double first;
	double second;
    };

public:
    void Init( double a, int32_t b );
    //void Read( );
    void Display( );

    double Root( double x );

private:
    Pair data_;
};

int main( )
{
    Data11 dt;
    dt.Init( 3, 4 );
    std::cout << dt.Root( 2 );
}

void Data11::Init( double a, int32_t b )
{
    data_.first = a;
    data_.second = b;
}

void Data11::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

double Data11::Root( double x )
{
    if ( !data_.second ) {
	std::cout << "ERROR";
	exit( 1 );
    }
    return -data_.first / data_.second;
}
