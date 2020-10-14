#include <iostream>

//перетащить в алгоритмы
int powSumm( int x, int n )
{
    if ( n == 1 )
        return x;
    else {
        int res = 0;
        for ( int i = 0; i < x; ++i ) {
            res += powSumm( x, n - 1 );
        }
        return res;
    }
}

int main( )
{
    std::cout << powSumm( 3, 4 );
}
