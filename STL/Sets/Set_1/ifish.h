#ifndef IFISH_H
#define IFISH_H
#include <iostream>
#include <string>

class IFish
{
 public:
  IFish( int id = 0 ) : id_ { id } { };
  virtual ~IFish( );
  virtual std::string getType( ) const = 0;
  virtual std::ostream &display( std::ostream &out ) const;
  int getId( ) const;

 private:
  int id_;
};

bool operator<( const IFish &lhs, const IFish &rhs );
std::ostream &operator<<( std::ostream &out, const IFish &rhs );

class Okun : public IFish {  // 1
 public:
  Okun( ) : IFish( 1 ) {}
  std::string getType( ) const override;
  std::ostream &display( std::ostream &out ) const override;

 private:
  const std::string TYPE = "I'm Okun";
};

class Karas : public IFish {  // 2
 public:
  Karas( ) : IFish( 2 ) {}
  std::string getType( ) const override;
  std::ostream &display( std::ostream &out ) const override;

 private:
  const std::string TYPE = "I'm Karas";
};

class Ersh : public IFish {  // 3
 public:
  Ersh( ) : IFish( 3 ) {}
  std::string getType( ) const override;
  std::ostream &display( std::ostream &out ) const override;

 private:
  const std::string TYPE = "I'm Ersh";
};

class Lesch : public IFish {  // 4
 public:
  Lesch( ) : IFish( 4 ) {}
  std::string getType( ) const override;
  std::ostream &display( std::ostream &out ) const override;

 private:
  const std::string TYPE = "I'm Lesch";
};

class Schuka : public IFish {  // 5
 public:
  Schuka( ) : IFish( 5 ) {}
  std::string getType( ) const override;
  std::ostream &display( std::ostream &out ) const override;

 private:
  const std::string TYPE = "I'm Schuka";
};

class Plotva : public IFish {  // 6
 public:
  Plotva( ) : IFish( 6 ) {}
  std::string getType( ) const override;
  std::ostream &display( std::ostream &out ) const override;

 private:
  const std::string TYPE = "I'm Plotva";
};

class Dorado : public IFish {  // 7
 public:
  Dorado( ) : IFish( 7 ) {}
  std::string getType( ) const override;
  std::ostream &display( std::ostream &out ) const override;

 private:
  const std::string TYPE = "I'm Dorado";
};

class Zubatka : public IFish {  // 8
 public:
  Zubatka( ) : IFish( 8 ) {}
  std::string getType( ) const override;
  std::ostream &display( std::ostream &out ) const override;

 private:
  const std::string TYPE = "I'm Zubatka";
};

#endif  // IFISH_H
