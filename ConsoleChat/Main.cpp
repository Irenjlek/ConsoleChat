#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <iostream>

int main() {
	Chat *chat = new Chat();
	std::string name, login, password;

	std::cout << "Hello! Please enter your name" << std::endl;
	std::cin >> name;
	std::cout << "Enter login" << std::endl;
	std::cin >> login;
	std::cout << "Enter password" << std::endl;
	std::cin >> password;
	
	chat->createNewUser(name, login, password);

	//сюда выбор написать сообщение или разлогиниться

	bool keep = true;
	while (keep) {
		std::cout << "Would you like login(enter 'L'), register(enter R) or quit(enter Q)?" << std::endl;
		char selection;
		std::cin >> selection;
		switch (selection)
		{
		case 'R':
		{
			std::string name, login, password;
			std::cout << "Enter login" << std::endl;
			std::cin >> login;
			if (chat->isLoginExist(login))
				break;
			std::cout << "Enter password" << std::endl;
			std::cin >> password;
			std::cout << "Enter name" << std::endl;
			std::cin >> name;
			chat->createNewUser(name, login, password);
			break;
		}

		case 'L':
		{
			std::string login, password;
			std::cout << "Enter login" << std::endl;
			std::cin >> login;
			if (!chat->isLoginExist(login)) {
				std::cout << "User with login " << login << " does not exist." << std::endl;
				break;
			}
			std::cout << "Enter password" << std::endl;
			std::cin >> password;
			for (int i = 0; i < 3; i++) {
				if (chat->login(login, password))
					break;
				else if (i != 2) {
					std::cout << "Enter password (" << 2 - i << " tries left)" << std::endl;
					std::cin >> password;
				}					
			}
			break;
		}
		case 'Q':// пока здесь выход из цикла, чтобы посмотреть результат, потом будет выход из всей программы
			std::cout << "Good luck, bye!" << std::endl;
			keep = false;
			break;
		default:
			std::cout << "Enter L or R" << std::endl;
			break;
		}
	}

	chat->showAll();
	chat->showActive();

	
	

	delete chat;
	return 0;
}