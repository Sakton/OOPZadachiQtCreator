#include "modelwindow.h"

#include <iostream>
#include <sstream>

ModelWindow::ModelWindow( const Monitor& monitor, const std::string& nm,
			  ModelWindow::Pair cup, int32_t w, int32_t h,
			  ModelWindow::Color cl, bool vsbl, bool fr )
    : monitor_ { monitor }, name_ { nm } {
  if ( ( 0 <= cup.x && cup.x <= monitor.WIDTH ) &&
       ( 0 <= cup.y && cup.y <= monitor.HEIGHT ) )
    coord_left_up_ = cup;

  if ( 0 < w && w < monitor.WIDTH ) {
    if ( ( coord_left_up_.x + w ) <= monitor.WIDTH ) {
      width_ = w;
    } else {
      width_ = monitor.WIDTH - coord_left_up_.x + 1;
    }
  } else {
    std::cout << "ERROR WIDTH!!!" << std::endl;
    exit( 1 );
  }

  if ( 0 < h && h < monitor.HEIGHT ) {
    if ( ( coord_left_up_.y + h ) <= monitor.HEIGHT ) {
      height_ = h;
    } else {
      height_ = monitor.HEIGHT - coord_left_up_.y + 1;
    }
  }

  color_ = cl;
  visible_ = vsbl;
  frame_ = fr;
}

void ModelWindow::Read( ) {
  std::string nm;
  std::cout << "Enter name: ";
  std::cin >> nm;
  std::cout << std::endl;

  std::cout << "Enter x y leftUp: ";
  int x = 0, y = 0;
  std::cin >> x >> y;
  std::cout << std::endl;
  ModelWindow::Pair coord { x, y };

  std::cout << "Enter Width: ";
  int w = 0;
  std::cin >> w;
  std::cout << std::endl;

  std::cout << "Enter Height: ";
  int h = 0;
  std::cin >> h;
  std::cout << std::endl;

  std::cout << "Enter Color: 1 OR 2 OR 3: ";
  int xx = 0;
  std::cin >> xx;
  ModelWindow::Color clr;
  switch ( xx ) {
    case 0:
      clr = ModelWindow::Color::RED;
      break;
    case 1:
      clr = ModelWindow::Color::GREEN;
      break;
    case 2:
      clr = ModelWindow::Color::BLUE;
      break;
    default:
      clr = ModelWindow::Color::RED;
      break;
  }

  std::cout << "Enter visible 0 - false OR !0 - true: ";
  int vs = 0;
  std::cin >> vs;

  std::cout << "Enter frame 0 - false OR !0 - true: ";
  int f = 0;
  std::cin >> f;

  //переприсвоить все поля сразу через временный обьект
  *this = ModelWindow( monitor_, nm, coord, w, h, clr, vs, f );
  //или через set устанвки полей в существующем обьекте
}

void ModelWindow::Display( ) { std::cout << ToString( ); }

std::string ModelWindow::ToString( ) {
  std::stringstream ss;
  ss << "Name = " << name_ << std::endl
     << "coord_left_up_ x = " << coord_left_up_.x
     << "; y = " << coord_left_up_.y << std::endl
     << "Width = " << width_ << std::endl
     << "Height = " << height_ << std::endl
     << "Color = ";
  switch ( color_ ) {
    case ModelWindow::Color::RED:
      ss << "RED";
      break;
    case ModelWindow::Color::GREEN:
      ss << "GREEN";
      break;
    case ModelWindow::Color::BLUE:
      ss << "BLUE";
      break;
  }
  ss << std::endl
     << std::boolalpha << "VISIBLE = " << visible_ << std::endl
     << "FRAME = " << frame_ << std::endl;
  return ss.str( );
}

void ModelWindow::MoveX( int32_t dx ) {
  if ( ( coord_left_up_.x + dx ) < 0 ||
       coord_left_up_.x + dx > monitor_.WIDTH ) {
    std::cout << "ERROR DX!! WINDOW OUTSIDE MONITOR ";
    exit( 1 );
  }
  if ( ( coord_left_up_.x + dx + width_ ) > monitor_.WIDTH ) {
    std::cout << "CROSSING VETICAL";
  }
  coord_left_up_.x += dx;
}

void ModelWindow::MoveY( int32_t dy ) {
  if ( ( coord_left_up_.y + dy ) < 0 ||
       coord_left_up_.y + dy > monitor_.HEIGHT ) {
    std::cout << "ERROR DY!! WINDOW OUTSIDE MONITOR ";
    exit( 1 );
  }
  if ( ( coord_left_up_.y + dy + height_ ) > monitor_.HEIGHT ) {
    std::cout << "CROSSING GORIZONTAL";
  }
  coord_left_up_.y += dy;
}

void ModelWindow::SetWidth( int32_t w ) {
  if ( ( coord_left_up_.x + w ) < 0 ||
       ( coord_left_up_.x + w ) > monitor_.WIDTH ) {
    std::cout << "ERROR W!! WINDOW OUTSIDE MONITOR ";
    exit( 1 );
  } else {
    width_ = w;
  }
}

void ModelWindow::SetHeight( int32_t h ) {
  if ( ( coord_left_up_.y + h ) < 0 ||
       ( coord_left_up_.y + h ) > monitor_.HEIGHT ) {
    std::cout << "ERROR H!! WINDOW OUTSIDE MONITOR ";
    exit( 1 );
  } else {
    height_ = h;
  }
}

void ModelWindow::SetColor( ModelWindow::Color clr ) {
  switch ( clr ) {
    case ModelWindow::Color::RED:
    case ModelWindow::Color::BLUE:
    case ModelWindow::Color::GREEN:
      color_ = clr;
      break;
    default:
      std::cout << "EROR COLOR!!" << std::endl;
      exit( 1 );
  }
}

void ModelWindow::SetVisible( bool vsbl ) { visible_ = vsbl; }

void ModelWindow::SetFrame( bool frm ) { frame_ = frm; }
