#include <sstream>
#include <vector>

#include "Customer.h"

using std::ostringstream;
using std::vector;
using std::string;

Customer::Customer()
{}

Customer::Customer( const string& name )
    : _name( name )
{}

void Customer::addRental( const Rental& arg )
{
    _rentals.push_back( arg );
}

string Customer::getName() const
{
    return _name;
}

string Customer::statement() const
{
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for (const auto& rental: _rentals)
    {
        // show figures for this rental
        result << "\t" << rental.getMovie().getTitle() << "\t"
               << rental.getCharge() << "\n";
    }
    // add footer lines
    result << "Amount owed is " << getTotalCharge() << "\n";
    result << "You earned " << getTotalFrequentRenterPoints()
           << " frequent renter points";
    return result.str();
}

double Customer::getTotalCharge() const
{
    double result = 0;
    for (const auto& rental: _rentals)
        result += rental.getCharge();

    return result;
}

int Customer::getTotalFrequentRenterPoints() const
{
    int result = 0;
    for (const auto& rental: _rentals)
        result += rental.getFrequentRenterPoints();

    return result;
}
