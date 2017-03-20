#pragma once

#include <string>
#include <memory>
#include "Price.h"

class Movie
{
public:
    static const int CHILDRENS   = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    Movie( const std::string& title, int priceCode = REGULAR );
    Movie( const Movie& movie );
    Movie& operator=( const Movie& rhs );

    int getPriceCode() const;
    void setPriceCode( int arg );
    std::string getTitle() const;
    double getCharge( int daysRented ) const;
    int getFrequentRenterPoints( int daysRented ) const;

private:
    std::string _title;
    std::unique_ptr<Price> _price;
};
