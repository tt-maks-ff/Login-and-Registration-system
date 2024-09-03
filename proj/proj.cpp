#include <iostream>
#include <string>

std::string userLogin;
std::string userPsassword;

int main() {
	while (true) {
		std::system("cls");
		std::cout << "Account info: " << std::endl;

		if (userLogin.empty()) {
			std::cout << "Login: " << "None" << std::endl;
		} 
		else {
			std::cout << "Login: " << userLogin << std::endl;
		}

		if (userPsassword.empty()) {
			std::cout << "Password: " << "None" << std::endl;
		}
		else {
			std::cout << "Password: " << "Hidden" << std::endl << std::endl;
		}

		std::cout << "1. Login to existing account" << std::endl;
		std::cout << "2. Create a new account" << std::endl;
		std::cout << "0. Exit" << std::endl;

		std::string choice;
		std::getline(std::cin, choice);

		if (choice.length() != 1) continue;
		if (static_cast<int>(choice[0]) < 48 || static_cast<int>(choice[0]) > 50) continue;

		switch (static_cast<int>(choice[0])) {
			case 48: return 0;
			case 49: {
				// login
				break;
			}
			case 50: {
				//creating
				break;
			}
		}
	}

	return 0;
}