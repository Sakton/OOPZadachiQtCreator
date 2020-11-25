#include "labelhtml.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  LabelHtml w;
  w.show();
  return a.exec();
}
