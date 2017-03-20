#pragma once

#include "Price.h"

class NewReleasePrice: public Price
{
public:
    virtual int getPriceCode() const;
};
