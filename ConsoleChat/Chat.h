#pragma once
#include <vector>
#include <string>
#include "User.h"

class Chat
{
private:
	

public:

	std::vector<User*> _users;
	Chat();
	~Chat();

	bool createNewUser(const std::string& name, const std::string& login, const std::string& password);
};

