#pragma once
#include <ostream>
#include <string>

class User
{
	std::string _name;
	const std::string _login;
	std::string _password;

public:
	User();
	User(std::string name, std::string login, std::string password);	
	std::string& getName() { return _name; }
	const std::string& getLogin() { return _login; }
	std::string& getPassword() { return _password; }
	friend std::ostream& operator<< (std::ostream&, User&);
	//void changename(); // допник

};

