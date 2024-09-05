#pragma once
#include "string"

class User {
private:
	std::string login;
	std::string password;
	bool isAdmin;

public:
	User();
	User(std::string login, std::string password, bool isAdmin);
	~User();
	std::string getLogin();
	std::string getPassword();
	int setLogin(std::string login);
	int setPassword(std::string password);
	int checkStatus();
	int changeStatus();
};