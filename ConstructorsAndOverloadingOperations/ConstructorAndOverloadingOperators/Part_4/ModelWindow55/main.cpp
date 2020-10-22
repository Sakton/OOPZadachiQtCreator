#include <iostream>

#include "ModellingMonitor.h"
#include "modelwindow.h"

using namespace std;

int main( ) {
  Monitor m;
  ModelWindow mw( m, "Myname", ModelWindow::Pair { 0, 0 }, 800, 600,
                  ModelWindow::Color::RED, true, true,
                  Cursor40B( 100, 100, Cursor40B::VID::HORIZONTAL,
                             Cursor40B::CURSOR_SIZE::SZ3, true ) );

  mw.Display( );
}
