#ifndef TRIANGLE25C_H
#define TRIANGLE25C_H
#include <string>

struct DataTringle {
    constexpr static double PI = 3.14159265358979323846;
    constexpr static int ANG_PI_2 = 180;
    enum class TYPE_TRIANGLE {
	RAVNO_STORONNY,
	RAVNO_BEDRENNY,
	PRYAMO_UGOLNY,
	OTHER
    };
    double sAB;
    double sBC;
    double sAC;
    double angAB_BC;
    double angBC_AC;
    double angAC_AB;

    void Init( double a, double b, double ab );
    void Display( ) const;
    void Read( );
    std::string ToString( ) const;
};

class Triangle25C {
public:
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
    DataTringle::TYPE_TRIANGLE GetType( ) const;

private:
    DataTringle data_;
};

#endif // TRIANGLE25C_H
