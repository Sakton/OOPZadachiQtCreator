#include "pushbuttons.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  PushButtons w;
  w.show();
  return a.exec();
}
