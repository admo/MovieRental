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

    Movie(const std::string& title, PriceCode priceCode = PriceCode::REGULAR );
    Movie( const Movie& movie );
    Movie& operator=( const Movie& rhs );

    PriceCode getPriceCode() const;
    void setPriceCode(PriceCode arg );
    std::string getTitle() const;
    double getCharge( int daysRented ) const;
    int getFrequentRenterPoints( int daysRented ) const;

private:
    std::string _title;
    std::unique_ptr<Price> _price;
};
