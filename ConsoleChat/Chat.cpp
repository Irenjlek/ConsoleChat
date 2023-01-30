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
	if (isLoginExist(login)) {
		std::cout << "User with login " << login << " is already exists." << std::endl;
		return false;
	}		
	std::shared_ptr <User> newUser = std::shared_ptr <User>(new User(name, login, password));
	_users.push_back(newUser);
	setActiveUser(newUser);

	return true;
}

void Chat::setActiveUser(const std::shared_ptr<User>& user)
{
	std::cout << "Hello, " << user->getName() << "! Nice to see you!" << std::endl;
	_activeUser = user;
}

bool Chat::login(std::string login, std::string password)
{
	bool found = isLoginExist(login);
	if (!found) {
		std::cout << "User with login " << login << " does not exist." << std::endl;
		return false;
	}

	for (std::shared_ptr <User> user : _users)
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
	
	std::shared_ptr <Message> shp_mess(new Message(text, getActiveUser().get()->getName(),
		recipient.get()->getName(), time_mess));
	_messages.push_back(shp_mess);	
	
}

void Chat::writeToAll(std::string text)
{
	time_t time_mess = time(&time_mess);
	
	
	for (auto ricipient : _users)
	{
		std::shared_ptr <Message> shp_mess(new Message(text, getActiveUser().get()->getName(),
			(*ricipient).getName(), time_mess));
		_messages.push_back(shp_mess);
	}
	
}

bool Chat::isLoginExist(const std::string& login)
{
	for (std::shared_ptr <User> user : _users)
	{
		if (user->getLogin() == login) 			
			return true;
	}
	return false;
}

std::shared_ptr<User> Chat::getActiveUser()
{
	return _activeUser;
}

void Chat::showMenuAddMessege()
{
	std::cout << "¬ыберите режим получател€ : 1 - одному , 2 - всем (All) \n";
}

