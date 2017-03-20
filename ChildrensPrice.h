#pragma once

#include "Price.h"

class ChildrensPrice: public Price
{
public:
    virtual PriceCode getPriceCode() const override;
    virtual double getCharge( int daysRented ) const override;
};
