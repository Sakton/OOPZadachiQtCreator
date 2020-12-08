#ifndef VGT_H
#define VGT_H

#include <QWidget>

class Vgt : public QWidget
{
  Q_OBJECT

 public:
  Vgt(QWidget *parent = nullptr);
  ~Vgt( );

  // QWidget interface
 protected:
  void keyPressEvent( QKeyEvent *event ) override;

  // QWidget interface
 protected:
  void mousePressEvent( QMouseEvent *event ) override;
};
#endif // VGT_H
