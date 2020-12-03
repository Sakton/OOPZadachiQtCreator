#include "simpledelegate.h"

#include <QPainter>

SimpleDelegate::SimpleDelegate( QObject* parent ) : QStyledItemDelegate( parent ) {}

// QStyleOptionViewItem содержит всю информацию, которая необходима функциям
// QStyle для рисования элементов для классов модели / представления Qt.
void SimpleDelegate::paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index ) const {
  if ( option.state & QStyle::State_MouseOver ) {
    QLinearGradient gradient( 0, 0, option.rect.width( ), option.rect.height( ) );
    gradient.setColorAt( 0, Qt::white );
    gradient.setColorAt( 0.5, Qt::blue );
    gradient.setColorAt( 1, Qt::green );

    painter->setBrush( gradient );
    painter->drawRect( option.rect );
  }
  QStyledItemDelegate::paint( painter, option, index );
}

QSize SimpleDelegate::sizeHint( const QStyleOptionViewItem& option, const QModelIndex& index ) const {
  return QSize( option.rect.width( ), 35 );
  Q_UNUSED( index )
}
