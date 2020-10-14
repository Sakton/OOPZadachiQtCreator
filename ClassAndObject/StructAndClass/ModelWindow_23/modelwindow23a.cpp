#include "modelwindow23a.h"
#include <sstream>

void Init( const Monitor & monitor,
	   ModelWindow23A & mw,
	   std::string nm,
	   ModelWindow23A::Pair cup,
	   int32_t w,
	   int32_t h,
	   ModelWindow23A::Color cl,
	   bool vsbl,
	   bool fr )
{
    mw.name = nm;
    if ( ( 0 <= cup.x && cup.x <= monitor.WIDTH ) && ( 0 <= cup.y && cup.y <= monitor.HEIGHT ) )
	mw.coord_left_up = cup;

    if ( 0 < w && w < monitor.WIDTH ) {
	if ( ( mw.coord_left_up.x + w ) <= monitor.WIDTH ) {
	    mw.width = w;
	} else {
	    mw.width = monitor.WIDTH - mw.coord_left_up.x + 1;
	}
    } else {
	std::cout << "ERROR WIDTH!!!" << std::endl;
	exit( 1 );
    }

    if ( 0 < h && h < monitor.HEIGHT ) {
	if ( ( mw.coord_left_up.y + h ) <= monitor.HEIGHT ) {
	    mw.height = h;
	} else {
	    mw.height = monitor.HEIGHT - mw.coord_left_up.y + 1;
	}
    }

    mw.color = cl;
    mw.visible = vsbl;
    mw.frame = fr;
}

void Read( const Monitor & monitor, ModelWindow23A & mv )
{
    std::string nm;
    std::cout << "Enter name: ";
    std::cin >> nm;
    std::cout << std::endl;

    std::cout << "Enter x y leftUp: ";
    int x = 0, y = 0;
    std::cin >> x >> y;
    std::cout << std::endl;
    ModelWindow23A::Pair coord { x, y };

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
    ModelWindow23A::Color clr;
    switch ( xx ) {
	case 0:
	    clr = ModelWindow23A::Color::RED;
	    break;
	case 1:
	    clr = ModelWindow23A::Color::GREEN;
	    break;
	case 2:
	    clr = ModelWindow23A::Color::BLUE;
	    break;
	default:
	    clr = ModelWindow23A::Color::RED;
	    break;
    }

    std::cout << "Enter visible 0 - false OR !0 - true: ";
    int vs = 0;
    std::cin >> vs;

    std::cout << "Enter frame 0 - false OR !0 - true: ";
    int f = 0;
    std::cin >> f;

    Init( monitor, mv, nm, coord, w, h, clr, vs, f );
}

void Display( const ModelWindow23A & mv )
{
    std::cout << ToString( mv );
}

std::string ToString( const ModelWindow23A & mv )
{
    std::stringstream ss;
    ss << "Name = " << mv.name << std::endl
       << "Coord_Left_Up x = " << mv.coord_left_up.x << "; y = " << mv.coord_left_up.y << std::endl
       << "Width = " << mv.width << std::endl
       << "Height = " << mv.height << std::endl
       << "Color = ";
    switch ( mv.color ) {
	case ModelWindow23A::Color::RED:
	    ss << "RED";
	    break;
	case ModelWindow23A::Color::GREEN:
	    ss << "GREEN";
	    break;
	case ModelWindow23A::Color::BLUE:
	    ss << "BLUE";
	    break;
    }
    ss << std::endl
       << std::boolalpha << "VISIBLE = " << mv.visible << std::endl
       << "FRAME = " << mv.frame << std::endl;
    return ss.str( );
}

void MoveX( const Monitor & monitor, ModelWindow23A & mv, int32_t dx )
{
    if ( ( mv.coord_left_up.x + dx ) < 0 || mv.coord_left_up.x + dx > monitor.WIDTH ) {
	std::cout << "ERROR DX!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    }
    if ( ( mv.coord_left_up.x + dx + mv.width ) > monitor.WIDTH ) {
	std::cout << "CROSSING VETICAL";
    }
    mv.coord_left_up.x += dx;
}

void MoveY( const Monitor & monitor, ModelWindow23A & mv, int32_t dy )
{
    if ( ( mv.coord_left_up.y + dy ) < 0 || mv.coord_left_up.y + dy > monitor.HEIGHT ) {
	std::cout << "ERROR DY!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    }
    if ( ( mv.coord_left_up.y + dy + mv.height ) > monitor.HEIGHT ) {
	std::cout << "CROSSING GORIZONTAL";
    }
    mv.coord_left_up.y += dy;
}

void SetWidth( const Monitor & monitor, ModelWindow23A & mv, int32_t w )
{
    if ( ( mv.coord_left_up.x + w ) < 0 || ( mv.coord_left_up.x + w ) > monitor.WIDTH ) {
	std::cout << "ERROR W!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    } else {
	mv.width = w;
    }
}

void SetHeight( const Monitor & monitor, ModelWindow23A & mv, int32_t h )
{
    if ( ( mv.coord_left_up.y + h ) < 0 || ( mv.coord_left_up.y + h ) > monitor.HEIGHT ) {
	std::cout << "ERROR H!! WINDOW OUTSIDE MONITOR ";
	exit( 1 );
    } else {
	mv.height = h;
    }
}

void SetColor( ModelWindow23A & mv, ModelWindow23A::Color clr )
{
    switch ( clr ) {
	case ModelWindow23A::Color::RED:
	case ModelWindow23A::Color::BLUE:
	case ModelWindow23A::Color::GREEN:
	    mv.color = clr;
	    break;
	default:
	    std::cout << "EROR COLOR!!" << std::endl;
	    exit( 1 );
    }
}

void SetVisible( ModelWindow23A & mv, bool vsbl )
{
    mv.visible = vsbl;
}

void SetFrame( ModelWindow23A & mv, bool frm )
{
    mv.frame = frm;
}
