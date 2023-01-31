#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "User.h"
#include "Message.h"

class Chat
{
private:
	std::vector<std::shared_ptr <User>> _users;
	std::vector<std::shared_ptr <Message>> _messages;
	std::shared_ptr <User> _activeUser;


public:

	Chat();
	~Chat();

	bool createNewUser(const std::string& name, const std::string& login, const std::string& password);
	void setActiveUser(const std::shared_ptr<User>& user);
	bool login(std::string login, std::string password);
	void write(std::string text, std::shared_ptr<User>&);
	void writeToAll(std::string text);
	std::shared_ptr <User> getActiveUser();
	std::shared_ptr <User> getUser(std::string login);
	void showMenuAddUser();
	void showMenuAddMessege();

	//temp for debug
	void showActive() {
		std::cout << "showactive" << std::endl;
		std::cout << _activeUser->getName() << std::endl;
	}

	void showAll() {
		std::cout << "showall" << std::endl;
		for (std::shared_ptr <User> user : _users)
		{
			std::cout << user->getName() << " " << std::endl;
		}
	}
};


