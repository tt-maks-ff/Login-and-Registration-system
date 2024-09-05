#include <iostream>
#include <string>
#include "User.h"
#include "MS.h"

MS ms;

std::string userLogin;
std::string userPassword;
bool isAdmin;

int main() {
	while (true) {
		std::system("cls");
		std::cout << "Account info: " << std::endl;

		std::cout << "Login: ";
		if (userLogin.empty()) std::cout << "None" << std::endl;
		else std::cout << userLogin << std::endl;

		std::cout << "Password: ";
		if (userPassword.empty()) std::cout << "None" << std::endl;
		else std::cout << "Hidden" << std::endl;

		std::cout << "Admin: ";
		if (isAdmin) std::cout << "true" << std::endl;
		else std::cout << "false" << std::endl;
		std::cout << std::endl;

		std::cout << "1. Login to existing account" << std::endl;
		std::cout << "2. Create a new account" << std::endl;
		std::cout << "0. Exit" << std::endl;

		std::string choice;
		std::getline(std::cin, choice);

		if ((choice.length() != 1) || 
			(static_cast<int>(choice[0]) < 48 || static_cast<int>(choice[0]) > 50)) {
			std::cout << "Choose correct number." << std::endl;
			std::system("pause");
			continue;
		}

		switch (static_cast<int>(choice[0])) {
			case 48: return 0;
			case 49: {
				
				//login
				break;
			}
			case 50: {
				while (true) {
					std::system("cls");
					std::cout << "Login rules: \n -6+ symbols \n -upper- and lower- case letters \n -at least 1 digit \n -only latin letters \n\n\n\n" << std::endl;
					std::cout << "Login: ";
					std:getline(std::cin, userLogin);


					if (!ms.checkLogin(userLogin)) {
						std::system("cls");
						std::cout << "Login rules: \n -6+ symbols \n -upper- and lower- case letters \n -at least 1 digit \n -only latin letters \n\n\n\n" << std::endl;
						std::cout << "Try again. " << std::endl;
						std::system("pause");
						continue;
					}
					else {
						break;
					}
				}

				while (true) {
					std::system("cls");
					std::cout << "Password rules: \n -8+ symbols \n -upper- and lower- case letters \n -at least 1 digit \n -only latin letters \n -one of '# $ & * @' necessary \n\n\n\n" << std::endl;
					std::cout << "Login: " << userLogin << std::endl;
					std::cout << "Password: ";
					std::getline(std::cin, userPassword);
					std::cout << std::endl;

					if (!ms.checkPassword(userPassword)) {
						std::system("cls");
						std::cout << "Password rules: \n -8+ symbols \n -upper- and lower- case letters \n -at least 1 digit \n -only latin letters \n -one of '# $ & * @' necessary \n\n\n\n" << std::endl;
						std::cout << "Try again. " << std::endl;
						std::system("pause");
						continue;
					}
					else {
						break;
					}
				}

				std::string adminCheck;
				while (true) {
					std::system("cls");
					std::cout << "Are you admin? (y/n)" << std::endl;
					std::getline(std::cin, adminCheck);

					if (adminCheck.length() > 1 || adminCheck.empty()) continue;
					if (adminCheck[0] != 'y' && adminCheck[0] != 'n') continue;
					else break;
				}

				switch (adminCheck[0])
				{
				case 'y': {
					std::cout << "Enter admin phrase: ";
					std::string userPhrase;
					std::getline(std::cin, userPhrase);

					isAdmin = ms.checkStatus(userPhrase);
					break;
				}
				case 'n':
					break;
				default:
					break;
				}

				if (!ms.findUserByLogin(userLogin)) ms.addUser(userLogin, userPassword, isAdmin);
				else {
					std::cout << "This login is already taken. Try again" << std::endl;
					userLogin.clear();
					userPassword.clear();
					std::system("pause");
				}
			}
		}
	}

	return 0;
}


// todo: login process