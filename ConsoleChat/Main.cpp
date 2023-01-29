#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <iostream>

bool main() {
	Chat *chat = new Chat();

	chat->createNewUser("Irina", "Irina", "12345");
	chat->createNewUser("Roman", "Roman", "67890");
	chat->createNewUser("Irina", "Irina", "23456");
	chat->createNewUser("Elena", "Elena", "35467");

	for (User* user : chat->_users) {
		std::cout << user->getLogin() << " ";
	}

	delete chat;
	return 0;
}