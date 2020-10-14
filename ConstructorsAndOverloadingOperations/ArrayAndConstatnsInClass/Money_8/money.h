#ifndef MONEY_H
#define MONEY_H
#include <string>
#include <vector>

class Money
{
    static constexpr int COUNT_N0M = 15;
    static const int INDEX_COP = 3;
    enum Nominal {
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

    struct Mpair {
        double nom;
        int32_t count;
    };

    operator double( );

    //далее все через дабл как в 33 упр

public:
    explicit Money( double summ = 0 );
    explicit Money( const std::string & s );

private:
    void ParseDouble( double summ );

private:
    std::vector< Mpair > po_nominals_;
};

#endif // MONEY_H
