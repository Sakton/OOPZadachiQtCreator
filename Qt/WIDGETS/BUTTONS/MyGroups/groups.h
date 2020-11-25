#ifndef GROUPS_H
#define GROUPS_H

#include <QGroupBox>

class QCheckBox;
class QRadioButton;

class Groups : public QGroupBox {
  Q_OBJECT

 public:
  Groups(QWidget *parent = nullptr);
  ~Groups( );

 public slots:
  void slotChekRadio( );

 private:
  QCheckBox *chb_;
  QRadioButton *red_;
  QRadioButton *blue_;
  QRadioButton *green_;
};
#endif // GROUPS_H
