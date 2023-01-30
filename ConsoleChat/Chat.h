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
	std::vector<User*> _users;
	std::vector <Message> _messeges;
	std::shared_ptr <User> _activeUser;


public:

	Chat();
	~Chat();

	bool createNewUser(const std::string& name, const std::string& login, const std::string& password);
	void setActiveUser(const std::shared_ptr<User>& user);
	bool login(std::string login, std::string password);
	void write(std::string text, std::shared_ptr<User>&);
	void writeToAll(std::string text);
	std::shared_ptr <User> getActiveUser(const std::vector<User*>&);
	std::shared_ptr <User> getUser(const std::vector<User>&);
	void showMenuAddUser();
	void showMenuAddMessege();

	//temp for debug
	void showActive() {
		std::cout << "showactive" << std::endl;
		std::cout << _activeUser->getName() << std::endl;
	}

	void showAll() {
		std::cout << "showall" << std::endl;
		for (User* user : _users)
		{
			std::cout << user->getName() << " " << std::endl;
		}
	}
};


