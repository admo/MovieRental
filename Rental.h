#pragma once

#include "Movie.h"

class Rental {
public:
    Rental( const Movie& Movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;
    double getCharge() const;

private:
    Movie _movie;
    int _daysRented;
};
