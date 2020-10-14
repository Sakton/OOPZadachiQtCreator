#include "BitString.h"
#include <iostream>

int main()
{
    try {
        BitString bs( "001100110011" );
        bs.Display( );
        bs <<= 2;
        bs.Display( );

    } catch ( ... ) {
        std::cout << "ERROE";
    }
}
