#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QMainWindow>
#include <QStackedWidget>

class QStackedWidget;
class QWidget;

class StackWidget : public QMainWindow {
  Q_OBJECT

 public:
  StackWidget(QWidget *parent = nullptr);
  ~StackWidget( );
};
#endif // STACKWIDGET_H
