#include "widget.h"

#include <QList>
#include <QListView>
#include <QTableView>
#include <QVBoxLayout>

#include "intlistmodel.h"

Widget::Widget( QWidget *parent ) : QWidget( parent ) {
  IntListModel model( QList< int > { } << 123 << 2341 << 32 << 5342 << 723 );
  QListView list;
  list.setModel( &model );
  list.show( );

  QTableView table;
  table.setModel( &model );
  table.show( );

  //  QVBoxLayout box( this );
  //  box.addWidget( &list );
  //  box.addWidget( &table );

  //  setLayout( &box );
}

Widget::~Widget()
{
}

