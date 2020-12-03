#include "delegate.h"

#include <QListView>
#include <QStringListModel>

#include "simpledelegate.h"

Delegate::Delegate( QWidget *parent ) : QWidget( parent ) {
  QStringListModel *model = new QStringListModel( this );
  model->setStringList( QStringList( ) << "Item1"
                                       << "Item2"
                                       << "Item3" );

  QListView *lw = new QListView( this );
  lw->setModel( model );
  lw->setItemDelegate( new SimpleDelegate( lw ) );
  lw->viewport( )->setAttribute( Qt::WA_Hover );
}

Delegate::~Delegate( ) {}
