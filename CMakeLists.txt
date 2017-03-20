project(movie_rental)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)
add_subdirectory(tests)
add_library(MovieRental OBJECT Rental.cpp Movie.cpp Customer.cpp NewReleasePrice.cpp RegularPrice.cpp ChildrensPrice.cpp)

add_executable(${PROJECT_NAME} $<TARGET_OBJECTS:MovieRental> main.cpp)
