#include "ChildrensPrice.h"
#include "Movie.h"

PriceCode ChildrensPrice::getPriceCode() const
{
    return PriceCode::CHILDRENS;
}

double ChildrensPrice::getCharge(int daysRented) const
{
    double result = 1.5;
    if ( daysRented > 3 )
        result += ( daysRented - 3 ) * 1.5;
    return result;
}
