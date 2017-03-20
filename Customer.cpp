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

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    vector< Rental >::iterator iter = _rentals.begin();
    vector< Rental >::iterator iter_end = _rentals.end();
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for ( ; iter != iter_end; ++iter ) {
        const Rental &rental = *iter;
        frequentRenterPoints += rental.getFrequentRenterPoints();

        // show figures for this rental
        result << "\t" << rental.getMovie().getTitle() << "\t"
               << rental.getCharge() << "\n";
        totalAmount += rental.getCharge();
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}
