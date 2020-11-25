#include "scrollbar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ScrollBar w;
  w.show();
  return a.exec();
}
