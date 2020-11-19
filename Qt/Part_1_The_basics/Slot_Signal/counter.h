#ifndef COUNTER_H
#define COUNTER_H
#include <QObject>

class Counter : public QObject {
  Q_OBJECT
 public:
  Counter( QObject *parent = nullptr, int32_t v = 0 );

 public slots:
  void slotInc( );

 signals:
  void goodbye( );
  void counterChanged( int32_t );

 private:
  int32_t m_value_;
};

#endif // COUNTER_H
