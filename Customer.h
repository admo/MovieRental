#pragma once

#include <string>
#include <vector>
#include "Rental.h"

class Customer {
public:
    Customer();
    explicit Customer( const std::string& name );

    void addRental( const Rental& arg );
    std::string getName() const;
    std::string statement();

private:
    std::string _name;
    std::vector< Rental > _rentals;

    double getTotalCharge() const;
};
