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
			// if not a letter, then leave it:
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

/********** concat **********/

// combine two strings:
std::string StringMethods::concat(std::string str1, std::string str2) {
	std::string retString;
	retString = str1 + str2;
	return retString;
}

/********** substring **********/

// get string from one index to another:
std::string StringMethods::substring(std::string str, int start, int end) {
	std::string retString;
	// copy all chars from specified start to specified end into retString:
	for (int i = start; i < end; i++) {
		retString += str.at(i);
	}
	return retString;
}

/********** trim **********/

// trim whitespace off the front and back of a string:
std::string StringMethods::trim(std::string str) {
	std::string retString = str;
	// if the first char is a space:
	if (str.at(0) == ' ') {
		// delete it:
		retString = substring(str, 1, str.length() - 1);
		str = retString;
	}
	// if the last char is a space:
	if (str.at(str.length() - 1) == ' ') {
		// delete it:
		retString = substring(str, 0, str.length() - 1);
	}
	return retString;
}

/********** contains **********/

// check if one string contains another:
bool StringMethods::contains(std::string str, std::string check) {
	for (int i = 0; i < str.length(); i++) {
		// if current char in str is equal to the first char in check:
		if (str.at(i) == check.at(0)) {
			// see if the rest of the characters match:
			int tempCount = i;
			for (int j = 0; j < check.length(); j++) {
				// if the current str letter does not match check's letter:
				if (!(str.at(tempCount) == check.at(j))) {
					// exit the inner loop:
					goto breakOut;
				}
				// otherwise:
				else {
					// if you get to the last letter:
					if (j == (check.length() - 1)) {
						// then the word is there:
						return true;
					}
				}
				tempCount++;
			}
		}
	breakOut:
		std::cout << "";
	}
	// otherwise, the word is not there:
	return false;
}

// check if a string contains a char:
bool StringMethods::contains(std::string str, char check) {
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == check) {
			return true;
		}
	}
	return false;
}

/********** isEqual **********/

// check if two strings are equal (have the same sequence of chars):
bool StringMethods::isEqual(std::string str1, std::string str2) {
	// if the strings are the same length:
	if (str1.length() == str2.length()) {
		for (int i = 0; i < str1.length(); i++) {
			// if a character is not the same:
			if (!(str1.at(i) == str2.at(i))) {
				return false;
			}
			else {
				// if you get to the last char:
				if (i == (str1.length() - 1)) {
					return true;
				}
			}
		}
	}
	// if the strings have different lengths:
	return false;
}

StringMethods::~StringMethods() {
}
