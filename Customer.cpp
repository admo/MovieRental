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
    vector< Rental >::iterator iter = _rentals.begin();
    vector< Rental >::iterator iter_end = _rentals.end();
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for ( ; iter != iter_end; ++iter ) {
        const Rental &rental = *iter;

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
  vector< Rental >::const_iterator iter = _rentals.begin();
  vector< Rental >::const_iterator iter_end = _rentals.end();
  for ( ; iter != iter_end; ++iter ) {
    Rental rental = *iter;
    result += rental.getCharge();
  }
  return result;
}

int Customer::getTotalFrequentRenterPoints() const
{
  int result = 0;
  vector< Rental >::const_iterator iter = _rentals.begin();
  vector< Rental >::const_iterator iter_end = _rentals.end();
  for ( ; iter != iter_end; ++iter ) {
    Rental rental = *iter;
    result += rental.getFrequentRenterPoints();
  }
  return result;
}
