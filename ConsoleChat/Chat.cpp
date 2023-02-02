#include "Chat.h"
#include <iostream>


Chat::Chat()
{
	_activeUser = nullptr;
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
	if (user != nullptr)
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
	showAllUserMesseges(_activeUser);
	return true;
}


void Chat::write(std::string text, std::shared_ptr<User> recipient)
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	
	std::shared_ptr <Message> shp_mess(new Message(text, getActiveUser()->getName(),
		                                           recipient->getName(), str));
	_messages.push_back(shp_mess);		
}

void Chat::writeToAll(std::string text)
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);	
	
	for (auto& recipient : _users)
	{
		if (recipient->getLogin() != getActiveUser()->getLogin())
		{
			std::shared_ptr <Message> shp_mess(new Message(text, getActiveUser()->getName(),
				                                         recipient->getName(), str));
			_messages.push_back(shp_mess);
		}
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
	std::cout << "Choose recipient mode : 1 - to One , 2 - to All, 3 - Exit \n";
}

std::shared_ptr<User> Chat::getUser(std::string login)
{
	for (auto& user : _users)
		if (user->getLogin() == login)				
			return user;    
		
		return std::make_shared <User>();
}

void Chat::showAllUserMesseges(std::shared_ptr<User> shpu)
{
	std::cout << shpu->getName() << ", your all messages are : " << std::endl << std::endl;
	
	for (auto& message : _messages)
	{
		if (shpu->getLogin() != "\0" && (shpu->getLogin() == message->getSender() ||
			 shpu->getLogin() == message->getRecipient()))
			std::cout << *message;
		else std::cout << "Bad recipient, choose right recipient!\n";
		
	}
}

std::ostream& operator<< (std::ostream& os, Chat& ch)
{
	int count(0);
	for (auto& user : ch._users)
	{		
		os << std::setw(3) << " < " << *user << " > ";
		count++;
		if (!(count % 6))
			os << std::endl;
	}
	return os;
}

