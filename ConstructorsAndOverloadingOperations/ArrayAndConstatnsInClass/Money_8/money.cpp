#include "money.h"

Money::Money( double summ )
{
    po_nominals_.reserve( COUNT_N0M );
    ParseDouble( summ );
}

Money::operator double( )
{
    int res = 0;
    for ( int i = 0; i <= COUNT_N0M; ++i ) {
        res += po_nominals_[ i ].nom * po_nominals_[ i ].count;
    }
    return res;
}

void Money::ParseDouble( double summ )
{
    int64_t rur = summ;
    int cop = ( summ - rur ) * 1000;
    int pogr = cop % 10;
    cop /= 10;
    //поправка на погрешность
    if ( pogr >= 5 )
        ++cop;

    po_nominals_[ NOM_50_COP ].count = cop / 50;
    po_nominals_[ NOM_50_COP ].nom = 0.5;
    cop %= 50;
    po_nominals_[ NOM_10_COP ].count = cop / 10;
    po_nominals_[ NOM_10_COP ].nom = 0.1;
    cop %= 10;
    po_nominals_[ NOM_5_COP ].count = cop / 5;
    po_nominals_[ NOM_5_COP ].nom = 0.05;
    cop %= 5;
    po_nominals_[ NOM_1_COP ].count = cop;
    po_nominals_[ NOM_1_COP ].nom = 0.01;

    po_nominals_[ NOM_5000_RUR ].count = rur / 5000;
    po_nominals_[ NOM_5000_RUR ].nom = 5000;
    rur %= 5000;
    po_nominals_[ NOM_2000_RUR ].count = rur / 2000;
    po_nominals_[ NOM_2000_RUR ].nom = 2000;
    rur %= 2000;
    po_nominals_[ NOM_1000_RUR ].count = rur / 1000;
    po_nominals_[ NOM_1000_RUR ].nom = 1000;
    rur %= 1000;
    po_nominals_[ NOM_500_RUR ].count = rur / 500;
    po_nominals_[ NOM_500_RUR ].nom = 500;
    rur %= 500;
    po_nominals_[ NOM_100_RUR ].count = rur / 100;
    po_nominals_[ NOM_100_RUR ].nom = 100;
    rur %= 100;
    po_nominals_[ NOM_50_RUR ].count = rur / 50;
    po_nominals_[ NOM_50_RUR ].nom = 50;
    rur %= 50;
    po_nominals_[ NOM_10_RUR ].count = rur / 10;
    po_nominals_[ NOM_10_RUR ].nom = 10;
    rur %= 10;
    po_nominals_[ NOM_5_RUR ].count = rur / 5;
    po_nominals_[ NOM_5_RUR ].nom = 5;
    rur %= 5;
    po_nominals_[ NOM_2_RUR ].count = rur / 2;
    po_nominals_[ NOM_2_RUR ].nom = 2;
    rur %= 2;
    po_nominals_[ NOM_1_RUR ].count = rur;
    po_nominals_[ NOM_1_RUR ].nom = 1;
}
