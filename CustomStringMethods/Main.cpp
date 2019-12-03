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

	system("PAUSE");
}