#include "lineedit.h"

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

LineEdit::LineEdit( QWidget *parent ) : QWidget( parent ) {
  QLabel *pblDisplay = new QLabel( "ТОП СЕКРЕТ" );
  pblDisplay->setAlignment( Qt::AlignCenter );
  pblDisplay->setFrameStyle( QFrame::Box | QFrame::Raised );
  pblDisplay->setLineWidth( 2 );
  pblDisplay->setFixedHeight( 50 );

  QLabel *plblText = new QLabel( "&Text" );
  QLineEdit *ptxt = new QLineEdit;
  plblText->setBuddy( ptxt );
  connect( ptxt, QOverload< const QString & >::of( &QLineEdit::textChanged ), plblText,
           QOverload< const QString & >::of( &QLabel::setText ) );

  QLabel *plblPass = new QLabel( "&Password" );
  QLineEdit *passEdit = new QLineEdit;
  plblPass->setBuddy( passEdit );
  passEdit->setEchoMode( QLineEdit::Password );
  connect( passEdit, QOverload< const QString & >::of( &QLineEdit::textChanged ), plblPass,
           QOverload< const QString & >::of( &QLabel::setText ) );

  QVBoxLayout *lay = new QVBoxLayout;
  lay->addWidget( pblDisplay );
  lay->addWidget( plblText );
  lay->addWidget( ptxt );
  lay->addWidget( plblPass );
  lay->addWidget( passEdit );

  setLayout( lay );
}

LineEdit::~LineEdit()
{
}

