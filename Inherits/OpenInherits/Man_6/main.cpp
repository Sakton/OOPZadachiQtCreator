#include "student.h"
#include <iostream>

Man6 & foo( Man6 * obj )
{
    obj->Display( );
    return *obj;
}

int main( )
{
    Man6 *p1, *p2;
    p1 = new Man6( "111", 20, "W", 50 );
    //    p1->Display( );
    //    p1->setAge( 21 );
    //    p1->setWeight( 60 );
    p2 = new Student( "222", 20, "M", 80, 2020 );
    //    p2->Display( );
    //    p2->setSex( "W" );
    //    p2->setWeight( 30 );
    //    p2->Display( );

    foo( p1 );
    foo( p2 );
}
