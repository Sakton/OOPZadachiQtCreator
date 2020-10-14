#ifndef MODELWINDOW23A_H
#define MODELWINDOW23A_H
#include "ModellingMonitor.h"
#include <iostream>
#include <string>

struct ModelWindow23A {
    enum class Color {
	RED = 0,
	GREEN,
	BLUE
    };
    struct Pair {
	int32_t x { 0 };
	int32_t y { 0 };
    };

    std::string name;
    Pair coord_left_up;
    int32_t width;
    int32_t height;
    Color color { Color::RED };
    bool visible;
    bool frame;
};

void Init( const Monitor & monitor,
	   ModelWindow23A & mw,
	   std::string nm,
	   ModelWindow23A::Pair cup,
	   int32_t w,
	   int32_t h,
	   ModelWindow23A::Color cl,
	   bool vsbl,
	   bool fr );

void Read( const Monitor & monitor, ModelWindow23A & mv );
void Display( const ModelWindow23A & mv );
std::string ToString( const ModelWindow23A & mv );

void MoveX( const Monitor & monitor, ModelWindow23A & mv, int32_t dx );
void MoveY( const Monitor & monitor, ModelWindow23A & mv, int32_t dy );
void SetWidth( const Monitor & monitor, ModelWindow23A & mv, int32_t w );
void SetHeight( const Monitor & monitor, ModelWindow23A & mv, int32_t h );
void SetColor( ModelWindow23A & mv, ModelWindow23A::Color clr );
void SetVisible( ModelWindow23A & mv, bool vsbl );
void SetFrame( ModelWindow23A & mv, bool frm );

#pragma pack( push, 1 )
struct ModelWindow23A_T {
    enum class Color {
	RED = 0,
	GREEN,
	BLUE
    };
    struct Pair {
	int32_t x { 0 };
	int32_t y { 0 };
    };

    std::string name;
    Pair coord_left_up;
    int32_t width;
    int32_t height;
    Color color { Color::RED };
    bool visible;
    bool frame;
};
#pragma pack( pop )

#endif	      // MODELWINDOW23A_H
