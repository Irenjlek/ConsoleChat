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
	for (User* user: _users)
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
