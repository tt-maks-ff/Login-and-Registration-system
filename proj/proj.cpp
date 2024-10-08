#include <iostream>
#include <string>
#include <iomanip>
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
		if (!userLogin.empty() && !userPassword.empty()) std::cout << "3. Show my password" << std::endl;
		if (!userLogin.empty() && !userPassword.empty() && isAdmin) std::cout << "4. Show all users" << std::endl;
		std::cout << "0. Exit" << std::endl;


		std::string choice;
		std::getline(std::cin, choice);

		if ((choice.length() != 1) ||
			((static_cast<int>(choice[0]) < 48 || static_cast<int>(choice[0]) > 51) && !userLogin.empty() && !userPassword.empty() && !isAdmin) ||
			((static_cast<int>(choice[0]) < 48 || static_cast<int>(choice[0]) > 50) && userLogin.empty() && userPassword.empty())) {
			std::cout << "Choose correct number." << std::endl;
			std::system("pause");
			continue;
		}

		

		switch (static_cast<int>(choice[0])) {
			case 48: return 0;
			case 49: {
				while (true) {
					std::system("cls");
					std::cout << "Enter your login: ";
					std::getline(std::cin, userLogin);
					std::cout << "Enter your password: ";
					std::getline(std::cin, userPassword);

					User* target = ms.findUserByLogin(userLogin);
					if (target && target->getPassword() == userPassword) {
						std::system("cls");
						std::cout << "Hello, dear user!" << std::endl;
						isAdmin = target->checkStatus();
						std::system("pause");
						break;
					}
					else if (!target) {
						std::system("cls");
						std::cout << "Error. Try again." << std::endl;
						userLogin.clear();
						userPassword.clear();
						isAdmin = false;
						std::system("pause");
						break;
					}
					else {
						std::system("cls");
						std::cout << "Incorrect password. Try again." << std::endl;
						userLogin.clear();
						userPassword.clear();
						isAdmin = false;
						std::system("pause");
						break;
					}
				}

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
					std::cout << "Password rules: \n -8+ symbols \n -upper- and lower- case letters \n -at least 1 digit \n -only latin letters \n -one of '# $ % &' necessary \n\n\n\n" << std::endl;
					std::cout << "Login: " << userLogin << std::endl;
					std::cout << "Password: ";
					std::getline(std::cin, userPassword);
					std::cout << std::endl;

					if (!ms.checkPassword(userPassword)) {
						std::system("cls");
						std::cout << "Password rules: \n -8+ symbols \n -upper- and lower- case letters \n -at least 1 digit \n -only latin letters \n -one of '# $ % &' necessary \n\n\n\n" << std::endl;
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
					isAdmin = false;
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

				break;
			}
			case 51: {
				std::system("cls");
				std::cout << "Your password: " << userPassword << std::endl;
				std::system("pause");

				break;
			}
			case 52: {
				std::system("cls");

				std::list<User*> users = ms.getAllUsers();
				
				std::cout << "No." << std::setw(12) << "user_login" << std::setw(15) << "user_password" << std::setw(10) << "is_admin" << std::endl;

				int i = 0;
				for (auto user : users) {
					std::cout << i++ << std::setw(12) << user->getLogin() << std::setw(15) << user->getPassword() << std::setw(10) << user->checkStatus() << std::endl;
				}
					
				std::cout << "\n\n\n" << std::endl;
				std::system("pause");
				break;
			}
			default: {
				std::system("cls");
				std::cout << "Coming soon." << std::endl;
				std::system("pause");
				break;
			}
		}
	}

	return 0;
}