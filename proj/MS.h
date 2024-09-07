#pragma once
#include <list>
#include <fstream>
#include "User.h"

class MS {
private:
	std::list<User*> users;
	int size;
	const std::string adminPhrase = "hello admin";
	std::fstream file;

public:
	MS();
	~MS();
	int getSize();
	int addUser(std::string login, std::string password, bool isAdmin);
	User* findUserByLogin(std::string login);
	int checkLogin(std::string login);
	int checkPassword(std::string password);
	bool checkStatus(std::string userPhrase);
	std::list<User*> getAllUsers();
};