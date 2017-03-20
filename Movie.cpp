#include "Movie.h"

Movie::Movie( const std::string& title, int priceCode )
    : _title( title )
{
    setPriceCode(priceCode);
}

int Movie::getPriceCode() const
{
    return _priceCode;
}

void Movie::setPriceCode( int arg )
{
    _priceCode = arg;
}

std::string Movie::getTitle() const
{
    return _title;
}

double Movie::getCharge(int daysRented) const
{
    double result = 0;
    switch ( getPriceCode() ) {
    case Movie::REGULAR:
        result += 2;
        if ( daysRented > 2 )
            result += ( daysRented - 2 ) * 1.5 ;
        break;
    case Movie::NEW_RELEASE:
        result += daysRented * 3;
        break;
    case Movie::CHILDRENS:
        result += 1.5;
        if ( daysRented > 3 )
            result += ( daysRented - 3 ) * 1.5;
        break;
    }
    return result;
}

int Movie::getFrequentRenterPoints(int daysRented) const
{
    if ( ( getPriceCode() == Movie::NEW_RELEASE )
         && daysRented > 1 )
      return 2;
    else
      return 1;
}

const int Movie::CHILDRENS;
const int Movie::REGULAR;
const int Movie::NEW_RELEASE;
