#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QStackedWidget>
#include <QWidget>

class StackWidget : public QWidget {
  Q_OBJECT

 public slots:
  void innt( int x );

 public:
  StackWidget(QWidget *parent = nullptr);
  ~StackWidget( );
};
#endif // STACKWIDGET_H
