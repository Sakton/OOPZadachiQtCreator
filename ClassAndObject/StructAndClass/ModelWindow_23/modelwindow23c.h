#ifndef MODELWINDOW23C_H
#define MODELWINDOW23C_H
#include "ModellingMonitor.h"
#include <string>

struct DataModelWindow {
    enum class Color {
	RED = 0,
	GREEN,
	BLUE
    };
    struct Pair {
	int32_t x { 0 };
	int32_t y { 0 };
    };
    Monitor monitor_;
    std::string name_;
    Pair coord_left_up_;
    int32_t width_;
    int32_t height_;
    Color color_ { Color::RED };
    bool visible_;
    bool frame_;

    void Init( const Monitor & monitor, std::string nm, Pair cup, int32_t w, int32_t h, Color cl, bool vsbl, bool fr );
    void Read( );
    void Display( );
    std::string ToString( );
};

class ModelWindow23C {
public:
    void Init( const Monitor & monitor, std::string nm, DataModelWindow::Pair cup, int32_t w, int32_t h, DataModelWindow::Color cl, bool vsbl, bool fr );
    void Read( );
    void Display( );
    std::string ToString( );

    void MoveX( int32_t dx );
    void MoveY( int32_t dy );
    void SetWidth( int32_t w );
    void SetHeight( int32_t h );
    void SetColor( DataModelWindow::Color clr );
    void SetVisible( bool vsbl );
    void SetFrame( bool frm );

private:
    DataModelWindow data_;
};

#endif // MODELWINDOW23C_H
