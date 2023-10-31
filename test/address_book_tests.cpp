#include "address_book.h"
#include <gtest/gtest.h>
#include <string>
//
///  Sample test data
std::string people[][3] = {
		{"Sally", "Graham", "+44 7700 900297"},
		{"Phoenix", "Bond", "0161 496 0311"},
		{"Aaran", "Parks", ""},
		{"Jayden", "Riddle", "+44 131 496 0609"},
		{"Adriana", "Paul", "(739) 391-4868"},
		{"Hamza", "Bo", "+44 131 496 0571"}
	};

///  Sample test data
AddressBook AddTestPeople()
{
	AddressBook addressBook;
	// Add all of the test data to the address book
	for (auto person : people)
	{
		AddressBook::Entry entry = { person[0], person[1], person[2] };
		addressBook.add(entry);
	}
	return addressBook;
}


/// Tests that it is possible to add a person to the address book.
TEST(AddressBookTests, AddPerson)
{
	AddressBook ab;
	// Add just the first person to an empty address book
	AddressBook::Entry entry = { people[0][0], people[0][1], people[0][2] };
	ab.add(entry);

	// Get the contents of the address book
	std::vector<AddressBook::Entry> results = ab.sortedByFirstName();
	
	// There should only be 1 entry in the results
	ASSERT_EQ(results.size(), 1);

	// Validate that the name and phone number is correct
	ASSERT_EQ(results[0].first_name, people[0][0]);
	ASSERT_EQ(results[0].last_name, people[0][1]);
	ASSERT_EQ(results[0].phone_number, people[0][2]);
}


/// Tests that entries are sorted by first name correctly.
TEST(AddressBookTests, SortedByFirstNames)
{
	// The correctly sorted test data 
	const std::string people_sortedFirstNames[][3] = {
		{"Aaran", "Parks", ""},
		{"Adriana", "Paul", "(739) 391-4868"},
		{"Hamza", "Bo", "+44 131 496 0571"},
		{"Jayden", "Riddle", "+44 131 496 0609"},
		{"Phoenix", "Bond", "0161 496 0311"},
		{"Sally", "Graham", "+44 7700 900297"},
	};

	// Populate the address book
	AddressBook ab = AddTestPeople();

	// Sort by first names
	std::vector<AddressBook::Entry> results = ab.sortedByFirstName();

	// There should only be 6 entries in the results 
	ASSERT_EQ(results.size(), 6);

	// Validate that all of the results exactly match the desired output
	for (size_t i=0; i < results.size(); i++)
	{
		auto personResult = results[i];
		auto personAnswer = people_sortedFirstNames[i];

		ASSERT_EQ(personResult.first_name, personAnswer[0]);
		ASSERT_EQ(personResult.last_name, personAnswer[1]);
		ASSERT_EQ(personResult.phone_number, personAnswer[2]);
	}
}


/// Tests that entries are sorted by last name correctly.
TEST(AddressBookTests, SortedByLastNames)
{
	const std::string people_sortedLastNames[][3] = {
		{"Hamza", "Bo", "+44 131 496 0571"},
		{"Phoenix", "Bond", "0161 496 0311"},
		{"Sally", "Graham", "+44 7700 900297"},
		{"Aaran", "Parks", ""},
		{"Adriana", "Paul", "(739) 391-4868"},
		{"Jayden", "Riddle", "+44 131 496 0609"},
	};

	// Populate the address book
	AddressBook ab = AddTestPeople();

	// Sort by last names
	std::vector<AddressBook::Entry> results = ab.sortedByLastName();

	// There should only be 6 entries in the results 
	ASSERT_EQ(results.size(), 6);

	// Validate that all of the results exactly match the desired output
	for (size_t i = 0; i < results.size(); i++)
	{
		auto personResult = results[i];
		auto personAnswer = people_sortedLastNames[i];

		ASSERT_EQ(personResult.first_name, personAnswer[0]);
		ASSERT_EQ(personResult.last_name, personAnswer[1]);
		ASSERT_EQ(personResult.phone_number, personAnswer[2]);
	}
}


/// Tests that an entry can be found in the address book.
TEST(AddressBookTests, FindPerson)
{
	// Populate the address book
	AddressBook ab = AddTestPeople();

	// Find a person whose name is, or starts with "Graham"
	std::vector<AddressBook::Entry> results = ab.find("Graham");

	// There should only be exactly 1 entry in the results 
	ASSERT_EQ(results.size(), 1);

	// Validate that the result is the entry we expected
	ASSERT_EQ(results[0].first_name, "Sally");
	ASSERT_EQ(results[0].last_name, "Graham");
	ASSERT_EQ(results[0].phone_number, "+44 7700 900297");
}
 

/* Tests that an entry can be found in the address book and that the search criteria is case insensitive
   e.g. find("Jayden") will have the same return value as find("jayden") */
 TEST(AddressBookTests, CaseInsensitive)
 {
	 // Populate the address book
	 AddressBook ab = AddTestPeople();

	 /* Find a person whose name is, or starts with "Jayden", "JAYDEN" and "jayden"
	    these 3 tests should return the same entry */
	 std::vector<AddressBook::Entry> results1 = ab.find("Jayden");
	 std::vector<AddressBook::Entry> results2 = ab.find("JAYDEN");
	 std::vector<AddressBook::Entry> results3 = ab.find("jayden");

	 // There should only be exactly 1 entry in results1, results2 and results3 
	 ASSERT_EQ(results1.size(), 1);
	 ASSERT_EQ(results2.size(), 1);
	 ASSERT_EQ(results3.size(), 1);

	 /* Validate that the result is the entry we expected for all 3 tests
		All 3 tests should have the same first_name, last_name and phone_number */
	 ASSERT_EQ(results1[0].first_name, "Jayden");
	 ASSERT_EQ(results1[0].last_name, "Riddle");
	 ASSERT_EQ(results1[0].phone_number, "+44 131 496 0609");

	 ASSERT_EQ(results2[0].first_name, "Jayden");
	 ASSERT_EQ(results2[0].last_name, "Riddle");
	 ASSERT_EQ(results2[0].phone_number, "+44 131 496 0609");

	 ASSERT_EQ(results3[0].first_name, "Jayden");
	 ASSERT_EQ(results3[0].last_name, "Riddle");
	 ASSERT_EQ(results3[0].phone_number, "+44 131 496 0609");
 }


int main(int argc, char** argv) {
	//tests
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}