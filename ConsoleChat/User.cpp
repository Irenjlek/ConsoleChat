#include "User.h"


User::User(std::string name, std::string login, std::string password): 
	        _name (name), _login(login), _password(password) {}

std::ostream& operator<< (std::ostream& os, User& us)
{
	os << us._name;
	return os;
}