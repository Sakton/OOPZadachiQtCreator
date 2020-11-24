#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

class QLCDNumber;

class Calculator : public QWidget
{
  Q_OBJECT

 public:
  explicit Calculator( QWidget *parent = nullptr );
  ~Calculator( );

 private:
  QLCDNumber *tablo;
};
#endif // CALCULATOR_H
