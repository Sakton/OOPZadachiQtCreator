#include "counter.h"

Counter::Counter( QObject* parent, int32_t v ) : QObject( parent ), m_value_ { v } {}

void Counter::slotInc( ) {
  emit counterChanged( m_value_++ );
  if ( m_value_ == 5 ) emit goodbye( );
}
