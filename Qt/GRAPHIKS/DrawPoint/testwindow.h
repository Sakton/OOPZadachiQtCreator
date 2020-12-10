#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>

class TestWindow : public QWidget
{
  Q_OBJECT

 public:
  TestWindow(QWidget *parent = nullptr);
  ~TestWindow();

  // QWidget interface
 protected:
  void paintEvent( QPaintEvent * ) override;
};
#endif // TESTWINDOW_H
