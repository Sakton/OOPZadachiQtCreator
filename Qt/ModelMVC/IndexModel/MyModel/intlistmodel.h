#ifndef INTLISTMODEL_H
#define INTLISTMODEL_H
#include <QAbstractListModel>

class IntListModel : public QAbstractListModel {
 public:
  IntListModel( const QList< int > &list, QObject *pObj = nullptr );

  // QAbstractItemModel interface
 public:
  int rowCount( const QModelIndex &parent ) const override;
  QVariant data( const QModelIndex &index, int role ) const override;
  bool setData( const QModelIndex &index, const QVariant &value, int role ) override;
  QVariant headerData( int section, Qt::Orientation orientation, int role ) const override;
  bool insertRows( int row, int count, const QModelIndex &parent ) override;
  bool removeRows( int row, int count, const QModelIndex &parent ) override;
  Qt::ItemFlags flags( const QModelIndex &index ) const override;

 private:
  QList< int > m_list;
};

#endif // INTLISTMODEL_H
