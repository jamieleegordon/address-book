# Address Book build template
cmake_minimum_required (VERSION 3.20)

# Define the project
project (AddressBook LANGUAGES CXX)

# Allow up to C++20
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable support for unit testing, configured in the "test" subdirectory
enable_testing ()

# Define a static "address book" library 
add_library(libAddressBook STATIC src/address_book.cpp src/include/address_book.h)
target_include_directories(libAddressBook PUBLIC src/include)

# Ensure tests are included
add_subdirectory (test)

