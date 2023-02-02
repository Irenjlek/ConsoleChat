#include "Message.h"
#include <ostream>

Message::Message(std::string text, std::string sender, std::string recipient, std::string time) :
	_text(text),
	_sender(sender),
	_recipient(recipient),
	_time(time)
{
}

std::string Message::getText()
{
	return _text;
}

std::string Message::getSender()
{
	return _sender;
}

std::string Message::getRecipient()
{	
	return _recipient;
}

std::string Message::getTime()
{	
	return _time;
}

std::ostream& operator<<(std::ostream& stream, Message& message)
{
	
	stream << message.getSender() << std::setw(35) << message.getTime() <<std::setw(30) << "--->" << std::setw(30)
		<< message.getRecipient() << std::endl << std::endl << std::setw(20) << "\" " << message.getText() << " \""
		<< std::endl << std::endl;
	return stream;
}
