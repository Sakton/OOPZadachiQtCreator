#include "Windows.h"
#include "dictionary.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    //    SetConsoleCP( 1251 );
    //    SetConsoleOutputCP( 1251 );

    try {
        Dictionary d(L"���������� �������");
        std::wcout << "  " << d.nameDict( ) << std::endl;

        d.AddWordcard( L"tree", L"������" );
        d.AddWordcard(L"deep", L"��������");
        d.AddWordcard(L"transitions", L"�������");
        d.AddWordcard(L"drouth", L"������");
        d.AddWordcard(L"adapt", L"�����������");
        d.Display();
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        //d.sortLess( );
        d.Remove( L"adapt", L"�����������" );
        d.Display();
        std::cout << "Size = " << d.Size( ) << std::endl;
        std::cout << std::endl;
        d.Remove( L"deep", L"��������" );
        d.Display( );
        std::cout << "Size = " << d.Size( ) << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        d.AddWordcard( L"drawback", L"����������" );
        d.AddWordcard( L"keyboard", L"����������" );
        std::cout << "Size = " << d.Size( ) << std::endl;
        d.Display( );
        d.AddWordcard( L"test", L"����" );
        d.AddWordcard( L"test1", L"����1" );
        d.AddWordcard( L"test2", L"����2" );
        d.AddWordcard( L"test3", L"����3" );
        d.AddWordcard( L"test3", L"����3" );
        d.AddWordcard( L"test3", L"����3" );
        d.AddWordcard( L"test3", L"����3" );
        d.AddWordcard( L"test3", L"����3" );
        std::cout << "Size = " << d.Size( ) << std::endl;
        d.Display( );
        std::cout << std::endl;
        std::cout << std::endl;
        d.sortLess( );
        d.Display( );
        std::cout << "************" << std::endl;

        std::cout << std::endl;

        Dictionary c( L"���������� ������� 2" );
        std::wcout << "  " << c.nameDict( ) << std::endl;
        c.AddWordcard( L"binary", L"��������" );
        c.AddWordcard( L"cash", L"���" );
        c.AddWordcard( L"edit", L"�������������" );
        c.AddWordcard( L"while", L"����" );
        c.AddWordcard( L"interface", L"���������" );
        c.Display( );
        c.AddWordcard( L"test", L"����" );
        c.AddWordcard( L"test1", L"����1" );
        c.AddWordcard( L"test2", L"����2" );
        c.AddWordcard( L"test3", L"����3" );
        c.AddWordcard( L"test3", L"����3" );
        c.AddWordcard( L"test3", L"����3" );
        c.AddWordcard( L"test3", L"����3" );
        c.AddWordcard( L"test3", L"����3" );
        //        ////d.sortLess();
        c.Display( );

        std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;

        std::cout << std::endl;
        std::cout << std::endl;

        d.Display( );
        std::cout << std::endl;
        std::cout << std::endl;

        c.Display( );
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "**********INTERSECTION*************" << std::endl;
        Dictionary res = d.Intersection( c );
        res.Display( );
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "**********   +++++  *************" << std::endl;
        Dictionary res1 = d + c;
        res1.Display( );
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "**********   -----  *************" << std::endl;
        Dictionary res2 = d - c;
        res2.Display( );

    } catch ( ... ) {
        std::cout << "ERROR";
    }
}
