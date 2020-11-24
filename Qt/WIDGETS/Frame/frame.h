#ifndef FRAME_H
#define FRAME_H

#include <QFrame>

class Frame : public QFrame {
  Q_OBJECT

 public:
  explicit Frame( QFrame *parent = nullptr );
  ~Frame();
};
#endif // FRAME_H
