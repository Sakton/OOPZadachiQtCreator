#ifndef CURSOR40B_H
#define CURSOR40B_H
#include <string>
//TODO доделать

class Cursor40B {
 public:
  enum class VID { HORIZONTAL, VERTICAL };

  enum class CURSOR_SIZE { SZ1 = 0, SZ2, SZ3 };

  Cursor40B( uint16_t c_x, uint16_t c_y, VID vid, CURSOR_SIZE c_s, bool vsbl );
  void Display( ) const;
  std::string ToString( ) const;

  uint16_t x( ) const;
  void setX( const uint16_t& x );

  uint16_t y( ) const;
  void setY( const uint16_t& y );

  VID vid( ) const;
  void setVid( const VID& vid );

  bool visible( ) const;
  void setVisible( bool visible );

  CURSOR_SIZE c_size( ) const;
  void setC_size( const CURSOR_SIZE& c_size );

 private:
  uint16_t x_;
  uint16_t y_;
  VID vid_;
  CURSOR_SIZE c_size_;
  bool visible_;
};

#endif // CURSOR40B_H
