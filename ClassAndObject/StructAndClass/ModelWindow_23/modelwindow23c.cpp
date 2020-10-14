#include "modelwindow23c.h"
#include <iostream>
#include <sstream>

void DataModelWindow::Init( const Monitor & monitor, std::string nm, DataModelWindow::Pair cup, int32_t w, int32_t h, DataModelWindow::Color cl, bool vsbl, bool fr )
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

void DataModelWindow::Read( )
{
    std::string nm;
    std::cout << "Enter name: ";
    std::cin >> nm;
    std::cout << std::endl;

    std::cout << "Enter x y leftUp: ";
    int x = 0, y = 0;
    std::cin >> x >> y;
    std::cout << std::endl;
    DataModelWindow::Pair coord { x, y };

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
    DataModelWindow::Color clr;
    switch ( xx ) {
	case 0:
	    clr = DataModelWindow::Color::RED;
	    break;
	case 1:
	    clr = DataModelWindow::Color::GREEN;
	    break;
	case 2:
	    clr = DataModelWindow::Color::BLUE;
	    break;
	default:
	    clr = DataModelWindow::Color::RED;
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

void DataModelWindow::Display( )
{
    std::cout << ToString( );
}

std::string DataModelWindow::ToString( )
{
    std::stringstream ss;
    ss << "Name = " << name_ << std::endl
       << "data_.coord_left_up_ x = " << coord_left_up_.x << "; y = " << coord_left_up_.y << std::endl
       << "Width = " << width_ << std::endl
       << "Height = " << height_ << std::endl
       << "Color = ";
    switch ( color_ ) {
	case DataModelWindow::Color::RED:
	    ss << "RED";
	    break;
	case DataModelWindow::Color::GREEN:
	    ss << "GREEN";
	    break;
	case DataModelWindow::Color::BLUE:
	    ss << "BLUE";
	    break;
    }
    ss << std::endl
       << std::boolalpha << "VISIBLE = " << visible_ << std::endl
       << "FRAME = " << frame_ << std::endl;
    return ss.str( );
}

void ModelWindow23C::Init( const Monitor & monitor, std::string nm, DataModelWindow::Pair cup, int32_t w, int32_t h, DataModelWindow::Color cl, bool vsbl, bool fr )
{
    data_.Init( monitor, nm, cup, w, h, cl, vsbl, fr );
}

void ModelWindow23C::Read( )
{
    data_.Read( );
}

void ModelWindow23C::Display( )
{
    data_.Display( );
}

std::string ModelWindow23C::ToString( )
{
    return data_.ToString( );
}

void ModelWindow23C::MoveX( int32_t dx )
{
    if ( ( data_.coord_left_up_.x + dx ) < 0 || data_.coord_left_up_.x + dx > data_.monitor_.WIDTH ) {
	std::cout << "ERROR DX!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    }
    if ( ( data_.coord_left_up_.x + dx + data_.width_ ) > data_.monitor_.WIDTH ) {
	std::cout << "CROSSING VETICAL";
    }
    data_.coord_left_up_.x += dx;
}

void ModelWindow23C::MoveY( int32_t dy )
{
    if ( ( data_.coord_left_up_.y + dy ) < 0 || data_.coord_left_up_.y + dy > data_.monitor_.HEIGHT ) {
	std::cout << "ERROR DY!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    }
    if ( ( data_.coord_left_up_.y + dy + data_.height_ ) > data_.monitor_.HEIGHT ) {
	std::cout << "CROSSING GORIZONTAL";
    }
    data_.coord_left_up_.y += dy;
}

void ModelWindow23C::SetWidth( int32_t w )
{
    if ( ( data_.coord_left_up_.x + w ) < 0 || ( data_.coord_left_up_.x + w ) > data_.monitor_.WIDTH ) {
	std::cout << "ERROR W!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    } else {
	data_.width_ = w;
    }
}

void ModelWindow23C::SetHeight( int32_t h )
{
    if ( ( data_.coord_left_up_.y + h ) < 0 || ( data_.coord_left_up_.y + h ) > data_.monitor_.HEIGHT ) {
	std::cout << "ERROR H!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    } else {
	data_.height_ = h;
    }
}

void ModelWindow23C::SetColor( DataModelWindow::Color clr )
{
    switch ( clr ) {
	case DataModelWindow::Color::RED:
	case DataModelWindow::Color::BLUE:
	case DataModelWindow::Color::GREEN:
	    data_.color_ = clr;
	    break;
	default:
	    std::cout << "EROR COLOR!!" << std::endl;
	    exit( 1 );
    }
}

void ModelWindow23C::SetVisible( bool vsbl )
{
    data_.visible_ = vsbl;
}

void ModelWindow23C::SetFrame( bool frm )
{
    data_.frame_ = frm;
}
