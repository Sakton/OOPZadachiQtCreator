#include "vgt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Vgt w;

  w.show();
  return a.exec();
}
