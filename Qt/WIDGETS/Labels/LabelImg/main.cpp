#include <QApplication>
#include <QLabel>

#include "imglabel.h"

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );
  //  ImgLabel w;
  //  w.show();
  QLabel *label = new QLabel;
  QPixmap pixmap( "E:/CPP/MyProects/OOPZadachiCreatorQt/OOPZadachiQtCreator/Qt/15487.png" );
  label->resize( pixmap.size( ) );
  label->setPixmap( pixmap );
  label->show( );
  return a.exec();
}
