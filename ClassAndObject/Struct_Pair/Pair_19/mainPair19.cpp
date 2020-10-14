#include <iostream>

class Data19 {
    struct Pair {
	int32_t first;
	int32_t second;
    };

public:
    void Init( int32_t a, int32_t b );
    void Read( );
    void Display( );
    uint64_t Combination( );
    Pair GetData( ) const;

private:
    Pair data_;
};

Data19 make_data19( int32_t a, int32_t b );

#pragma pack( push, 1 )
struct Pair {
    int32_t first;
    int32_t second;
};
#pragma pack( pop )

int main()
{

    std::cout << "************* PROGRAMMA PAIR_19 **************" << std::endl;
    std::cout << "1: Sizes no pragma: " << sizeof( Data19 ) << "  with pragma: " << sizeof( Pair ) << std::endl;

    //1. Init
    Data19 a;
    a.Init( 100, 13 );
    a.Display( );
    std::cout << " a Combination = " << a.Combination( ) << std::endl;

    //2. Read
    //    Data19 b;
    //    char stop = ' ';
    //    do {
    //	b.Read( );
    //	std::cout << " b Combination = " << b.Combination( ) << std::endl;
    //	std::cout << " stop? Y  " << std::endl;
    //	std::cin >> stop;
    //    } while ( stop != 'Y' );

    //3. Make
    Data19 c = make_data19( 10, 3 );
    c.Display( );
    std::cout << " a Combination = " << c.Combination( ) << std::endl;

    //4. Arrays
    //имимтация коэффициентов в разложении бинома (a + b)^n

    Data19 arr[ 14 ];
    for ( int i = 0; i <= 13; ++i )
	arr[ i ].Init( 13, 13 - i );
    for ( int i = 0; i <= 13; ++i )
	std::cout << "( " << arr[ i ].Combination( ) << "* a^" << arr[ i ].GetData( ).first << " * b^" << arr[ i ].GetData( ).second << " ) + " << std::endl;
    return 0;
}

void Data19::Init( int32_t a, int32_t b )
{
    if ( a < 0 || b < 0 ) {
	std::cout << "ERROR DATA" << std::endl;
	exit( 1 );
    } else {
	data_.first = a;
	data_.second = b;
    }
}

void Data19::Read( )
{
    int32_t a = 0;
    int32_t b = 0;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void Data19::Display( )
{
    std::cout << "Display "
	      << "f: " << data_.first << " :: s: " << data_.second;
}

uint64_t Data19::Combination( )
{
    //нахождение количества комбинаций = C(n, k) = n! / (k!(n - k)!)
    //если цифры перепутаны меняем их местами
    //если они равны то то вариатов выбора - 1 - выбрать все элементы, или же если k = 0, то вариантов выбора тоже 1 - ничего не выбирать
    //числитель сокращается с максимальным из факториалов в знаменателе - значение start
    //выбирает число после сокращения факториалов исходя из сокращения наибольшего (это предусловия, это как бы проделано на бумажке)
    //тоесть в числителе имеем (n - k + 1)*(n - k + 2)*...*(n - 1)*n
    //Алгоритм умножения: умножаем на верхний факториал пока полученное число не будет делится без остатка на знаменатель
    //когда делится - делим его и увеличиваем знаменатель на 1 - имитируя факториал в знаменателе
    //тогда в наменателе будет
    //1. 1 * 2 * .... *(n - k - 1) при (( n - k ) < k ) - тоесть в скобках факториал меньше ( например С(10, 7) )
    //2. 1 * 2 * .....*(k - 1) * k - (( n - k ) > k ) - k меньше ( например С(10, 3) )
    //идея в том что при вычислении сочетаний всегда получится целое число.

    int64_t n = data_.first;
    int64_t k = data_.second;
    if ( k == 0 || k == n ) {
	return 1;
    }
    if ( n < k )
	std::swap( n, k );
    int64_t start = ( ( n - k ) < k ) ? ( k + 1 ) : ( n - k + 1 );
    int64_t res = 1;
    for ( int64_t i = start, j = 1; i <= n && j <= k; ++i ) {
	res *= i;
	if ( res % j == 0 ) {
	    res /= j;
	    ++j;
	}
    }
    return res;
}

Data19::Pair Data19::GetData( ) const
{
    return data_;
}

//uint64_t Data19::Combination( )
//{
//    int n = data_.first;
//    int k = data_.second;
//    int64_t chislitel = 1;
//    for ( int64_t i = n - k + 1; i <= n; ++i ) {
//	chislitel *= i;
//    }
//    int znamenatel = 1;
//    for ( int64_t j = 2; j <= k; ++j ) {
//	znamenatel *= j;
//    }
//    return chislitel / znamenatel;
//}

Data19 make_data19( int32_t a, int32_t b )
{
    Data19 p;
    p.Init( a, b );
    return p;
}
