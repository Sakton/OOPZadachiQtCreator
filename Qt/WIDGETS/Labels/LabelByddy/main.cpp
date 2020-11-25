#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>

#include "labelbyddy.h"

int main(int argc, char *argv[])
{
  QApplication a( argc, argv );
  //  LabelByddy w;
  //  w.show();
  QWidget w;
  QLabel *lblNmae = new QLabel( "&Name:" );
  QLineEdit *ptxtName = new QLineEdit;
  lblNmae->setBuddy( ptxtName );

  QLabel *lblAge = new QLabel( "&Age" );
  QSpinBox *pspin = new QSpinBox;
  lblAge->setBuddy( pspin );

  QVBoxLayout *vlayout = new QVBoxLayout( &w );
  vlayout->addWidget( lblNmae );
  vlayout->addWidget( ptxtName );
  vlayout->addWidget( lblAge );
  vlayout->addWidget( pspin );

  w.setLayout( vlayout );
  w.show( );

  return a.exec( );
}
