# C++ PROGRAMMING TASK: ADDRESS BOOK

This package contains an initial project to help you get started with the Address Book programming task. The project cam be built using CMake on either Linux or Windows. The cmake project defines a static library for the address book implementation, and some unit tests that make use of the GoogleTest library. GoogleTest will be downloaded as part of the configuration process, so you do not need to install it yourself.


# Files

**src/include/address_book.h** - Initial declaration of the AddressBook class
**src/address_book.cpp** - Implementation of the AddressBook class 
**test/address_book_tests.cpp** - A small selection of Unit tests
**test/CMakeLists.txt** - Configuration of GoogleTest and Unit tests
**CMakeLists.txt** - Overall project configurations

# Getting Started
## Implementation
This project can be considered a starting point for your solution. You are free to make any modifications to the files or structure that you wish. The shortest starting point would be to begin implementing the address book functions in **src/address_book.cpp**

## Requirements
 - CMake 3.20 or higher
 - A compiler supporting C++20. e.g.
    - GCC 8+
    - Visual Studio 2022+

## Building 
You can build the project via an IDE that supports cmake, or with the following commands:

    cmake -S . -B out
    cmake --build out

## Testing
Run unit tests with the following command:

    cd out
    ctest --output-on-failure 

