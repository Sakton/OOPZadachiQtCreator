#include "saves.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Saves w;
  w.show();
  return a.exec();
}
