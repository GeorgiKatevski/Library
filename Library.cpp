// Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Book.h"
#include "Vector.h"
#include "User.h"
#include "System.h"
#include <direct.h>
#include <conio.h>
using namespace std;
#pragma warning(disable:4996)

/*
void test()
{
	//------------------------------------------------------------------------
	std::string words[15];
	for (size_t i = 0; i < 12; i++)
	{
		words[i] = "kukuu";
	}
	Book book("Kalmari", "Georgi Katevski", "Action","isbn1", 5.5, 1999, "kalmari e suzdadena prez maichino vreme",words);
	Book book2("Kalmari2", "Georgi Katevski", "Action", "isbn2", 5.5, 1999, "kalmari e suzdadena prez maichino vreme",words);
	Book book3("Kalmari3", "Georgi Katevski", "Action", "isbn3", 5.5, 1999, "kalmari e suzdadena prez maichino vreme", words);
	Book book4("Kalmar4", "Georgi Katevski", "Action", "isbn4", 5.5, 1999, "kalmari e suzdadena prez maichino vreme", words);
	Book book5("Kalmari5", "Georgi Katevski", "Action", "isbn5", 5.5, 1999, "kalmari e suzdadena prez maichino vreme", words);
	Book book6("Kalmari64", "Georgi Katevski", "Action", "isbn6", 5.5, 1999, "kalmari e suzdadena prez maichino vreme", words);
	Book book7("Kalmari55", "Georgi Katevski", "Action", "isbn7", 5.5, 1999, "kalmari e suzdadena prez maichino vreme", words);
	D_array<Book> books;
	books.pushBack(book);
	books.pushBack(book2);
	books.pushBack(book3);
	books.pushBack(book4);
	books.pushBack(book5);
	books.pushBack(book6);
	books.pushBack(book7);


	User user("Georgi", "Parola", 0);
	User user2("Ivan", "Parola", 0);

	User user3("shishkan", "Parola", 0);
	User user4("peshu", "Parola", 0);

	User user5("pencho", "Parola", 0);
	User user6("goshu", "Parola", 0);

	User user7("chichaka", "Parola", 0);
	User user8("Klr", "Parola", 0);
	D_array<User> users;
	users.pushBack(user);
	users.pushBack(user2);
	users.pushBack(user3);
	users.pushBack(user4);
	users.pushBack(user5);
	users.pushBack(user6);
	users.pushBack(user7);
	users.pushBack(user8);

	System system;
	system.setBooks(books);
	system.setUsers(users);
	}
*/

void help()
{
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "open <file>        opens <file>" << std::endl;
	std::cout << "close              closes currently opened file" << std::endl;
	std::cout << "save               saves the currently open file" << std::endl;
	std::cout << "saveas <file>      saves the currently open file in <file>" << std::endl;
	std::cout << "help               prints this information" << std::endl;
	std::cout << "exit	           exists the program" << std::endl;

}

void test()
{
	std::cout << "write open and make sure the files are good to use " << std::endl;
	std::string command;
	while (command != "exit")
	{
		getline(std::cin, command);
		if (command == "help")
		{
			help();
		}
		if (command == "open")
		{

			std::cout << "Choose between 3 ways to start the project,but first check if the files are good!!" << std::endl;
			std::cout << "1-With directory but you have, but only for Windows" << std::endl;
			std::cout << "2-With a file in the project's directory" << std::endl;
			std::cout << "3-Without files" << std::endl;
			System system;
			int number;
			cin >> number;
			if (number == 1)
			{
				//--za WINDOWS!!!
				System tempSystem("C:\\Users\\Georgi\\Desktop\\Filebe.txt");
				//ZA WINDOWS
				system = tempSystem;
				std::cout << "Now you have to write login" << std::endl;
			}
			else if (number == 2)
			{

				System tempSystem("Filebe.txt");

				system = tempSystem;
				std::cout << "Now you have to write login" << std::endl;
			}
			else if (number == 3)
			{
				std::string words[15];
				for (size_t i = 0; i < 15; i++)
				{
					words[i] = "word";
				}
				Book book("Aalmari", "Yeorgi Katevski", "Action", "isbn1", 5.5, 1991, "kalmari e suzdadena prez minalo vreme", words);
				Book book2("Galmari2", "Meorgi Katevski", "Action", "isbn2", 5.5, 1992, "kalmari e suzdadena prez minalo vreme", words);
				Book book3("Talmari3", "Keorgi Katevski", "Action", "isbn3", 5.5, 1993, "kalmari e suzdadena prez minalo vreme", words);
				Book book4("Walmar4", "Aeorgi Katevski", "Action", "isbn4", 5.5, 1994, "kalmari e suzdadena prez minalo vreme", words);
				Book book5("Salmari5", "Ueorgi Katevski", "Action", "isbn5", 5.5, 1999, "kalmari e suzdadena prez minalo vreme", words);
				Book book6("Oalmari64", "Jeorgi Katevski", "Action", "isbn6", 5.5, 1998, "kalmari e suzdadena prez minalo vreme", words);
				Book book7("Balmari55", "Peorgi Katevski", "Action", "isbn7", 5.5, 1800, "kalmari e suzdadena prez minalo vreme", words);
				D_array<Book> books;
				books.pushBack(book);
				books.pushBack(book2);
				books.pushBack(book3);
				books.pushBack(book4);
				books.pushBack(book5);
				books.pushBack(book6);
				books.pushBack(book7);


				User user("Georgi", "Parola", 0);
				User user2("Ivan", "Parola", 0);

				User user3("shishkan", "Parola", 0);
				User user4("peshu", "Parola", 0);

				User user5("pencho", "Parola", 0);
				User user6("goshu", "Parola", 0);

				User user7("chichaka", "Parola", 0);
				User user8("Klr", "Parola", 0);
				D_array<User> users;
				users.pushBack(user);
				users.pushBack(user2);
				users.pushBack(user3);
				users.pushBack(user4);
				users.pushBack(user5);
				users.pushBack(user6);
				users.pushBack(user7);
				users.pushBack(user8);

				System tempSystem;
				tempSystem.setBooks(books);
				tempSystem.setUsers(users);
				system = tempSystem;
				std::cout << "Now you have to write 'login'." << std::endl;
			}

			std::string validCommand;
			getline(::cin, validCommand);
			while (validCommand != "quit")
			{
				getline(::cin, validCommand);
				if (validCommand == "quit")
				{
					break;
				}

				if (validCommand == "login")
				{
					std::string name;

					int checkAdmin;

					cout << "Welcome to my library" << endl;
					cout << "Login" << endl;
					cout << "Name: ";
					cin >> name;
					cout << "Password: ";
					string password = "";
					//----------------------------------
					//will cause problem on linux
					//----------------------------------
					//--http://www.cplusplus.com/forum/general/3570/
					char letter;
					letter = _getch();
					while (letter != 13) {//character 13 is enter
						password.push_back(letter);
						cout << '*';
						letter = _getch();
					}
					//--http://www.cplusplus.com/forum/general/3570/
					//----------------------------------
					//will cause problem on linux
					//----------------------------------
					//--------------
					/*
				std::string pass;
				getline(std::cin,pass)
					*/
					//========
					std::cout << std::endl;
					cout << "Choose 0 for client and 1 for Admin" << endl;
					cin >> checkAdmin;

					system.login(name, password, checkAdmin);

				}

				if (validCommand == "logout")
				{
					system.logout();

				}

				if (validCommand == "books all")
				{
					system.booksAll();
				}
				if (validCommand == "books find")
				{
					std::string option;
					std::string title;
					getline(std::cin, option);
					getline(std::cin, title);
					Book book = system.bookFind(option, title);
					book.printBook();


				}
				if (validCommand == "books sort")
				{
					std::string str;
					getline(std::cin, str);
					
					cout << "Choose 1 or 0 for ascending sort or descending sort" << std::endl;
			
					system.booksSort(str, 0);

				}
				if (validCommand == "books info")
				{
					std::string ISBN;
					cin >> ISBN;
					system.booksInfo(ISBN);

				}


				if (validCommand == "close")
				{
					std::cout << "close" << std::endl;
				}

				if (validCommand == "save")
				{
					system.save();
				}
				if (validCommand == "saveas")
				{
					std::string fileToSafe;
					getline(std::cin, fileToSafe);
					const char* file = fileToSafe.c_str();
					system.saveas(file);
				}
				if (validCommand == "users add")
				{
					std::string name;
					getline(std::cin, name);
					std::string password;
					getline(std::cin, password);
					User user;
					user.setName(name);
					user.setPassword(password);
					user.setAdmin(0);
					system.addUser(user);
				}
				if (validCommand == "users remove")
				{
					std::string name;
					getline(std::cin, name);
					system.removeUser(name);
				}
			}

		}

	}
}

int main()
{
	test();

	/*
	std::string words[15];
	for (size_t i = 0; i < 15; i++)
	{
		words[i] = "word";
	}
	Book book("aalmari", "Georgi Katevski", "Action", "isbn1", 5.5, 1991, "kalmari e suzdadena prez minalo vreme", words);
	Book book2("walmari2", "Georgi Katevski", "Action", "isbn2", 5.5, 1992, "kalmari e suzdadena prez minalo vreme", words);
	Book book3("walmari3", "Georgi Katevski", "Action", "isbn3", 5.5, 1993, "kalmari e suzdadena prez minalo vreme", words);
	Book book4("zalmar4", "Georgi Katevski", "Action", "isbn4", 5.5, 1994, "kalmari e suzdadena prez minalo vreme", words);
	Book book5("malmari5", "Georgi Katevski", "Action", "isbn5", 5.5, 1999, "kalmari e suzdadena prez minalo vreme", words);
	Book book6("yalmari64", "Georgi Katevski", "Action", "isbn6", 5.5, 1998, "kalmari e suzdadena prez minalo vreme", words);
	Book book7("talmari55", "Georgi Katevski", "Action", "isbn7", 5.5, 1800, "kalmari e suzdadena prez minalo vreme", words);
	D_array<Book> books;
	books.pushBack(book);
	books.pushBack(book2);
	books.pushBack(book3);
	books.pushBack(book4);
	books.pushBack(book5);
	books.pushBack(book6);
	books.pushBack(book7);


	User user("Georgi", "Parola", 0);
	User user2("Ivan", "Parola", 0);

	User user3("shishkan", "Parola", 0);
	User user4("peshu", "Parola", 0);

	User user5("pencho", "Parola", 0);
	User user6("goshu", "Parola", 0);

	User user7("chichaka", "Parola", 0);
	User user8("Klr", "Parola", 0);
	D_array<User> users;
	users.pushBack(user);
	users.pushBack(user2);
	users.pushBack(user3);
	users.pushBack(user4);
	users.pushBack(user5);
	users.pushBack(user6);
	users.pushBack(user7);
	users.pushBack(user8);

	System tempSystem;
	tempSystem.setBooks(books);
	tempSystem.setUsers(users);
	tempSystem.setFlag(true);
	tempSystem.setAdmin(true);
	tempSystem.booksAll();
	tempSystem.booksSort("title", 1);
	tempSystem.booksAll();
	
	
	
	
	
	
	
	
	*/
	
	
	
	
	
	
	
	
	


	





	//System s("C:\\Users\\Georgi\\Desktop\\SaveToFile.txt");
	//s.change_directory("C:\\Users\\Georgi\\Desktop\\SaveToFile.txt");
	
	/*

	std::string words[15];
	for (size_t i = 0; i < 15; i++)
	{
		words[i] = "kukuu";
	}
//Book book("zlmari", "Georgi Katev", "Action", "isbn1", 5.5, 1992, "kalmari e suzdadena prez maichino vreme", words);
Book book2("walmari2", "Aeorgi Katev", "Action", "isbn2", 5.5, 1994, "kalmari e suzdadena prez maichino vreme", words);
Book book3("salmari3", "Beorgi Katevs", "Action", "isbn3", 5.5, 2000, "kalmari e suzdadena prez maichino vreme", words);
Book book4("dalmar4", "Deorgi Katevs", "Action", "isbn4", 5.5, 1996, "kalmari e suzdadena prez maichino vreme", words);
Book book5("calmari5", "Deorgi Katevs", "Action", "isbn5", 5.5, 1997, "kalmari e suzdadena prez maichino vreme", words);
Book book6("yalmari64", "Meorgi Katevs", "Action", "isbn6", 5.5, 1997, "kalmari e suzdadena prez maichino vreme", words);
Book book7("aalmari55", "Neorgi Katev", "Action", "isbn7", 5.5, 1998, "kalmari e suzdadena prez maichino vreme", words);
D_array<Book> books;
//books.pushBack(book);
books.pushBack(book2);
books.pushBack(book3);
books.pushBack(book4);
books.pushBack(book5);
books.pushBack(book6);
books.pushBack(book7);
*/

//book.saveBook("File1.txt");
/*
book2.saveBook("File2.txt");
Book book;
book.readBook("File2.txt");
book.printBook();
*/


//system.setBooks(books);
//system.saveBooks("File3.txt");
/*
	std::ifstream file("SaveToFile.txt");
System system;
system.readBooks(file);
system.setAdmin(1);
system.setFlag(1);
system.booksAll();
*/
//system.saveBooks("savaFile.txt");
	/*
std::ifstream file2("SaveToFile.txt");
System system2;
system2.readBooks(file2);
system2.setAdmin(1);
system2.setFlag(1);
system2.booksAll();

User user("Georgi", "Parola", 0);
User user2("Ivan", "Parola", 0);

User user3("shishkan", "Parola", 0);
User user4("peshu", "Parola", 0);

User user5("pencho", "Parola", 0);
User user6("goshu", "Parola", 0);

User user7("chichaka", "Parola", 0);
User user8("Klr", "Parola", 0);
D_array<User> users;
users.pushBack(user);
users.pushBack(user2);
users.pushBack(user3);
users.pushBack(user4);
users.pushBack(user5);
users.pushBack(user6);
users.pushBack(user7);
users.pushBack(user8);

//system2.setUsers(users);
//system2.saveUsers("Users.txt");
std::ifstream file4("Users.txt");
system2.readUsers(file4);
std::cout << system2.getUsers();
*/
	/*
std::ifstream file5("SaveToFile.txt");
std::ifstream file6("Users.txt");
System s3(file5, file6);
s3.setFlag(1);
s3.booksAll();
cout<<s3.getUsers();
*/

//system2.saveBooks("SaveToFile.txt");




//system.quickSort("year",0,books.getSize()-1,1);
/*
system.booksSort("year", 1);
system.setFlag(1);
system.booksAll();

*/




	/*
	std::string words[15];
	for (int i = 0; i < 15; i++)
	{
		words[i] = "kalmar";
	}

	for (int i = 0; i < 15; i++)
	{
		cout << words[i];
	}
	*/

	/*
	Book book("Kalmari", "Georgi Katevski", "Action", 5.5, 1999, "kalmari e suzdadena prez maichino vreme");
	Book book2("Kalmari2", "Georgi Katevski", "Action", 5.5, 1998, "kalmari e suzdadena prez maichino vreme");
	Book book3("Kalmari3", "Georgi Katevski", "Action", 5.5, 123, "kalmari e suzdadena prez maichino vreme");
	Book book4("Kalmar4", "Georgi Katevski", "Action", 5.5, 1933, "kalmari e suzdadena prez maichino vreme");
	Book book5("Kalmari5", "Georgi Katevski", "Action", 5.5, 1955, "kalmari e suzdadena prez maichino vreme");
	Book book6("Kalmari64", "Georgi Katevski", "Action", 5.5, 1966, "kalmari e suzdadena prez maichino vreme");
	Book book7("Kalmari55", "Georgi Katevski", "Action", 5.5, 1911, "kalmari e suzdadena prez maichino vreme");
	D_array<Book> books;
	books.pushBack(book);
	books.pushBack(book2);
	books.pushBack(book3);
	books.pushBack(book4);
	books.pushBack(book5);
	books.pushBack(book6);
	books.pushBack(book7);
	System system;
	system.setBooks(books);
	system.setFlag(true);
	system.quickSort(0, books.getSize()-1);
	//system.booksRemove("Kalmari");
	system.booksAll();


	*/

		


		



}

