#ifndef TRIANGLE48_H
#define TRIANGLE48_H
#include "angle26b.h"
#include <string>

class Triangle48 {
public:
    constexpr static double PI = 3.14159265358979323846;
    constexpr static int ANG_PI_2 = 180;
    enum class TYPE_TRIANGLE {
	RAVNO_STORONNY,
	RAVNO_BEDRENNY,
	PRYAMO_UGOLNY,
	OTHER
    };

    void Init( double a, double b, double ab );
    void Display( ) const;
    void Read( );
    std::string ToString( ) const;

    double GetAB( ) const;
    double GetBC( ) const;
    double GetAC( ) const;
    double GetAngleAB_BC( ) const;
    double GetAngleBC_AC( ) const;
    double GetAngleAC_AB( ) const;
    double Area( ) const;
    double Perimeter( ) const;
    double HeightToAB( ) const;
    double HeightToBC( ) const;
    double HeightToAC( ) const;
    TYPE_TRIANGLE GetType( ) const;

private:
    double sAB;
    double sBC;
    double sAC;
    Angle26B angAB_BC;
    Angle26B angBC_AC;
    Angle26B angAC_AB;
};

#endif // TRIANGLE48_H
