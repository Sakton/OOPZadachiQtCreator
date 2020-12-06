#include "widgetfilesystem.h"

#include <QFileSystemModel>
#include <QSplitter>
#include <QTableView>
#include <QTreeView>

WidgetFileSystem::WidgetFileSystem( QWidget *parent ) : QWidget( parent ) {
  resize( 1600, 800 );
  QFileSystemModel *fModel = new QFileSystemModel;
  fModel->setRootPath( QDir::rootPath( ) );
  QTreeView *tree = new QTreeView( this );
  tree->resize( 800, 600 );
  tree->setModel( fModel );

  QTableView *table = new QTableView;
  table->resize( 800, 600 );
  table->setModel( fModel );

  //высланный индекс при клике устанавливается в качестве родительского в табличном представлении
  //табличное представление отображает только содержимое папки
  connect( tree, QOverload< const QModelIndex & >::of( &QTreeView::clicked ), table,
           QOverload< const QModelIndex & >::of( &QTableView::setRootIndex ) );

  //при выборе в табличной модели каталога, сообщаем в древовиное представление его индекс для выделения
  connect( table, QOverload< const QModelIndex & >::of( &QTableView::activated ), tree,
           QOverload< const QModelIndex & >::of( &QTreeView::setCurrentIndex ) );

  // переключение в самой таблице
  connect( table, QOverload< const QModelIndex & >::of( &QTableView::activated ), table,
           QOverload< const QModelIndex & >::of( &QTableView::setRootIndex ) );

  QSplitter *sp = new QSplitter( this );
  sp->setGeometry( geometry( ) );
  sp->addWidget( tree );
  sp->addWidget( table );
}

WidgetFileSystem::~WidgetFileSystem()
{
}

