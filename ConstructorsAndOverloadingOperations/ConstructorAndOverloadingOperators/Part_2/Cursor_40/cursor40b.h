#ifndef CURSOR40B_H
#define CURSOR40B_H
#include <string>
//TODO доделать

class Cursor40B
{
public:
    enum class VID {
	HORIZONTAL,
	VERTICAL
    };
    void Init( );
    void Display( );
    //void Read( );
    std::string ToString( );

    uint16_t x( ) const;
    void setX( const uint16_t & x );

    uint16_t y( ) const;
    void setY( const uint16_t & y );

    VID vid( ) const;
    void setVid( const VID & vid );

    int16_t size( ) const;
    void setSize( const int16_t & size );

    bool visible( ) const;
    void setVisible( bool visible );

private:
    uint16_t x_;
    uint16_t y_;
    VID vid_;
    int16_t size_;
    bool visible_;
};

#endif // CURSOR40B_H
