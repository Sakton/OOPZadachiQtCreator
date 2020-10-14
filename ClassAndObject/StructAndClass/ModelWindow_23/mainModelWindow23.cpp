#include "modelwindow23a.h"
#include "modelwindow23b.h"
#include "modelwindow23c.h"
#include <iostream>

int main( )
{
        std::cout << "Pragma = " << sizeof( ModelWindow23A_T ) << "  No Pragma = " << sizeof( ModelWindow23A ) << std::endl;
        std::cout << "******* PROGRAMMA MODELWINDOW 22 A-A-A ********" << std::endl;
        //GLOBAL DATA - MONITOR
        Monitor MONITOR;

        //Methods demonstration
        ModelWindow23A MA1;
        Init( MONITOR, MA1, "Window_A", { 10, 10 }, 800, 600, ModelWindow23A::Color::GREEN, 1, 1 );
        Display( MA1 );
        SetWidth( MONITOR, MA1, 1000 );
        SetHeight( MONITOR, MA1, 800 );
        MoveX( MONITOR, MA1, -10 );
        MoveY( MONITOR, MA1, -10 );
        SetColor( MA1, ModelWindow23A::Color::BLUE );
        SetVisible( MA1, false );
        SetFrame( MA1, 0 );
        std::cout << "**********change 11111111 change**********" << std::endl;
        Display( MA1 );

        SetWidth( MONITOR, MA1, 1500 );
        SetHeight( MONITOR, MA1, 1000 );
        MoveX( MONITOR, MA1, 30 );
        MoveY( MONITOR, MA1, 30 );
        SetColor( MA1, ModelWindow23A::Color::RED );
        SetVisible( MA1, 1 );
        SetFrame( MA1, 0 );
        std::cout << "**********change 2222222 change**********" << std::endl;
        Display( MA1 );

        std::cout << "******* PROGRAMMA MODELWINDOW 22 B-B-B ********" << std::endl;
        //Methods demonstration
        ModelWindow23B MA2;
        MA2.Init( MONITOR, "Window_A", { 10, 10 }, 800, 600, ModelWindow23B::Color::GREEN, 1, 1 );
        MA2.Display( );
        MA2.SetWidth( 1000 );
        MA2.SetHeight( 800 );
        MA2.MoveX( -10 );
        MA2.MoveY( -10 );
        MA2.SetColor( ModelWindow23B::Color::BLUE );
        MA2.SetVisible( false );
        MA2.SetFrame( 0 );
        std::cout << "**********change 11111111 change**********" << std::endl;
        MA2.Display( );

        MA2.SetWidth( 1500 );
        MA2.SetHeight( 1000 );
        MA2.MoveX( 30 );
        MA2.MoveY( 30 );
        MA2.SetColor( ModelWindow23B::Color::RED );
        MA2.SetVisible( 1 );
        MA2.SetFrame( 0 );
        std::cout << "**********change 2222222 change**********" << std::endl;
        MA2.Display( );

        std::cout << "******* PROGRAMMA MODELWINDOW 22 C-C-C ********" << std::endl;
        //Methods demonstration
        ModelWindow23C MA3;
        MA3.Init( MONITOR, "Window_A", { 10, 10 }, 800, 600, DataModelWindow::Color::GREEN, 1, 1 );
        MA3.Display( );
        MA3.SetWidth( 1000 );
        MA3.SetHeight( 800 );
        MA3.MoveX( -10 );
        MA3.MoveY( -10 );
        MA3.SetColor( DataModelWindow::Color::BLUE );
        MA3.SetVisible( false );
        MA3.SetFrame( 0 );
        std::cout << "**********change 11111111 change**********" << std::endl;
        MA3.Display( );

        MA3.SetWidth( 1500 );
        MA3.SetHeight( 1000 );
        MA3.MoveX( 30 );
        MA3.MoveY( 30 );
        MA3.SetColor( DataModelWindow::Color::RED );
        MA3.SetVisible( 1 );
        MA3.SetFrame( 0 );
        std::cout << "**********change 2222222 change**********" << std::endl;
        MA3.Display( );
    return 0;
}
