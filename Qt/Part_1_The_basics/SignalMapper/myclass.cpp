#include "myclass.h"

MyClass::MyClass( QWidget* parent )
    : QWidget( parent ), m_button1 { nullptr }, m_button2 { nullptr }, m_label { nullptr }, m_mapper { nullptr } {
  setGeometry( QRect( 100, 100, 400, 200 ) );
  // objects
  m_button1 = new QPushButton( "Button1", this );
  m_button2 = new QPushButton( "Button2", this );
  m_label = new QLabel( "Label", this );
  m_label->setGeometry( QRect( m_button2->geometry( ).x( ) + 200, m_button2->geometry( ).y( ), 100, 50 ) );
  m_label->move( m_button2->geometry( ).x( ) + 200, m_button2->geometry( ).y( ) );
  m_button2->move( m_button2->geometry( ).x( ) + 100, m_button2->geometry( ).y( ) );
  m_button1->show( );
  m_button2->show( );
  m_label->show( );
  m_mapper = new QSignalMapper( this );
  // connects
  connect( m_button1, static_cast< void ( QPushButton::* )( bool ) >( &QPushButton::clicked ), m_mapper,
           static_cast< void ( QSignalMapper::* )( ) >( &QSignalMapper::map ) );
  m_mapper->setMapping( m_button1, "Button1 Action" );

  connect( m_button2, static_cast< void ( QPushButton::* )( bool ) >( &QPushButton::clicked ), m_mapper,
           static_cast< void ( QSignalMapper::* )( ) >( &QSignalMapper::map ) );
  m_mapper->setMapping( m_button2, "BUTTON___2 Action" );

  connect( m_mapper, static_cast< void ( QSignalMapper::* )( const QString& ) >( &QSignalMapper::mappedString ), m_label,
           static_cast< void ( QLabel::* )( const QString& ) >( &QLabel::setText ) );
}

MyClass::~MyClass()
{
}

// void MyClass::showAction( const QString& str ) { emit pushed( str ); }
