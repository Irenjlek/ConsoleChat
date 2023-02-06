#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "User.h"
#include "Message.h"
#include <iomanip>
#include <typeinfo>

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
	
	std::vector<std::shared_ptr <User>> getVusers() const { return _users; }
	std::vector<std::shared_ptr <Message>> getVmessages() const { return _messages; }
		
	
	template <typename T>
	bool isontheList(std::vector<T>, std::string Element, std::string fromElement);
};


template <typename T>
bool Chat::isontheList(std::vector<T> vecshptr, std::string Element, std::string fromElement)
{

	if (typeid(T).name() == typeid(std::shared_ptr<User>).name())
	{
		if (Element == "name")
		{
			for (auto& tempname : getVusers())
			{
				if (tempname->getName() == fromElement)
					return true;
			}
			std::cout << "not : \"" << fromElement << "\" in the list \n";
			return false;

		}
		else
		{
			std::cout << "bad element, try again!\n";
			return false;
		}

		if (Element == "login")
		{
			for (auto& tempname : getVusers())
			{
				if (tempname->getLogin() == fromElement)
					return true;
			}
			std::cout << "not : \"" << fromElement << "\" in the list \n";
			return false;

		}
		else
		{
			std::cout << "bad element, try again!\n";
			return false;
		}
	}

	//else	
	if (typeid(T).name() == typeid(std::shared_ptr<Message>).name())
	{
		if (Element == "text")
		{
			for (auto& tempelem : getVmessages())
			{
				if (tempelem->getText() == fromElement)
					return true;
			}
			std::cout << "not : \" " << fromElement << "\" in the list \n";
				return false;

		}
		else
		{
			std::cout << "bad element, try again!\n";
			return false;
		}

		std::cout << "Nothing foud \n";

		return false;

	}
	//else return false;
}
 
 
