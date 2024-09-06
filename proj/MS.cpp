#include "MS.h"
#include <iostream>

MS::MS() : size(0) {}

int MS::getSize() {
	return this->size;
}

int MS::addUser(std::string login, std::string password, bool isAdmin) {
	try {
		User* newUser = new User{ login, password, isAdmin };
		users.push_back(newUser);
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
		std::system("pause");
		return 1;
	}
	return 0;
}

User* MS::findUserByLogin(std::string login) {
	try {
		for (auto* user : users) {
			if (user->getLogin() == login) return user;
		}
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
	return nullptr;
}

int MS::checkLogin(std::string login) {
	// 6+ symbols
	// upper and lowercase letters
	// at least 1 digit
	// only latin letters

	if (login.length() < 6) return 0;

	bool uppercase, lowercase, digit;
	uppercase = lowercase = digit = false;

	for (char symbol : login) {
		if (static_cast<int>(symbol) < 33 || static_cast<int>(symbol) > 126) return 0;
		if (isupper(symbol)) uppercase = true;
		if (islower(symbol)) lowercase = true;
		if (isdigit(symbol)) digit = true;
	}

	if (uppercase && lowercase && digit) return 1;
	else return 0;
}

int MS::checkPassword(std::string login) {
	// 8+ symbols
	// upper and lowercase letters
	// at least 1 digit
	// only latin letters
	// '#$%&' necessary

	if (login.length() < 6) return 0;

	bool uppercase, lowercase, digit, symb;
	uppercase = lowercase = digit = symb = false;

	for (char symbol : login) {
		if (static_cast<int>(symbol) < 33 || static_cast<int>(symbol) > 126) return 0;
		if (isupper(symbol)) uppercase = true;
		if (islower(symbol)) lowercase = true;
		if (isdigit(symbol)) digit = true;
		if (static_cast<int>(symbol) >= 35 && static_cast<int>(symbol) <= 38) symb = true;
	}

	if (uppercase && lowercase && digit && symb) return 1;
	else return 0;
}

bool MS::checkStatus(std::string userPhrase) {
	if (userPhrase == this->adminPhrase) return true;
	else return false;
}

MS::~MS() {}