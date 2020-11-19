#ifndef MYSIGNAL_H
#define MYSIGNAL_H
#include <QObject>
#include <QString>

class MySignal : public QObject {
  Q_OBJECT
 public:
  MySignal( QObject* parent = nullptr );
  void sendSignal( );

 signals:
  void doIt( );
  void sendString( const QString& );
};

#endif // MYSIGNAL_H
