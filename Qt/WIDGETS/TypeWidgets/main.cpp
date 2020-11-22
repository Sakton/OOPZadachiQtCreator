#include "typewidgets.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TypeWidgets w;
  // w.setWindowFlags( Qt::WindowTitleHint );
  // w.setWindowFlags( Qt::WindowCloseButtonHint );
  // w.setWindowFlags( Qt::WindowTitleHint );
  // w.setWindowFlags( Qt::WindowContextHelpButtonHint );
  // w.setWindowFlags( Qt::WindowStaysOnBottomHint );
  w.show();
  return a.exec();
}
