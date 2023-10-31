# This file downloads the google test library for unit testing.
# See https://github.com/google/googletest.git for more information on googletest
# To run unit tests execute: ctest

cmake_minimum_required (VERSION 3.20)

# Set up GoogleTest dependency
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# Create an executable from our test code
add_executable(AddressBookTests "address_book_tests.cpp")

# Link the test executable against google test and the main address book library
target_link_libraries(AddressBookTests 
	PUBLIC 
	GTest::GTest
	libAddressBook)

# Tell CTest of the tests we with to run
add_test(NAME PrimaryTests COMMAND AddressBookTests)
