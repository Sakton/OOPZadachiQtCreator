#include "widget.h"

#include <QStandardItemModel>
#include <QTreeView>

Widget::Widget( QWidget *parent ) : QWidget( parent ) {
  QStandardItemModel *model = new QStandardItemModel( 5, 3 );
  for ( int nTopRow = 0; nTopRow < 5; ++nTopRow ) {
    QModelIndex index = model->index( nTopRow, 0 );                    //индекс верхней модели
    model->setData( index, "item" + QString::number( nTopRow + 1 ) );  //установка значения в верхней модели

    model->insertRows( 0, 4, index );  // index - родительский индекс таблицы
    model->insertColumns( 0, 3, index );

    for ( int nRow = 0; nRow < 4; ++nRow ) {
      for ( int nCol = 0; nCol < 3; ++nCol ) {
        QString strPos = QString( "%1, %2" ).arg( nRow ).arg( nCol );
        model->setData( model->index( nRow, nCol, index ), strPos );
      }
    }
  }

  QTreeView *tree = new QTreeView( this );
  tree->resize( 500, 400 );
  tree->setModel( model );
}

Widget::~Widget()
{
}

