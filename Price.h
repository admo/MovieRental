#pragma once

class Price {
public:
    virtual ~Price();
    virtual int getPriceCode() const = 0;
    virtual double getCharge( int daysRented ) const = 0;
};

inline Price::
~Price()
{}
