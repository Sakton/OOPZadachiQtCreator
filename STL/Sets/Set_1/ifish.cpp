#include "ifish.h"

IFish::~IFish( ) {}

std::ostream &IFish::display( std::ostream &out ) const {
  out << "id = " << id_;
  return out;
}

int IFish::getId( ) const { return id_; }

int IFish::getIDCOUNT( ) { return IDCOUNT; }

std::string Okun::getType( ) const { return TYPE; }

std::ostream &Okun::display( std::ostream &out ) const {
  return IFish::display( out ) << "\n"
                               << "TYPE = " << TYPE << std::endl;
}

std::string Karas::getType( ) const { return TYPE; }

std::ostream &Karas::display( std::ostream &out ) const {
  return IFish::display( out ) << "\n"
                               << "TYPE = " << TYPE << std::endl;
}

std::string Ersh::getType( ) const { return TYPE; }

std::ostream &Ersh::display( std::ostream &out ) const {
  return IFish::display( out ) << "\n"
                               << "TYPE = " << TYPE << std::endl;
}

std::string Lesch::getType( ) const { return TYPE; }

std::ostream &Lesch::display( std::ostream &out ) const {
  return IFish::display( out ) << "\n"
                               << "TYPE = " << TYPE << std::endl;
}

std::string Schuka::getType( ) const { return TYPE; }

std::ostream &Schuka::display( std::ostream &out ) const {
  return IFish::display( out ) << "\n"
                               << "TYPE = " << TYPE << std::endl;
}

bool operator<( const IFish &lhs, const IFish &rhs ) { return lhs.getId( ) < rhs.getId( ); }

std::ostream &operator<<( std::ostream &out, const IFish &rhs ) { return rhs.display( out ); }

std::string Plotva::getType( ) const { return TYPE; }

std::ostream &Plotva::display( std::ostream &out ) const {
  return IFish::display( out ) << "\n"
                               << "TYPE = " << TYPE << std::endl;
}

std::string Dorado::getType( ) const { return TYPE; }

std::ostream &Dorado::display( std::ostream &out ) const {
  return IFish::display( out ) << "\n"
                               << "TYPE = " << TYPE << std::endl;
}

std::string Zubatka::getType( ) const { return TYPE; }

std::ostream &Zubatka::display( std::ostream &out ) const {
  return IFish::display( out ) << "\n"
                               << "TYPE = " << TYPE << std::endl;
}
