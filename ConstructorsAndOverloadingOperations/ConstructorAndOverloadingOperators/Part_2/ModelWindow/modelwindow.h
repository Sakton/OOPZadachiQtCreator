#ifndef MODELWINDOW_H
#define MODELWINDOW_H

#include <string>

#include "ModellingMonitor.h"

class ModelWindow {
public:
  enum class Color { RED = 0, GREEN, BLUE };
  struct Pair {
    int32_t x { 0 };
    int32_t y { 0 };
  };

public:
  ModelWindow( const Monitor& monitor, const std::string& nm, Pair cup,
	       int32_t w, int32_t h, Color cl, bool vsbl, bool fr );
  void Read( );
  void Display( );
  std::string ToString( );

  void MoveX( int32_t dx );
  void MoveY( int32_t dy );

  void SetWidth( int32_t w );
  void SetHeight( int32_t h );
  void SetColor( Color clr );
  void SetVisible( bool vsbl );
  void SetFrame( bool frm );

private:
  Monitor monitor_;
  std::string name_;
  Pair coord_left_up_;
  int32_t width_;
  int32_t height_;
  Color color_ { Color::RED };
  bool visible_;
  bool frame_;
};

#endif  // MODELWINDOW_H
