#ifndef BITSTRING37B_H
#define BITSTRING37B_H
#include <cstdint>
#include <string>

class Bitstring37B {
 public:
  Bitstring37B( uint32_t h = 0, uint32_t t = 0 );
  Bitstring37B( uint64_t num );  // Adding

  void Display( ) const;
  std::string ToString( ) const;

  friend Bitstring37B operator&( const Bitstring37B& b1,
                                 const Bitstring37B& b2 );
  friend Bitstring37B operator|( const Bitstring37B& b1,
                                 const Bitstring37B& b2 );
  friend Bitstring37B operator^( const Bitstring37B& b1,
                                 const Bitstring37B& b2 );
  friend Bitstring37B operator~( const Bitstring37B& b1 );

  friend Bitstring37B operator<<( const Bitstring37B& b1, int n );
  friend Bitstring37B operator>>( const Bitstring37B& b1, int n );

 private:
  uint32_t head_;
  uint32_t tail_;
};

#endif // BITSTRING37B_H
