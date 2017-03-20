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
    double result = 0;
    switch ( getMovie().getPriceCode() ) {
    case Movie::REGULAR:
        result += 2;
        if ( getDaysRented() > 2 )
            result += ( getDaysRented() - 2 ) * 1.5 ;
        break;
    case Movie::NEW_RELEASE:
        result += getDaysRented() * 3;
        break;
    case Movie::CHILDRENS:
        result += 1.5;
        if ( getDaysRented() > 3 )
            result += ( getDaysRented() - 3 ) * 1.5;
        break;
    }

    return result;
}
