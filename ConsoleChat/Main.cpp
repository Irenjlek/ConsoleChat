#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <iostream>
#include <ctime>

int main() {
	Chat *chat = new Chat();


	std::cout << "create---------------" << std::endl;
	chat->createNewUser("Irina", "@Irina", "12345");
	chat->createNewUser("Roman", "@Roman", "67890");
	chat->createNewUser("Irina", "@irina", "23456");
	chat->createNewUser("Elena", "@Elena", "35467");
	std::cout << "show------------" << std::endl;
	chat->showActive();
	chat->showAll();
	
	chat->login("@Irina", "23456");
	std::cout << "show1-------" << std::endl;
	chat->showActive();

	chat->login("@Irina", "12345");
	std::cout << "show2-------" << std::endl;
	chat->showActive();

	chat->login("Anton", "12345");
	std::cout << "show3-------" << std::endl;
	chat->showActive();

	std::cout << std::endl;		
	
	bool _true = true;
	char choose;
	while (_true)
	{
		chat->showMenuAddMessege(); // 1 - One, 2 - All, 3 - Exit	    
	    std::cin >> choose;
		while (std::cin.get() != '\n')
			continue;
	    std::string message;
		std::string name_ricipient;
		std::string log_ricipient;
		switch (choose)
		{
		case '1':		
		    {
		      std::cout << "You are : " << chat->getActiveUser()->getName() << std::endl;
			  std::cout << "Choоse the ricipient: \n";
			  std::cout << *chat << std::endl;
			  std::getline (std::cin,name_ricipient);
			  
			  if (!(chat->isontheList(name_ricipient)))	     	  
				    continue;			    

			  if (!chat->isUnicName(name_ricipient)) // eсли имя не уникальное то проходим, нет - переходим на else
			    {			    
			      std::cout << "The name is not unique, chose name by login list : \n";
			    	chat->showAllLogin();
			    	std::cout << std::endl;
	     		  	std::string login_from_list;
	    			std::getline(std::cin, login_from_list);
	     			log_ricipient = login_from_list;	
				
				
	    		} else
			      log_ricipient = chat->getLoginByName(name_ricipient);
			      std::cout << std::endl;
			      std::cout << "The logricipient is :" << log_ricipient << std::endl;
			      std::cout << std::endl;
			      std::cout << "write a message\n";
			      std::getline(std::cin,message);
			      std::cout << std::endl;
			      chat->write(message, chat->getUser(log_ricipient));
			      time_t result = time(NULL);
			      char str[26];
			      ctime_s(str, sizeof str, &result);
			     std::cout << chat->getActiveUser()->getName() << std::setw(35) << str <<std::setw(30) 
			    	<< "--->"<< std::setw(30)
			    	<< chat->getNameByLogin(log_ricipient) << std::endl << std::endl << std::setw(15) << "\" " << message << " \""
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
	
	std::cout << "showAllMesseges : \n";
	
	chat->showAllMessages();



	delete chat;

	
	
	std::cout << "Done!";

	return 0;
}