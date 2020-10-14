#include <iostream>

class Data1 {
    struct Pair {
	double first;
	int32_t second;
    };

public:
    void Init( double a, int32_t b );
    void Read( );
    void Display ( );
    double Power ( );
    double pwr ( double num, int32_t step );

private:
    Pair data_;
};

#pragma pack(push, 1)
struct Pair {
    double first;
    int32_t second;
};
#pragma pack(pop)

Data1 make_data1( double a, int32_t b );

int main()
{
    std::cout << "************* PROGRAMMA PAIR_1 *******************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data1 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //1. Init
    Data1 a;
    a.Init(3.0, 3);
    a.Display();
    std::cout << std::endl;
    std::cout << "a MyMethod = " << a.Power ( ) << std::endl;

    //2. Read
    Data1 b;
    b.Read();
    b.Display();
    std::cout << std::endl;
    std::cout << "b MyMethod = " << b.Power ( ) << std::endl;

    //3. Make
    Data1 c = make_data1( 4.0, 4 );
    c.Display();
    std::cout << std::endl;
    std::cout << "c MyMethod = " << c.Power ( ) << std::endl;

    Data1 d = make_data1( 4.0, -4 );
    c.Display ( );
    std::cout << std::endl;
    std::cout << "d MyMethod = " << d.Power ( ) << std::endl;

    //4. Arrays
    Data1 ar[ 10 ];
    for( int i = 0; i < 10; ++i ){
        ar[i].Init(i + 1, i + 1);
    }
    for( int i = 0; i < 10; ++i ){
        std::cout << i << "  ";
        ar[i].Display();
	std::cout << "[] MyMethod = " << ar[ i ].Power ( ) << std::endl
		  << std::endl;
    }

    return 0;
}

void Data1::Init( double a, int32_t b )
{
    //first, second принадлежат всему диапазону
    data_.first = a;
    data_.second = b;
}

void Data1::Read( )
{
    double a = 0;
    int32_t b = 0;
    std::cout << "Enter num" << std::endl;
    std::cin >> a;
    std::cout << "Enter stepen" << std::endl;
    std::cin >> b;
    // ... проверки a и b ...
    Init(a, b);
}

void Data1::Display ( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

double Data1::Power ( )
{
    if ( data_.second > 0 )
	return pwr ( data_.first, data_.second );
    else
	return std::pow ( data_.first, data_.second );
}

double Data1::pwr ( double num, int32_t step )
{
    //1. степень целое число - быстрое возведение в степень
    if( step == 0 ) return 1.0;
    if( !( step % 2 ) ) return pwr( num * num, step / 2 );
    else return num * pwr( num, step - 1 );
}

Data1 make_data1( double a, int32_t b )
{
    Data1 p;
    p.Init(a,b);
    return p;
}
