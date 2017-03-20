#include "Price.h"
#include "Movie.h"

int Price::getFrequentRenterPoints(int daysRented) const
{
    if ( ( getPriceCode() == Movie::NEW_RELEASE )
         && daysRented > 1 )
        return 2;
    else
        return 1;
}
