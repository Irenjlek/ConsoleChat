#include "Chat.h"
#include <iostream>

Chat::Chat()
{

}

Chat::~Chat()
{

}

bool Chat::createNewUser(const std::string& name, const std::string& login, const std::string& password)
{

	for (User* user : _users)

	{
		if (user->getLogin() == login) {
			std::cout << "User with login " << login << " is already exists." << std::endl;
			return false;
		}
	}
	User* newUser = new User(name, login, password);
	_users.push_back(newUser);
	setActiveUser(std::make_shared<User>(*newUser));

	return true;
}

void Chat::setActiveUser(const std::shared_ptr<User>& user)
{
	_activeUser = user;
}

bool Chat::login(std::string login, std::string password)
{
	for (User* user : _users)
	{
		if (user->getLogin() == login) {
			if (user->getPassword() == password) {
				setActiveUser(std::make_shared<User>(*user));
			}
			else {
				std::cout << "Password is incorrect." << std::endl;
				return false;
			}
		}
	}
	return true;
}


void Chat::write(std::string text, std::shared_ptr<User>& recipient)
{
	time_t time_mess = time(&time_mess);		
	
	std::shared_ptr <Message> shp_mess(new Message(text, getActiveUser(_users).get()->getName(), 
		                                         recipient.get()->getName(), time_mess));	
	_messeges.push_back(*shp_mess);	
	
}

void Chat::writeToAll(std::string text)
{
	time_t time_mess = time(&time_mess);
	
	
	for (auto ricipient : _users)
	{
		std::shared_ptr <Message> shp_mess(new Message(text, getActiveUser(_users).get()->getName(),
			(*ricipient).getName(), time_mess));
		_messeges.push_back(*shp_mess);
	}
	
}

void Chat::showMenuAddMessege()
{
	std::cout << "¬ыберите режим получател€ : 1 - одному , 2 - всем (All) \n";
}

