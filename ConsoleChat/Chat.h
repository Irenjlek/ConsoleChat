#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
#include <memory>
class Chat
{
	std::vector <User> _users;
	std::vector <Message> _messeges;
    std::shared_ptr <User> _activeUser;
public:
	Chat();
	void setActiveUser(const std::shared_ptr<User> &);
	bool login(std::string login, std::string password, std::string name);
	void write(std::string text, std::shared_ptr<User> &);
	void writeAll(std::string text);
	std::shared_ptr <User> getActiveUser(const std::vector<User> &);
	std::shared_ptr <User> getUser(const std::vector<User> &);
	void showMenuAddUser();
	void showMenuAddMessege();
};

