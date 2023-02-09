# ConsoleChat
Homework for skillfactory first module c++

Участники:
- Рогозина Ирина Владимировна
- Кожевников Роман Александрович

Консольная программа ConsoleChat обладает, в частности, следующим функционалом:

- Регистрация пользователей - логин, пароль, имя
- Вход в чат по логину/паролю
- Отправка сообщений конкретному пользователю
- Обмен сообщениями между всеми пользователями чата одновременно

Для реализации данного функционала используются три основных класса:
- Message
- User 
- Chat

и два вспомогательных класса исключений:

- Badlogin
- Badpassword

Описание классов и алгоритм программы содержатся в соответствующих диаграммах к проекту.

Программа предусматривает:
 
 - удобное меню для регистрации и входа, перключения между режимами идентификации пользователя 
   и отправки сообщений.

 - возможность отправки сообщения самому себе, для испльзования в качестве 
   черновика или шаблона. При отправке сообщения всем пользователям, такая возможность отключена.

 - возможность использования идентичных имён. При выборе идентичного имени 
    из списка пользователей, предлагается использовать логин (пароль и логин уникальны).  
 
 - возможность использования шаблонной и нешаблонной функции isontheList() как для поиска имени  
   в списке User, так для поиска любого элемента из любого списков : User, Messages (последнее 
   использутся в программе в режиме теста.
 
Для безопасной работы программа использует,соответствующие режимы ввода и классы исключений. 
 
 Задачи в команде были распределены и выполнены следующим образом:

1) ИРИНА:

все файлы диаграмм 

класс Message 
- объявление и реализация

класс Chat
- объявление и реализация следующих функций:

  bool createNewUser(const std::string& name, const std::string& login, const std::string& password)
  
  void setActiveUser(const std::shared_ptr<User>& user) 
  
  void login(std::string login, std::string password) 
  
  bool isLoginExist(const std::string& login) 
  
  shared_ptr <User> getActiveUser() 
  
  void showActive() - (имя активного пользователя)
  
  void showAll() - (все имена пользователей)

класс Badlogin

- объявление и реализация

класс Badpassword

- объявление и реализация

функция main() :

  - начало общего цикла
  - меню "Would you like login(enter 'L'), register(enter 'R') or quit(enter 'Q')?"  
    полный цикл (строки с 10 по 88) 

2) РОМАН:  

файл README

класс User 
- объявление и реализация

класс Chat
- объявление и реализация следующих функций:

    void write(std::string text, std::shared_ptr<User>) (сообщение одному)
	
	void writeToAll(std::string text)
	
	std::shared_ptr <User> getUser(std::string login)
	
	void showMenuAddMessege() 
	
	void showAllUserMesseges(std::shared_ptr <User>) 
	
	friend std::ostream& operator<< (std::ostream& os, Chat&) (имена всех пользователей)
	
	void showAllLogin() 
	
	bool isUnicName(std::string name) 
	
	std::string getNameByLogin(std::string login) 
	
	std::string getLoginByName(std::string name) 
	
	bool isontheList(std::string name) (имя пользователя в списке)	
	
	void showAllMessages() 	(по пользователю)
	
	std::vector<std::shared_ptr <User>> getVusers() const 
	
	std::vector<std::shared_ptr <Message>> getVmessages() const 
	
	template <typename T>	
	
	bool isontheList(std::vector<T>, std::string Element, std::string fromElement) 
	
        (поиск в элементах классa T) 
        

функция main() :
  
  - меню "Choose recipient mode : 1 - to One , 2 - to All, 3 - Exit \n"  
  
    полный цикл (строки с 90 по 174) 
