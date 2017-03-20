#pragma once

#include "Price.h"

class NewReleasePrice: public Price
{
public:
    virtual PriceCode getPriceCode() const override;
    virtual double getCharge( int daysRented ) const override;
    virtual int getFrequentRenterPoints( int daysRented ) const override;
};
