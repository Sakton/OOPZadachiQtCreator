#ifndef ABSTRACTCULTURE_H
#define ABSTRACTCULTURE_H
#include <memory>
#include <string>

class AbstractCulture {
 public:
  explicit AbstractCulture( const std::string &name = "" );
  virtual ~AbstractCulture( ) { };
  std::string name( ) const;

 private:
  std::string name_;
};

class CulturePredicat {
 public:
  bool operator( )( const std::shared_ptr< AbstractCulture > &a, const std::shared_ptr< AbstractCulture > &b ) const {
    return a->name( ) < b->name( );
  }
};

class Kartofel : public AbstractCulture {
 public:
  explicit Kartofel( const std::string &name = "Kartofel" );
};

class Ukrop : public AbstractCulture {
 public:
  explicit Ukrop( const std::string &name = "Ukrop" );
};

class Morkov : public AbstractCulture {
 public:
  explicit Morkov( const std::string &name = "Morkov" );
};

class Gorokh : public AbstractCulture {
 public:
  explicit Gorokh( const std::string &name = "Gorokh" );
};

class Kapusta : public AbstractCulture {
 public:
  explicit Kapusta( const std::string &name = "Kapusta" );
};

class Redis : public AbstractCulture {
 public:
  explicit Redis( const std::string &name = "Redis" );
};

#endif // ABSTRACTCULTURE_H
