#include "progressbar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ProgressBar w;
  w.show();
  return a.exec();
}
