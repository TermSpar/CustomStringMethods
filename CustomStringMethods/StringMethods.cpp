#include "StringMethods.h"

StringMethods::StringMethods() {
}

/********** toUpper **********/

// convert string to uppercase:
std::string StringMethods::toUpper(std::string str) {
	std::string retString = "";
	for (int i = 0; i < str.length(); i++) {
		// if the letter is lowercase:
		if (str.at(i) >= 97 && str.at(i) <= 122) {
			// make it uppercase:
			retString += (str.at(i) - ASCII_LETTER_CONSTANT);
		}
		else {
			// otherwise just leave it:
			retString += str.at(i);
		}
	}
	return retString;
}

/********** toLower **********/

// convert string to lowercase:
std::string StringMethods::toLower(std::string str) {
	std::string retString = "";
	for (int i = 0; i < str.length(); i++) {
		// if the letter is uppercase:
		if (str.at(i) >= 65 && str.at(i) <= 90) {
			// make it lowercase:
			retString += (str.at(i) + ASCII_LETTER_CONSTANT);
		}
		else {
			// otherwise just leave it:
			retString += str.at(i);
		}
	}
	return retString;
}

/********** toCamel **********/

// convert string to camelcase:
std::string StringMethods::toCamel(std::string str) {
	std::string retString = "";
	for (int i = 0; i < str.length(); i++) {
		// if the char is uppercase
		if ((str.at(i) >= 65 && str.at(i) <= 90)) {
			// if it's first or right after a space:
			if (i == 0 || str.at(i - 1) == ' ') {
				// leave it:
				retString += str.at(i);
			}
			else {
				// otherwise make it lowercase:
				retString += (str.at(i) + ASCII_LETTER_CONSTANT);
			}
		}
		// if the char is lowercase
		else if ((str.at(i) >= 97 && str.at(i) <= 122)) {
			// if it's first or right after a space:
			if (i == 0 || str.at(i - 1) == ' ') {
				// make it uppercase:
				retString += (str.at(i) - ASCII_LETTER_CONSTANT);
			}
			else {
				// otherwise leave it:
				retString += (str.at(i));
			}
		}
		else {
			// if not a char, then leave it:
			retString += str.at(i);
		}
	}
	return retString;
}

/********** toString **********/

// convert integer to string:
std::string StringMethods::toString(int num) {
	std::list<int> digits;
	std::string finalString = "";

	// if the number is zero, leave it:
	if (num == 0) {
		digits.push_back(0);
	}
	// otherwise:
	else {
		// loop through every digit:
		while (num != 0) {
			// isolate it and put it in digits list:
			int last = num % 10;
			digits.push_front(last);
			num = (num - last) / 10;
		}
	}
	// loop digits list:
	for (std::list<int>::iterator it = digits.begin(); it != digits.end(); ++it) {
		// convert each digit to ascii by adding 48, and add it to finalString:
		finalString += (*it + ASCII_NUM_CONSTANT);
	}
	return finalString;
}

/********** toInt **********/

// convert string to integer:
int StringMethods::toInt(std::string str) {
	std::vector<int> intVec;
	int finalInt = 0;
	int digitPlaces = str.length();

	// get each digit as an int into intVec:
	for (int i = digitPlaces - 1; i >= 0; i--) {
		intVec.push_back(str.at(i) - ASCII_NUM_CONSTANT);
	}

	// combine digits:
	int place = 1;
	for (int i = 0; i < digitPlaces; i++) {
		// if the digit is a zero, just mult places by 10:
		if (intVec.at(i) == 0) {
			place *= 10;
		}
		// otherwise mult the current num by its place, and add it to finalNum:
		else {
			finalInt += intVec.at(i) * place;
			place *= 10;
		}
	}
	return finalInt;
}

/********** split **********/

// split a string on a certain char:
std::vector<std::string> StringMethods::split(std::string str, char breakOn) {
	std::vector<std::string> sVec;
	std::string statement = "";
	str += breakOn;
	// traverse str:
	for (unsigned int i = 0; i < str.size(); i++) {
		// if iteration != breakOn:
		if (str.at(i) != breakOn) {
			// add it to statement:
			statement += str.at(i);
		}
		// if iteration == breakOn:
		else if (str.at(i) == breakOn) {
			// push vector with statement
			statement += str.at(i);
			sVec.push_back(statement);
			// reset statement:
			statement = "";
		}
	}
	// remove appended char
	statement += sVec.at(1);
	statement = statement.substr(0, statement.length() - 1);
	sVec.at(1) = statement;

	return sVec;
}

StringMethods::~StringMethods() {
}
