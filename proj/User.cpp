#include "User.h"
#include <iostream>

User::User() {
	isAdmin = false;
}

int User::setLogin(std::string login) {
	if (login.empty()) return 1;
	try {
		this->login = login;
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	return 0;
}

int User::setPassword(std::string password) {
	if (password.empty()) return 1;
	try {
		this->password = password;
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	return 0;
}

int User::checkStatus() {
	return isAdmin;
}

int User::changeStatus() {
	try {
		this->isAdmin = !this->isAdmin;
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	return 0;
}

std::string User::getLogin() {
	try {
		return this->login;
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
}

std::string User::getPassword() {
	try {
		return this->password;
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
}

User::~User() {}