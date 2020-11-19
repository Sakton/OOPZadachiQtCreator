#ifndef MYSLOT_H
#define MYSLOT_H

#include <QObject>

class MySlot : public QObject
{
  Q_OBJECT
 public:
  explicit MySlot( QObject *parent = nullptr );

 public slots:
  void slot( );
  void stringSlot( const QString &str );
};

#endif // MYSLOT_H
