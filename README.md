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

Для реализации данного функционала используются три класса:
- Message
- User 
- Chat

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
 
