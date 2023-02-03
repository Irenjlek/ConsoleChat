#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "User.h"
#include "Message.h"
#include <iomanip>

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
	void write(std::string text, std::shared_ptr<User>);
	void writeToAll(std::string text);
	bool isLoginExist(const std::string& login);
	std::shared_ptr <User> getActiveUser();
	std::shared_ptr <User> getUser(std::string login);
	void showMenuAddMessege();
	void showAllUserMesseges(std::shared_ptr <User>);
	friend std::ostream& operator<< (std::ostream& os, Chat&);
	void showAllLogin();
	bool isUnicName(std::string name);
	std::string getNameByLogin(std::string login);
	std::string getLoginByName(std::string name);
	bool isontheList(std::string name);

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

	void showAllMessages()
	{
		

		for (auto& shpm : _messages)
		{
			std::cout << shpm->getText();
			std::cout << std::setw(30);
			std::cout << shpm->getSender();
			std::cout << std::setw(40);
			std::cout << shpm->getRecipient();
			std::cout << std::endl;
		}
	}

};


