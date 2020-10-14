#ifndef MONEY33B_H
#define MONEY33B_H
#include <string>

class Money33B {
public:
    void Init( double sum = 0.0 );
    void Display( );
    //void Read( );
    std::string ToString( );

    Money33B Add( const Money33B & b );
    Money33B Sub( const Money33B & b );
    Money33B Mul( double x );
    double Div( const Money33B & b );
    Money33B Div( double x );
    bool Eq( const Money33B & b );
    bool NotEqu( const Money33B & b );
    bool Less( const Money33B & b );
    bool LessOrEq( const Money33B & b );
    bool Greater( const Money33B & b );
    bool GreaterOrEq( const Money33B & b );
    double ToDouble( ) const;

private:
    void ParseSum( double sum );

private:
    enum NOMINALS {
	NOM_1_COP = 0,
	NOM_5_COP,
	NOM_10_COP,
	NOM_50_COP,
	NOM_1_RUR,
	NOM_2_RUR,
	NOM_5_RUR,
	NOM_10_RUR,
	NOM_50_RUR,
	NOM_100_RUR,
	NOM_200_RUR,
	NOM_500_RUR,
	NOM_1000_RUR,
	NOM_2000_RUR,
	NOM_5000_RUR
    };
    static const int COUNT_ELEMENTS = 15;
    static const int INDEX_COP = 3;
    static const double NOMIMALS_BILL[];

    int64_t summa_[ COUNT_ELEMENTS ] { };
};

#endif // MONEY33B_H
