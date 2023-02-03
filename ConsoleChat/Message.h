#pragma once

#include <string>
#include <iomanip>



class Message
{
private:
	std::string _text;
	std::string _sender;
	std::string _recipient;
	std::string _time;

public:
	Message(std::string text, std::string sender, std::string recipient);

	std::string getText();
	std::string getSender();
	std::string getRecipient();
	std::string getTime();
	friend std::ostream& operator<< (std::ostream& stream, Message& message);
};

