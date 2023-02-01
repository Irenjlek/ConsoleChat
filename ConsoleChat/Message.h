#pragma once

#include <string>
#include <iomanip>

class Message
{
private:
	std::string _text;
	std::string _sender;
	std::string _recipient;
	time_t _time;

public:
	Message(std::string text, std::string sender, std::string recipient, time_t time);

	std::string getText();
	std::string getSender();
	std::string getRecipient();
	time_t getTime();
	friend std::ostream& operator<< (std::ostream& stream, Message& message);
};

