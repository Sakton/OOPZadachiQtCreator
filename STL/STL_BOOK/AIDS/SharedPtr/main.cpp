#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Person {
 public:
  Person( const std::string &n, std::shared_ptr< Person > m = nullptr, std::shared_ptr< Person > f = nullptr )
      : name { n }, mother { m }, father { f } {}
  ~Person( ) { std::cout << "delete Person object name = " << name << std::endl; }

  void setKids( std::shared_ptr< Person > kid ) { kids.push_back( kid ); }
  std::shared_ptr< Person > &operator[]( int index ) { return kids[ index ]; }
  const std::shared_ptr< Person > operator[]( int index ) const { return std::static_pointer_cast< Person >( kids[ index ] ); }

  const std::shared_ptr< Person > getMother( ) const { return mother; }
  const std::shared_ptr< Person > getFather( ) const { return father; }
  std::string getName( ) const { return name; }

 private:
  std::string name { "" };
  std::shared_ptr< Person > mother { nullptr };
  std::shared_ptr< Person > father { nullptr };
  std::vector< std::shared_ptr< Person > > kids;
};

std::shared_ptr< Person > initFamily( const std::string &name );

int main( ) {
  std::shared_ptr< Person > p = initFamily( "nico" );
  std::cout << "created nico family" << std::endl;
  std::cout << "nico shareds = " << p.use_count( ) << std::endl;
  std::cout << " name 1st kids of mom = " << ( *p->getMother( ) )[ 0 ]->getName( );
}

std::shared_ptr< Person > initFamily( const std::string &name ) {
  std::shared_ptr< Person > mom( new Person( name + " moms" ) );
  std::cout << "mom shareds = " << mom.use_count( ) << std::endl;
  // std::shared_ptr< Person > dad( new Person( name + " dad" ) );
  std::shared_ptr< Person > dad { std::make_shared< Person >( name + " dad" ) };
  std::cout << "dad shareds = " << dad.use_count( ) << std::endl;
  std::shared_ptr< Person > kid( new Person( name, mom, dad ) );
  std::cout << "kid shareds = " << kid.use_count( ) << std::endl;
  std::cout << "mom + dad + kid shareds = " << mom.use_count( ) << std::endl;
  mom->setKids( kid );
  std::cout << "kid + mom shareds = " << kid.use_count( ) << std::endl;
  dad->setKids( kid );
  std::cout << "kid + mom + dad shareds = " << kid.use_count( ) << std::endl;
  return kid;
}
