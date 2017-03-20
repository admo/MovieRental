#pragma once

enum class PriceCode
{
    REGULAR,
    NEW_RELEASE,
    CHILDRENS
};

class Price {
public:
    virtual ~Price();
    virtual PriceCode getPriceCode() const = 0;
    virtual double getCharge( int daysRented ) const = 0;
    virtual int getFrequentRenterPoints( int daysRented ) const;
};

inline Price::
~Price()
{}
