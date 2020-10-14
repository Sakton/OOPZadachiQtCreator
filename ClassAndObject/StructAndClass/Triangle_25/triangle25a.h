#ifndef TRIANGLE25A_H
#define TRIANGLE25A_H
#include <string>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

struct Triangle25A {
    double sAB;
    double sBC;
    double sAC;
    double angAB_BC;
    double angBC_AC;
    double angAC_AB;
};

enum class TYPE_TRIANGLE {
    RAVNO_STORONNY,
    RAVNO_BEDRENNY,
    PRYAMO_UGOLNY,
    OTHER
};

//2 строны и угол между ними, остальное решение треугольников
void Init( Triangle25A & tr, double a, double b, double ab );
void Display( const Triangle25A & tr );
void Read( Triangle25A & tr );
std::string ToString( const Triangle25A & tr );

double GetAB( const Triangle25A & tr );
double GetBC( const Triangle25A & tr );
double GetAC( const Triangle25A & tr );
double GetAngleAB_BC( const Triangle25A & tr );
double GetAngleBC_AC( const Triangle25A & tr );
double GetAngleAC_AB( const Triangle25A & tr );

//Эти методы бессмысленны без уточнения так как изменение этих размеров может происходить по разному
//и решения разные и есть вариант что не имеет решения, так как нет 2 доп данных для разрешения всего треугольника
//TODO пока так

//void SetAB( Triangle25A & tr, double size );
//void SetBC( Triangle25A & tr, double size );
//void SetAC( Triangle25A & tr, double size );
//void SetAngleAB_BC( Triangle25A & tr, double angle );
//void SetAngleBC_AC( Triangle25A & tr, double angle );
//void SetAngleAC_AB( Triangle25A & tr, double angle );

double Area( const Triangle25A & tr );
double Perimeter( const Triangle25A & tr );
double HeightToAB( const Triangle25A & tr );
double HeightToBC( const Triangle25A & tr );
double HeightToAC( const Triangle25A & tr );

TYPE_TRIANGLE GetType( const Triangle25A & tr );

#endif // TRIANGLE25A_H
