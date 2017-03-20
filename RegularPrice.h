#pragma once

#include "Price.h"

class RegularPrice: public Price
{
public:
    virtual int getPriceCode() const;
};
