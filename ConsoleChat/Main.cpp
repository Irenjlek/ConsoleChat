#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <iostream>
#include <ctime>

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

<<<<<<< HEAD
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
=======
	std::cout << std::endl;		
>>>>>>> 8a351ba36002753f5e8dca9731ab264eef956a78

	bool _true = true;
	char choose;
	while (_true)
	{
		chat->showMenuAddMessege(); // 1 - One, 2 - All, 3 - Exit	    
	    std::cin >> choose;
		while (std::cin.get() != '\n')
			continue;
	    std::string message;
		std::string ricipient;
		switch (choose)
		{
		case '1':		
		    {
			std::cout << "You are : " << chat->getActiveUser()->getName() << std::endl;
			std::cout << "Choоse the ricipient: \n";
			std::cout << *chat << std::endl;
			std::getline (std::cin,ricipient);
			if ((chat->getUser(ricipient)->getLogin()) == "\0")
			{
				std::cout << "bad ricipient, try again! \n";
				continue;
			}			
			std::cout << "write a message\n";
			std::getline(std::cin,message);
			std::cout << std::endl;
			chat->write(message, chat->getUser(ricipient));
			time_t result = time(NULL);
			char str[26];
			ctime_s(str, sizeof str, &result);
			std::cout << chat->getActiveUser()->getName() << std::setw(35) << str <<std::setw(30) 
				<< "--->"<< std::setw(30)
				<< ricipient << std::endl << std::endl << std::setw(15) << "\" " << message << " \""
				<< std::endl << std::endl;
		    }
			continue;

		case '2':
		    {
			std::cout << "You are : " << chat->getActiveUser()->getName() << std::endl;
			std::cout << "write a message : \n";
			std::getline(std::cin,message);			
			chat->writeToAll(message);
			std::cout << std::endl;
			time_t result = time(NULL);
			char str[26];
			ctime_s(str, sizeof str, &result);
			std::cout << chat->getActiveUser()->getName() << std::setw(35) << str << std::setw(30)
				<< "--->" << std::setw(30)
				<< "All" << std::endl << std::endl << std::setw(15) << "\" " << message << " \""
				<< std::endl << std::endl;
		    }
			continue;
		
		case '3':
		    {
			std::cout << "Exit! \n";
			break;
		    }

		default: std::cout << "bad choose mode, try again! \n";
			continue;
		}
		
		_true = false;
	}
		
	chat->showAllUserMesseges(chat->getActiveUser());
		
	std::cout << std::endl << std::endl;
	
	//std::cout << *chat << std::endl;
	

	delete chat;

	
	
	std::cout << "Done!";

	return 0;
}