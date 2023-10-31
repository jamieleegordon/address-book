#pragma once

#include <string>
#include <vector>

/// The main Address Book implementation
class AddressBook {
public:
	/// A container for address book data
	struct Entry
	{
		std::string first_name;
		std::string last_name;
		std::string phone_number;
	};

	// vector container for the collection of entries in the address book
	// new entries will be added to this vector
	std::vector<Entry> entries;

	/// Add an entry
	void add(Entry person);

	/// Remove an entry
	void remove(Entry person);
	
	/// Return all entries sorted by first names
	std::vector<Entry> sortedByFirstName();

	/// Return all entries sorted by last names
	std::vector<Entry> sortedByLastName();

	// change names to lower case to ensure the find function is case insensitive
	// e.g. find("Sally") and find("sally") will have the same result
	std::string lowerCase(std::string name);

	/// Return all matching entries
	std::vector<Entry> find(const std::string & name);
};