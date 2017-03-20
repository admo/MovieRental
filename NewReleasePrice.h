#pragma once

#include "Price.h"

class NewReleasePrice: public Price
{
public:
    virtual int getPriceCode() const;
    virtual double getCharge( int daysRented ) const;
    virtual int getFrequentRenterPoints( int daysRented ) const;
};
