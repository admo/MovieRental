#include "NewReleasePrice.h"
#include "Movie.h"

int NewReleasePrice::getPriceCode() const
{
    return Movie::NEW_RELEASE;
}

double NewReleasePrice::getCharge(int daysRented) const
{
    return daysRented * 3;
}

int NewReleasePrice::getFrequentRenterPoints(int daysRented) const
{
    return (daysRented > 1) ? 2 : 1;
}
