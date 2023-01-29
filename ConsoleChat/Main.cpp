#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <iostream>

int main() {
	Chat *chat = new Chat();
	std::cout << "create---------------" << std::endl;
	chat->createNewUser("Irina", "Irina", "12345");
	chat->createNewUser("Roman", "Roman", "67890");
	chat->createNewUser("Irina", "Irina", "23456");
	chat->createNewUser("Elena", "Elena", "35467");
	std::cout << "show------------" << std::endl;
	chat->showActive();
	chat->showAll();
	
	chat->login("Irina", "23456");
	std::cout << "show1-------" << std::endl;
	chat->showActive();

	chat->login("Irina", "12345");
	std::cout << "show2-------" << std::endl;
	chat->showActive();

	delete chat;
	return 0;
}