#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QWidget>

class QProgressBar;

class ProgressBar : public QWidget
{
  Q_OBJECT

 public:
  ProgressBar(QWidget *parent = nullptr);
  ~ProgressBar( );

 public slots:
  void plus( );
  void minus( );

 private:
  QProgressBar *progress_;
  int step;
};
#endif // PROGRESSBAR_H
