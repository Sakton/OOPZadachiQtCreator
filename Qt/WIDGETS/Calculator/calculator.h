#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QStack>
#include <QWidget>

class QLCDNumber;
class QPushButton;

class Calculator : public QWidget
{
  Q_OBJECT

 public:
  explicit Calculator( QWidget *parent = nullptr );
  ~Calculator( );

  QPushButton *createButton( const QString &str );

 public slots:
  void slotsButtonClicked( );
  void calculate( );

 private:
  enum { LEN = 4 };
  QLCDNumber *tablo_;
  QString strDisplay_;
  QStack< QString > stack_;
};
#endif // CALCULATOR_H
