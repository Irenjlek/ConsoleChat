#include "Message.h"

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

std::ostream& operator<<(std::ostream&, Message&)
{
	// TODO: вставьте здесь оператор return
}
