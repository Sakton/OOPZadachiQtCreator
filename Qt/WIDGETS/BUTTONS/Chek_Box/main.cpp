#include "chekbox.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ChekBox w;
  w.show();
  return a.exec();
}
