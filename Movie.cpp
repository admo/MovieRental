#include <stdexcept>

#include "Movie.h"
#include "RegularPrice.h"
#include "ChildrensPrice.h"
#include "NewReleasePrice.h"

Movie::Movie( const std::string& title, int priceCode )
    : _title( title )
{
    setPriceCode(priceCode);
}

Movie::Movie(const Movie& movie)
    : _title(movie.getTitle())
{
    setPriceCode(movie.getPriceCode());
}

Movie& Movie::operator=( const Movie& rhs )
{
    if ( this == &rhs )
        return *this;
    _title = rhs.getTitle();
    setPriceCode( rhs.getPriceCode() );
    return *this;
}

int Movie::getPriceCode() const
{
    return _price->getPriceCode();
}

void Movie::setPriceCode( int arg )
{
    switch (arg)
    {
    case REGULAR:
        _price.reset(new RegularPrice);
        break;
    case CHILDRENS:
        _price.reset(new ChildrensPrice);
        break;
    case NEW_RELEASE:
        _price.reset(new NewReleasePrice);
        break;
    default:
        throw std::invalid_argument("Incorrect Price Code");
    }
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
