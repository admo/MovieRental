project(movie_rental)
cmake_minimum_required(VERSION 2.8)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR})

add_library(MovieRentalTests OBJECT MovieRentalTests.cpp)

add_executable(AllTests
    $<TARGET_OBJECTS:MovieRentalTests> $<TARGET_OBJECTS:MovieRental>
    )

target_link_libraries(AllTests gtest_main)
