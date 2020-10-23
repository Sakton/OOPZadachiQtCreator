#include <iostream>

#include "cursor40b.h"

int main()
{
  Cursor40B cur( 100, 100, Cursor40B::VID::VERTICAL,
                 Cursor40B::CURSOR_SIZE::SZ3, true );
  cur.Display( );
}
