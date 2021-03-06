#include "RegularPrice.h"
#include "Movie.h"

PriceCode RegularPrice::getPriceCode() const
{
    return PriceCode::REGULAR;
}

double RegularPrice::getCharge(int daysRented) const
{
    double result = 2;
    if ( daysRented > 2 )
        result += ( daysRented - 2 ) * 1.5 ;
    return result;
}
