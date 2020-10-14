#include <iostream>

using namespace std;

class Data10 {
    struct Pair {
	double first;
	double second;
    };

public:
    void Init( double a, int32_t b );
    //void Read( );
    void Display( );

    double Function( double x );

private:
    Pair data_;
};

int main( )
{
    Data10 dt;
    dt.Init( 3, 4 );
    std::cout << dt.Function( 2 );
}

void Data10::Init( double a, int32_t b )
{
    data_.first = a;
    data_.second = b;
}

void Data10::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

double Data10::Function( double x )
{
    return data_.first * x + data_.second;
}
