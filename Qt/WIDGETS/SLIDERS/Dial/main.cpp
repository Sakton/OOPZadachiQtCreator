#include "dial.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Dial w;
  w.show();
  return a.exec();
}
