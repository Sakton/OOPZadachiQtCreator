#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets>

class MyClass : public QWidget
{
  Q_OBJECT

 public:
  MyClass(QWidget *parent = nullptr);
  ~MyClass( );

 public slots:
  // void showAction( const QString &str );

  // signals:
  //  void pushed( const QString &str );

 private:
  QPushButton *m_button1;
  QPushButton *m_button2;
  QLabel *m_label;
  QSignalMapper *m_mapper;
};
#endif // MYCLASS_H
