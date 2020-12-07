#include "intlistmodel.h"

IntListModel::IntListModel( const QList< int >& list, QObject* pObj ) : QAbstractListModel { pObj }, m_list { list } {}

int IntListModel::rowCount( const QModelIndex& parent ) const {
  if ( parent.isValid( ) ) {  // TODO ВАЖНО !!!!!
    return 0;
  }
  return m_list.size( );
}

QVariant IntListModel::data( const QModelIndex& index, int role ) const {
  if ( !index.isValid( ) ) return QVariant { };
  if ( index.row( ) < 0 || m_list.size( ) < index.row( ) ) return QVariant { };
  return ( role == Qt::DisplayRole || role == Qt::EditRole ) ? m_list.at( index.row( ) ) : QVariant { };
}

bool IntListModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
  if ( index.isValid( ) && role == Qt::EditRole ) {
    m_list.replace( index.row( ), value.value< int >( ) );
    emit dataChanged( index, index );
    return true;
  }
  return false;
}

QVariant IntListModel::headerData( int section, Qt::Orientation orientation, int role ) const {
  if ( role != Qt::DisplayRole ) return QVariant { };
  return ( orientation == Qt::Horizontal ) ? QString( "Number" ) : QString::number( section );
}

bool IntListModel::insertRows( int row, int count, const QModelIndex& parent ) {
  if ( parent.isValid( ) ) return false;
  beginInsertRows( QModelIndex { }, row, row + count - 1 );  //оповещение о вставке
  for ( int i = 0; i < count; ++i ) m_list.insert( row, 0 );
  endInsertRows( );  // оповещение о конце вставки
  return true;
}

bool IntListModel::removeRows( int row, int count, const QModelIndex& parent ) {
  if ( parent.isValid( ) ) return false;
  beginRemoveRows( QModelIndex { }, row, row + count - 1 );  //оповещение о удалении
  for ( int i = 0; i < count; ++i ) m_list.removeAt( row );
  endRemoveRows( );  // оповещение о конце удаления
  return true;
}

Qt::ItemFlags IntListModel::flags( const QModelIndex& index ) const {
  // возвращает свойства элемента определенные флагами
  Qt::ItemFlags flag = QAbstractListModel::flags( index );
  // если индекс валидный разрешаем редактирование
  return index.isValid( ) ? ( flag | Qt::ItemIsEditable ) : flag;
}
