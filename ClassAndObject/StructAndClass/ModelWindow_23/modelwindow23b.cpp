#include "modelwindow23b.h"
#include <iostream>
#include <sstream>

void ModelWindow23B::Init( const Monitor & monitor, std::string nm, ModelWindow23B::Pair cup, int32_t w, int32_t h, ModelWindow23B::Color cl, bool vsbl, bool fr )
{
    monitor_ = monitor;
    name_ = nm;
    if ( ( 0 <= cup.x && cup.x <= monitor.WIDTH ) && ( 0 <= cup.y && cup.y <= monitor.HEIGHT ) )
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

void ModelWindow23B::Read( )
{
    std::string nm;
    std::cout << "Enter name: ";
    std::cin >> nm;
    std::cout << std::endl;

    std::cout << "Enter x y leftUp: ";
    int x = 0, y = 0;
    std::cin >> x >> y;
    std::cout << std::endl;
    ModelWindow23B::Pair coord { x, y };

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
    ModelWindow23B::Color clr;
    switch ( xx ) {
	case 0:
	    clr = ModelWindow23B::Color::RED;
	    break;
	case 1:
	    clr = ModelWindow23B::Color::GREEN;
	    break;
	case 2:
	    clr = ModelWindow23B::Color::BLUE;
	    break;
	default:
	    clr = ModelWindow23B::Color::RED;
	    break;
    }

    std::cout << "Enter visible 0 - false OR !0 - true: ";
    int vs = 0;
    std::cin >> vs;

    std::cout << "Enter frame 0 - false OR !0 - true: ";
    int f = 0;
    std::cin >> f;

    Init( monitor_, nm, coord, w, h, clr, vs, f );
}

void ModelWindow23B::Display( )
{
    std::cout << ToString( );
}

std::string ModelWindow23B::ToString( )
{
    std::stringstream ss;
    ss << "Name = " << name_ << std::endl
       << "coord_left_up_ x = " << coord_left_up_.x << "; y = " << coord_left_up_.y << std::endl
       << "Width = " << width_ << std::endl
       << "Height = " << height_ << std::endl
       << "Color = ";
    switch ( color_ ) {
	case ModelWindow23B::Color::RED:
	    ss << "RED";
	    break;
	case ModelWindow23B::Color::GREEN:
	    ss << "GREEN";
	    break;
	case ModelWindow23B::Color::BLUE:
	    ss << "BLUE";
	    break;
    }
    ss << std::endl
       << std::boolalpha << "VISIBLE = " << visible_ << std::endl
       << "FRAME = " << frame_ << std::endl;
    return ss.str( );
}

void ModelWindow23B::MoveX( int32_t dx )
{
    if ( ( coord_left_up_.x + dx ) < 0 || coord_left_up_.x + dx > monitor_.WIDTH ) {
	std::cout << "ERROR DX!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    }
    if ( ( coord_left_up_.x + dx + width_ ) > monitor_.WIDTH ) {
	std::cout << "CROSSING VETICAL";
    }
    coord_left_up_.x += dx;
}

void ModelWindow23B::MoveY( int32_t dy )
{
    if ( ( coord_left_up_.y + dy ) < 0 || coord_left_up_.y + dy > monitor_.HEIGHT ) {
	std::cout << "ERROR DY!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    }
    if ( ( coord_left_up_.y + dy + height_ ) > monitor_.HEIGHT ) {
	std::cout << "CROSSING GORIZONTAL";
    }
    coord_left_up_.y += dy;
}

void ModelWindow23B::SetWidth( int32_t w )
{
    if ( ( coord_left_up_.x + w ) < 0 || ( coord_left_up_.x + w ) > monitor_.WIDTH ) {
	std::cout << "ERROR W!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    } else {
	width_ = w;
    }
}

void ModelWindow23B::SetHeight( int32_t h )
{
    if ( ( coord_left_up_.y + h ) < 0 || ( coord_left_up_.y + h ) > monitor_.HEIGHT ) {
	std::cout << "ERROR H!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    } else {
	height_ = h;
    }
}

void ModelWindow23B::SetColor( ModelWindow23B::Color clr )
{
    switch ( clr ) {
	case ModelWindow23B::Color::RED:
	case ModelWindow23B::Color::BLUE:
	case ModelWindow23B::Color::GREEN:
	    color_ = clr;
	    break;
	default:
	    std::cout << "EROR COLOR!!" << std::endl;
	    exit( 1 );
    }
}

void ModelWindow23B::SetVisible( bool vsbl )
{
    visible_ = vsbl;
}

void ModelWindow23B::SetFrame( bool frm )
{
    frame_ = frm;
}
