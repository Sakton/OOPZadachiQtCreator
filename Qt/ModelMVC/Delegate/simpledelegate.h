#ifndef SIMPLEDELEGATE_H
#define SIMPLEDELEGATE_H
#include <QStyledItemDelegate>

class SimpleDelegate : public QStyledItemDelegate {
 public:
  SimpleDelegate( QObject* parent = nullptr );

  // QAbstractItemDelegate interface
 public:
  void paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index ) const override;
  QSize sizeHint( const QStyleOptionViewItem& option, const QModelIndex& index ) const override;
};

#endif // SIMPLEDELEGATE_H
