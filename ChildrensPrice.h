#pragma once

#include "Price.h"

class ChildrensPrice: public Price
{
public:
    virtual int getPriceCode() const;
};
