#include "Rental.h"

Rental::Rental( const Movie& movie, int daysRented )
    : _movie( movie )
    , _daysRented( daysRented ) {}

int Rental::getDaysRented() const
{
    return _daysRented;
}

const Movie& Rental::getMovie() const
{
    return _movie;
}

double Rental::getCharge() const
{
    return getMovie().getCharge(getDaysRented());
}

int Rental::getFrequentRenterPoints() const
{
    return getMovie().getFrequentRenterPoints(getDaysRented());
}
