#ifndef BANKOMAT34B_H
#define BANKOMAT34B_H
#include <string>

class Bankomat34B {
public:
    static constexpr int COUNT_ELEMENTS = 5;
    using SpecArray = int16_t[ COUNT_ELEMENTS ];
    enum NOMINALS {
	NOM_10_RUR = 0,
	NOM_50_RUR,
	NOM_100_RUR,
	NOM_500_RUR,
	NOM_1000_RUR
    };

    void Init( int32_t id = 0, int32_t min = 0, int32_t max = 0, SpecArray cassetaMoney = nullptr );
    void Display( );
    //void Read( );
    std::string ToString( );
    void AddCash( SpecArray cassetaMoney );
    void SubCash( int32_t summ );

private:
    void ParsePoNominals( int32_t summ, SpecArray arr );
    int64_t RemainerCash( );

private:
    static constexpr int NOMIMALS_BILL[] { 10, 50, 100, 500, 1000 };	    //денежки которые может хранить банкомат

    int32_t id_;
    SpecArray cash_ { 0 };
    int32_t min_;
    int32_t max_;
};

#endif // BANKOMAT34B_H
