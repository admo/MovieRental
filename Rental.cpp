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
    return _movie.getCharge(getDaysRented());
}

int Rental::getFrequentRenterPoints() const
{
    if ( ( getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && getDaysRented() > 1 )
      return 2;
    else
      return 1;
}
