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
        Dictionary d(L"ангельский словарь");
        std::wcout << "  " << d.nameDict( ) << std::endl;

        d.AddWordcard( L"tree", L"Дерево" );
        d.AddWordcard(L"deep", L"Глубокий");
        d.AddWordcard(L"transitions", L"Переход");
        d.AddWordcard(L"drouth", L"Засуха");
        d.AddWordcard(L"adapt", L"Настраивать");
        d.Display();
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        //d.sortLess( );
        d.Remove( L"adapt", L"Настраивать" );
        d.Display();
        std::cout << "Size = " << d.Size( ) << std::endl;
        std::cout << std::endl;
        d.Remove( L"deep", L"Глубокий" );
        d.Display( );
        std::cout << "Size = " << d.Size( ) << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        d.AddWordcard( L"drawback", L"недостаток" );
        d.AddWordcard( L"keyboard", L"клавиатура" );
        std::cout << "Size = " << d.Size( ) << std::endl;
        d.Display( );
        d.AddWordcard( L"test", L"тест" );
        d.AddWordcard( L"test1", L"тест1" );
        d.AddWordcard( L"test2", L"тест2" );
        d.AddWordcard( L"test3", L"тест3" );
        d.AddWordcard( L"test3", L"тест3" );
        d.AddWordcard( L"test3", L"тест3" );
        d.AddWordcard( L"test3", L"тест3" );
        d.AddWordcard( L"test3", L"тест3" );
        std::cout << "Size = " << d.Size( ) << std::endl;
        d.Display( );
        std::cout << std::endl;
        std::cout << std::endl;
        d.sortLess( );
        d.Display( );
        std::cout << "************" << std::endl;

        std::cout << std::endl;

        Dictionary c( L"ангельский словарь 2" );
        std::wcout << "  " << c.nameDict( ) << std::endl;
        c.AddWordcard( L"binary", L"Двоичный" );
        c.AddWordcard( L"cash", L"Кэш" );
        c.AddWordcard( L"edit", L"Редактировать" );
        c.AddWordcard( L"while", L"Пока" );
        c.AddWordcard( L"interface", L"Интерфейс" );
        c.Display( );
        c.AddWordcard( L"test", L"тест" );
        c.AddWordcard( L"test1", L"тест1" );
        c.AddWordcard( L"test2", L"тест2" );
        c.AddWordcard( L"test3", L"тест3" );
        c.AddWordcard( L"test3", L"тест3" );
        c.AddWordcard( L"test3", L"тест3" );
        c.AddWordcard( L"test3", L"тест3" );
        c.AddWordcard( L"test3", L"тест3" );
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
