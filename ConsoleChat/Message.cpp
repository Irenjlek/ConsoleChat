#include "Message.h"
#include <ostream>

Message::Message(std::string text, std::string sender, std::string recipient, time_t time) :
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

time_t Message::getTime()
{	
	return _time;
}

std::ostream& operator<<(std::ostream& stream, Message& message)
{
	
	stream << message.getSender() << std::setw(30) << "--->" << std::setw(30)
		<< message.getRecipient() << std::endl << std::endl << std::setw(15) << "\" " << message.getText() << " \""
		<< std::endl << std::endl;
	return stream;
}
