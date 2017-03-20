#pragma once

#include <string>

class Movie
{
public:
    static const int CHILDRENS   = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    Movie( const std::string& title, int priceCode = REGULAR );

    int getPriceCode() const;
    void setPriceCode( int arg );
    std::string getTitle() const;

private:
    std::string _title;
    int _priceCode;
};
