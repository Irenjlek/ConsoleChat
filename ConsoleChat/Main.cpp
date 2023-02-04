#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <iostream>
#include <ctime>

int main() {
	std::shared_ptr<Chat> chat = std::shared_ptr<Chat>(new Chat());
	std::string name, login, password;

	std::cout << "Hello! Let's start!" << std::endl;

	char choose;
	while (true)
	{
		while (chat->getActiveUser() == nullptr) {
			std::cout << "Would you like login(enter 'L'), register(enter 'R') or quit(enter 'Q')?" << std::endl;
			char selection;
			std::cin >> selection;
			switch (selection)
			{
			case 'R':
			{
				std::string name, login, password;
				std::cout << "Enter login" << std::endl;
				std::cin >> login;
				if (chat->isLoginExist(login)) {
					std::cout << "User with login " << login << " is already exists." << std::endl;
					break;
				}					
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
				if (!chat->isLoginExist(login)) 
				{
					std::cout << "User with login " << login << " does not exist." << std::endl;
					break;
				} 
				std::cout << "Enter password" << std::endl;
				std::cin >> password;
				for (int i = 0; i < 3; i++) 
				   {
					if (chat->login(login, password))
					   {
						  std::cout << std::endl;
						  chat->showAllUserMesseges(chat->getActiveUser());
						  std::cout << std::endl;
						  break;
					    } 
					    else if (i != 2) 
						  {
					    	std::cout << "Enter password (" << 2 - i << " tries left)" << std::endl;
					    	std::cin >> password;
					      }
				   }			
				
				break;
			}
			case 'Q':
				std::cout << "Good luck, bye!" << std::endl;
				return 0;
			default:
				std::cout << "Enter L, R or Q" << std::endl;
				break;
			}
		}

		
		chat->showMenuAddMessege(); // 1 - One, 2 - All, 3 - Exit	    
	    std::cin >> choose;
		while (std::cin.get() != '\n')
			continue;
	    std::string message;
		std::string name_recipient;
		std::string log_recipient;
		switch (choose)
		{
		case '1':		
		    {
		      std::cout << "You are : " << chat->getActiveUser()->getName() << std::endl;
			  std::cout << "Choоse the recipient: \n";
			  std::cout << *chat << std::endl;
			  std::getline (std::cin,name_recipient);
			  
			  if (!(chat->isontheList(name_recipient)))	     	  
				    continue;			    

			  if (!chat->isUnicName(name_recipient)) // eсли имя не уникальное то проходим, нет - переходим на else
			    {			    
			      std::cout << "The name is not unique, chose name by login list : \n";
			    	chat->showAllLogin();
			    	std::cout << std::endl;
	     		  	std::string login_from_list;
	    			std::getline(std::cin, login_from_list);
	     			log_recipient = login_from_list;	
				
				
	    		} else
			      log_recipient = chat->getLoginByName(name_recipient);
			      std::cout << std::endl;
			      std::cout << "The logrecipient is :" << log_recipient << std::endl;
			      std::cout << std::endl;
			      std::cout << "write a message\n";
			      std::getline(std::cin,message);
			      std::cout << std::endl;
			      chat->write(message, chat->getUser(log_recipient));
			      time_t result = time(NULL);
			      char str[26];
			      ctime_s(str, sizeof str, &result);
			     std::cout << chat->getActiveUser()->getName() << std::setw(35) << str <<std::setw(30) 
			    	<< "--->"<< std::setw(30)
			    	<< chat->getNameByLogin(log_recipient) << std::endl << std::endl << std::setw(15) << "\" " << message << " \""
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
			chat->setActiveUser(nullptr);
			break;
		    }

		default: std::cout << "bad choose mode, try again! \n";
			continue;
		}

	}

	std::cout << "Done!";

}