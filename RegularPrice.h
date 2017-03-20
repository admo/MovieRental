#pragma once

#include "Price.h"

class RegularPrice: public Price
{
public:
    virtual int getPriceCode() const;
    virtual double getCharge( int daysRented ) const;
};
