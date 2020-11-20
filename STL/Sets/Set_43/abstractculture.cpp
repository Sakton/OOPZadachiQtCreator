#include "abstractculture.h"

AbstractCulture::AbstractCulture( const std::string &name ) : name_( name ) {}

std::string AbstractCulture::name( ) const { return name_; }

Kartofel::Kartofel( const std::string &name ) : AbstractCulture( name ) {}

Ukrop::Ukrop( const std::string &name ) : AbstractCulture( name ) {}

Morkov::Morkov( const std::string &name ) : AbstractCulture( name ) {}

Gorokh::Gorokh( const std::string &name ) : AbstractCulture( name ) {}

Kapusta::Kapusta( const std::string &name ) : AbstractCulture( name ) {}

Redis::Redis( const std::string &name ) : AbstractCulture( name ) {}
