#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>

class Counter : public QObject {
  Q_OBJECT

 public:
  Counter( QObject *parent = nullptr, int32_t v = 0 );
  ~Counter( );

 signals:
  void goodbye( );
  void counterChanged( int, int );

 public slots:
  void slotInc( );

 private:
  int32_t m_value;
};
#endif // COUNTER_H
