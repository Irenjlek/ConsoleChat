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
	for (User user: _users)
	{
		if (user.getLogin() == login) {
			std::cout << "User with login " << login << " is already exists." << std::endl;
			return false;
		}
	}
	User newUser(name, login, password);
	_users.push_back(newUser);
	return true;
}
