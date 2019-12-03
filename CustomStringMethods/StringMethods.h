// custom string methods by Ben Bollinger

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>

// difference between actual numbers and their ASCII values:
#define ASCII_NUM_CONSTANT 48
// difference between upper and lowercase letters:
#define ASCII_CHAR_CONSTANT 32

class StringMethods {
public:
	StringMethods();

	// capitalization methods:
	static std::string toUpper(std::string);
	static std::string toLower(std::string);
	static std::string toCamel(std::string);

	// conversion methods:
	static std::string toString(int);
	static int toInt(std::string);

	// split method:
	static std::vector<std::string> split(std::string, char);

	~StringMethods();
};
