#include "pushbuttons.h"

#include <QPushButton>
#include <QVBoxLayout>

PushButtons::PushButtons( QWidget *parent ) : QWidget( parent ) {
  QPushButton *push = new QPushButton( tr( "&ОБЫЧНАЯ КНОПКА" ) );
  QPushButton *toggle = new QPushButton( tr( "&ПЕРЕКЛЮЧАТЕЛЬ" ) );
  toggle->setCheckable( true );
  toggle->setChecked( true );
  QPushButton *flat = new QPushButton( tr( "&СКРЫТАЯ КНОПКА" ) );
  flat->setFlat( true );

  QPixmap pix( "E:/CPP/MyProects/OOPZadachiCreatorQt/OOPZadachiQtCreator/Qt/15487.png" );
  QPushButton *imgBtn = new QPushButton( /*"&КАРТИНКА-КНОПКА"*/ );
  imgBtn->setIcon( pix );
  imgBtn->setIconSize( pix.size( ) );

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget( push );
  layout->addWidget( toggle );
  layout->addWidget( flat );
  layout->addWidget( imgBtn );

  setLayout( layout );
}

PushButtons::~PushButtons()
{
}

