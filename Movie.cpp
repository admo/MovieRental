#include <stdexcept>

#include "Movie.h"
#include "RegularPrice.h"
#include "ChildrensPrice.h"
#include "NewReleasePrice.h"

Movie::Movie( const std::string& title, PriceCode priceCode )
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

PriceCode Movie::getPriceCode() const
{
    return _price->getPriceCode();
}

void Movie::setPriceCode( PriceCode arg )
{
    switch (arg)
    {
    case PriceCode::REGULAR:
        _price.reset(new RegularPrice);
        break;
    case PriceCode::CHILDRENS:
        _price.reset(new ChildrensPrice);
        break;
    case PriceCode::NEW_RELEASE:
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
    return _price->getCharge(daysRented);
}

int Movie::getFrequentRenterPoints(int daysRented) const
{
    return _price->getFrequentRenterPoints(daysRented);
}

const int Movie::CHILDRENS;
const int Movie::REGULAR;
const int Movie::NEW_RELEASE;
