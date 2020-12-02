#include "widget.h"

#include <QHBoxLayout>
#include <QItemSelectionModel>
#include <QListView>
#include <QStringListModel>
#include <QTableView>
#include <QTreeView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
  QStringListModel *model = new QStringListModel( this );
  QStringList list;
  list << "Item1"
       << "Item2"
       << "Item3";
  model->setStringList( list );

  QListView *lw = new QListView;
  QTreeView *trw = new QTreeView;
  QTableView *tbw = new QTableView;

  //живут сами по себе
  lw->setModel( model );
  trw->setModel( model );
  tbw->setModel( model );

  //обьект выделения (теперь выделяются синхронно)
  // скорее всего тут паттерн "наблюдатель"
  QItemSelectionModel *itemModel = new QItemSelectionModel( model );
  lw->setSelectionModel( itemModel );
  trw->setSelectionModel( itemModel );
  tbw->setSelectionModel( itemModel );

  QHBoxLayout *box = new QHBoxLayout( this );
  box->addWidget( lw );
  box->addWidget( trw );
  box->addWidget( tbw );

  setLayout( box );
}

Widget::~Widget()
{
}

