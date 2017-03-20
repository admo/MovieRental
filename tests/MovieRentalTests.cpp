#include <gtest/gtest.h>
#include <memory>

#include "Customer.h"

using namespace ::testing;

class MovieRentalTests: public Test
{
protected:
    using CustomerPtr = std::unique_ptr<Customer>;
    CustomerPtr customer;
    Movie THE_HULK{"The Hulk", Movie::CHILDRENS};
    Movie IRON_MAN{"Iron Man", Movie::NEW_RELEASE};
    Movie SPIDER_MAN{"Spiderman", Movie::REGULAR};

public:
    void SetUp()
    {
        customer.reset(new Customer{"Jan Kowalski"});
    }

    void TearDown()
    {
        customer.reset();
    }
};

TEST_F(MovieRentalTests, CustomerWithoutName_GetNameReturnEmptyString)
{
    customer.reset(new Customer{});
    EXPECT_STREQ("", customer->getName().c_str());
}

TEST_F(MovieRentalTests, CustomerWithName_GetNameReturnsGivenName)
{
    EXPECT_STREQ("Jan Kowalski", customer->getName().c_str());
}

TEST_F(MovieRentalTests, CustomerWithEmptyStatement_ShouldGiveEmptyStatementReport)
{
    EXPECT_STREQ("Rental Record for Jan Kowalski\nAmount owed is 0\nYou earned 0 frequent renter points",
                 customer->statement().c_str());
}

TEST_F(MovieRentalTests, basicChildrenRental)
{
    customer->addRental(Rental{THE_HULK, 2});
    EXPECT_STREQ("Rental Record for Jan Kowalski\n\tThe Hulk\t1.5\nAmount owed is 1.5\nYou earned 1 frequent renter points",
                 customer->statement().c_str());
}

TEST_F(MovieRentalTests, shouldDiscountChildrensRentals)
{
    customer->addRental(Rental{THE_HULK, 4});
    EXPECT_STREQ("Rental Record for Jan Kowalski\n\tThe Hulk\t3\nAmount owed is 3\nYou earned 1 frequent renter points",
                 customer->statement().c_str());
}

TEST_F(MovieRentalTests, basicNewReleaseRental)
{
    customer->addRental(Rental{IRON_MAN, 1});
    EXPECT_STREQ("Rental Record for Jan Kowalski\n\tIron Man\t3\nAmount owed is 3\nYou earned 1 frequent renter points",
                 customer->statement().c_str());
}

TEST_F(MovieRentalTests, shouldNotDiscountNewReleaseRentalsButBonusFrequentRenterPoints)
{
    customer->addRental(Rental{IRON_MAN, 4});
    EXPECT_STREQ("Rental Record for Jan Kowalski\n\tIron Man\t12\nAmount owed is 12\nYou earned 2 frequent renter points",
                 customer->statement().c_str());

}

TEST_F(MovieRentalTests, basicRegularRental)
{
    customer->addRental(Rental{SPIDER_MAN, 2});
    EXPECT_STREQ("Rental Record for Jan Kowalski\n\tSpiderman\t2\nAmount owed is 2\nYou earned 1 frequent renter points",
                 customer->statement().c_str());
}

TEST_F(MovieRentalTests, shouldDiscountRegularRental)
{
    customer->addRental(Rental{SPIDER_MAN, 4});
    EXPECT_STREQ("Rental Record for Jan Kowalski\n\tSpiderman\t5\nAmount owed is 5\nYou earned 1 frequent renter points",
                 customer->statement().c_str());
}

TEST_F(MovieRentalTests, shouldSumVariousRentals)
{
    customer->addRental(Rental{THE_HULK, 2});
    customer->addRental(Rental{SPIDER_MAN, 1});
    customer->addRental(Rental{IRON_MAN, 3});
    EXPECT_STREQ("Rental Record for Jan Kowalski\n\tThe Hulk\t1.5\n\tSpiderman\t2\n\tIron Man\t9\nAmount owed is 12.5\nYou earned 4 frequent renter points",
                 customer->statement().c_str());
}
