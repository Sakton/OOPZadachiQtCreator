#include <QByteArray>
#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include <iostream>

int main(int argc, char *argv[])
{
  QCoreApplication a( argc, argv );

  QByteArray b( "ПРИВЕТ" );
  QTextCodec::setCodecForLocale( QTextCodec::codecForName( "IBM 866" ) );
  std::cout << QString::fromUtf8( b ).toLocal8Bit( ).data( );

  return a.exec( );
}
