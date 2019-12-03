#include <iostream>
#include "StringMethods.h"

int main() {

	// testing conversion methods:
	std::cout << "CONVERSION METHODS\n-------------------\n";
	std::cout << StringMethods::toString(432) << " is now a string!\n";
	std::cout << StringMethods::toInt("83201") << " is now an integer!\n";
	int product = StringMethods::toInt("201") + StringMethods::toInt("43");
	std::cout << StringMethods::toString(product) << " was calculated with our methods!\n\n";

	// testing capitalization methods:
	std::cout << "CAPITALIZATION METHODS\n-----------------------\n";
	std::string originalString = "tHiS StrInG iS vErY sTrAnGe, lEt'S trY To fIx iT! 1..2..3.. GO!";
	std::cout << "Original: " << originalString << "\n";
	std::cout << "ToUpper: " << StringMethods::toUpper(originalString) << "\n";
	std::cout << "ToLower: " << StringMethods::toLower(originalString) << "\n";
	std::cout << "ToCamel: " << StringMethods::toCamel(originalString) << "\n\n";

	// testing split method:
	std::cout << "SPLIT METHOD\n-------------\n";
	originalString = "My String";
	std::cout << "Original: " << originalString << "\n";
	std::cout << "First half: " << StringMethods::split(originalString, ' ')[0] << "\n";
	std::cout << "Second half: " << StringMethods::split(originalString, ' ')[1] << "\n\n";

	// testing concat method:
	std::cout << "CONCAT METHOD\n--------------\n";
	std::string str1 = "First String"; std::string str2 = "Second String";
	std::cout << str1 << "\n" << str2 << "\n";
	std::cout << "Combined: " << StringMethods::concat(str1, str2) << "\n\n";

	// testing contains method:
	std::cout << "CONTAINS METHOD\n----------------\n";
	std::string contString = "What's in this string?";
	std::cout << "String to check for 'this': " << contString << "\n";
	if (StringMethods::contains(contString, "this")) {
		std::cout << "The string contains the word 'this'\n\n";;
	}

	system("PAUSE");
}