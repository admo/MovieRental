#include <iostream>
#include "Customer.h"

using namespace std;

int main(int argc, char *argv[])
{
    Customer c{"Adam Oleksy"};
    c.addRental({{"Game of Thrones"}, 2});
    c.addRental({{"Stranger Things"}, 1});


    cout << c.statement() << endl;

    return 0;
}
