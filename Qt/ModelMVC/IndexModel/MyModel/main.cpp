#include <QApplication>
#include <QList>
#include <QListView>
#include <QTableView>
#include <QVBoxLayout>

#include "intlistmodel.h"
#include "widget.h"

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );
  //  Widget w;
  //  w.show();

  IntListModel model( QList< int > { } << 123 << 2341 << 32 << 5342 << 723 );
  QListView list;
  list.setModel( &model );
  list.show( );

  QTableView table;
  table.setModel( &model );
  table.show( );

  return a.exec( );
}
