#include "System.h"

size_t System::getUsers() const
{
	return users.getSize();
}

void System::login(const std::string& name,const std::string& password,bool isAdmin)
{
	if (isLogged == false)
	{

		bool isValid = false;
		for (size_t i = 0; i < users.getSize(); i++)
		{
			if (users[i].getName() == name && users[i].getPassword() == password && users[i].getisAdmin() == isAdmin)
			{
				isLogged = true;
				isValid = true;
				if (users[i].getisAdmin() == true)
				{
					isAdmin = true;
				}
				std::cout << "Welcome " << name << "!" << std::endl;
				break;
			}

		}
		if (isValid == false)
		{
			std::cout << "Invalid account!" << std::endl;
		}
	}
	else
	{
		std::cout << "You are already logged in!" << std::endl;
	}

}

void System::logout()
{
	setFlag(false);
	isAdmin = false;
}

void System::booksAll()
{
	if (isLogged == true)
	{
		for (size_t i = 0; i < books.getSize(); i++)
		{
			
			std::cout << books[i].getTitle() << " " << books[i].getAuthor() << " "
				<< books[i].getISBN() << " " << books[i].getGenre() <<std::endl;
			
			
			//books[i].printBook();
		}
	
	}
	else
	{
		std::cout << "You have to login first" << std::endl;

	}
}

void System::booksInfo(const std::string& ISBN) 
{
	if (isLogged == true)
	{
		//ili size_t no isbn po princip ima i bukvi
		bool isValidBook = false;
		for (size_t i = 0; i < books.getSize(); i++)
		{
			if (ISBN == books[i].getISBN())
			{
				isValidBook = true;
				books[i].printBook();
				break;
			}

		}
		if (isValidBook == false)
		{
			std::cout << "Invalid ISBN" << std::endl;
		}
	}
	else
	{
		std::cout << "You have to log in first" << std::endl;
	}

}



Book& System::bookFind(const std::string& option, const std::string& name)
{
	if (isLogged == true)
	{
		if (option == "title")
		{
			bool isValid = false;
			for (size_t i = 0; i < books.getSize(); i++)
			{
				if (books[i].getTitle() == name)
				{
					isValid = true;
					return books[i];

				}
			}
			if (isValid == false)
			{
				std::cout << "Invalid Title" << std::endl;
			}
		}
		if (option == "author")
		{
			bool isValid = false;
			for (size_t i = 0; i < books.getSize(); i++)
			{
				if (books[i].getAuthor() == name)
				{
					isValid = true;
					return books[i];

				}
			}
			if (isValid == false)
			{
				std::cout << "Invalid Author" << std::endl;
			}

		}
		if (option == "author")
		{
			bool isValid = false;
			for (size_t i = 0; i < books.getSize(); i++)
			{
				if (books[i].getAuthor() == name)
				{
					isValid = true;
					return books[i];

				}
			}
			if (isValid == false)
			{
				std::cout << "Invalid Author" << std::endl;
			}

		}
		
	}
	else
	{
		std::cout << "You have to log in first" << std::endl;
	}

}



void System::pushUser(std::string& name, std::string& password)
{
	User user;
	user.setName(name);
	user.setPassword(password);
	addUser(user);

}

void System::addUser(const User& user)
{
	if (isAdmin == true && isLogged==true)
	{
		users.pushBack(user);
	}
	else
	{
		std::cout << "You are not admin or you are not logged in" << std::endl;
	}
}

void System::removeUser(const std::string& name)
{
	if (isAdmin == true && isLogged == true)
	{
	int count = 0;
	for (size_t i = 0; i < users.getSize(); i++)
	{
		if (users[i].getName() == name)
		{
			count = i;
			break;
		}
	}

	users.remove(count);
	}
	else
	{
		std::cout << "You are not admin or you are not logged in" << std::endl;
	}
}

void System::booksAdd(const Book& book)
{
	if (isAdmin == true && isLogged == true)
	{
		books.pushBack(book);
	}
	else
	{
		std::cout << "You are not admin or you are not logged in" << std::endl;
	}
}
void System::readUsers(std::ifstream& file)
{
	
	while (!file.eof())
	{
		User user;
		user.readUser(file);
		users.pushBack(user);

	}

}
void System::saveUsers(const char* file)
{
	std::ofstream out(file);
	if (out.is_open())
	{
		for (size_t i = 0; i < books.getSize(); i++)
		{
			users[i].saveUser(file);
		}
	}



}

void System::booksRemove(const std::string& name)
{

	if (isAdmin == true && isLogged == true)
	{
		int count = 0;
		for (size_t i = 0; i < books.getSize(); i++)
		{
			if (books[i].getTitle() == name)
			{
				count = i;
				break;
			}
		}

		books.remove(count);
	}
	else
	{
		std::cout << "You are not admin or you are not logged in" << std::endl;
	}

}


System::System()
{}

System::System(std::ifstream& booksFile, std::ifstream& usersFile)
{
	User user;
	user.setName("admin");
	user.setPassword("i<3c++");
	user.setAdmin(1);
	users.pushBack(user);
	readBooks(booksFile);
	readUsers(usersFile);
}

System::System(const std::string& file)
{
	
	User user;
	user.setName("admin");
	user.setPassword("i<3c++");
	user.setAdmin(1);
	usersFile = "Users.txt";
	users.pushBack(user);
	change_directory(file);

}

System::System(const char* fileName)
{
	User user;
	user.setName("admin");
	user.setPassword("i<3c++");
	user.setAdmin(1);
	this->file = fileName;
	std::ifstream fileUsers("Users.txt");
	usersFile = "User.txt";
	readUsers(fileUsers);
	std::ifstream file(fileName);
	readBooks(file);
}

void System::setBooks(D_array<Book>& _books)
{

	for (size_t i = 0; i < _books.getSize(); i++)
	{
		this->books.pushBack(_books[i]);
	}
}

void System::setUsers(D_array<User>& _users)
{
	for (size_t i = 0; i < _users.getSize(); i++)
	{
		this->users.pushBack(_users[i]);
	}
	
}
void System::setFlag(bool isLogged)
{
	this->isLogged = isLogged;
}
void System::setAdmin(bool isLogged)
{
	isAdmin = true;
}
D_array<Book> System::getBooks() const
{
	 return books;
}
void System::quickSort(const std::string& option,int first, int last,bool isAsc)
{
	
	int p = 0, j, i;
	Book temp;
	if (first < last)
	{
		p = first;
		i = first;
		j = last;

		while (i < j)
		{
			if (isAsc)
			{
				if (option == "year")
				{
					while (books[i].getYear() >= books[p].getYear() && i < last)
					{
						i++;
						while (books[j].getYear() < books[p].getYear())
						{
							j--;
						}

						if (i < j)
						{
							temp = books[i];
							books[i] = books[j];
							books[j] = temp;
						}
					}
				}
				else{

					while (books[i].getRating() >= books[p].getRating() && i < last)
					{
						i++;
						while (books[j].getRating() < books[p].getRating())
						{
							j--;
						}

						if (i < j)
						{
							temp = books[i];
							books[i] = books[j];
							books[j] = temp;
						}
					}

				}
			}
			else
			{
				if (option == "year")
				{
					while (books[i].getYear() <= books[p].getYear() && i < last)
					{
						i++;
						while (books[j].getYear() > books[p].getYear())
						{
							j--;
						}

						if (i < j)
						{
							temp = books[i];
							books[i] = books[j];
							books[j] = temp;
						}
					}
				}
				else {

					while (books[i].getRating() <= books[p].getRating() && i < last)
					{
						i++;
						while (books[j].getRating() > books[p].getRating())
						{
							j--;
						}

						if (i < j)
						{
							temp = books[i];
							books[i] = books[j];
							books[j] = temp;
						}
					}

				}
			}
		}
		temp = books[p];
		books[p] = books[j];
		books[j] = temp;


		quickSort(option,first, j - 1,isAsc);
		quickSort(option,j + 1, last,isAsc);
	}
	
}


void System::booksSort(const std::string& option,bool isAsc)
{
	if (option == "year" || option == "rating")
	{
		quickSort(option, 0, books.getSize()-1, isAsc);
	}
	else
	{
		quickSort2(option, 0, books.getSize()-1, isAsc);
	}

}
void System::saveBooks(const char* file)
{
	std::ofstream out(file);
	if (out.is_open())
	{
		for (size_t i = 0; i < books.getSize(); i++)
		{
			books[i].saveBook(file);
		}
	}

}

void System::readBooks( std::ifstream& in)
{
	
	while (!in.eof())
	{
		Book book;
		book.readBook(in);
		books.pushBack(book);

	}
}



const char* System::getInputFile() const
{

	return  file;

}

void System::save()
{
	if (usersFile != nullptr)
	{
		saveUsers(usersFile);
		saveBooks(getInputFile());
	}
	else
	{
		std::cout << "There is no file to be saved"<<std::endl;
	}
}

void System::saveas(const char* file)
{
	saveBooks(file);
}

void System::change_directory(const std::string& str)
{
	
	std::string str2 = str;

	int count = 0;
	for (size_t i = 0; i < str2.length(); i++)
	{

		if (str2[i] == '\\')
		{
			count++;

		}

	}
	std::cout << count <<std::endl;
	int count1 = 0;

	std::string str3 = "";
	std::string str4 = "";
	for (size_t i = 0; i < str2.length(); i++)
	{
		if (count == count1)
		{
			str3 += str2[i];
		}
		if (str2[i] == '\\')
		{
			count1++;
		}
		if (count != count1)
		{
			str4 += str2[i];
		}
	}

	std::cout << str3 << " " << str4;
	const char* directory = str4.c_str();
	//--https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/reference/chdir-wchdir?view=vs-2019
	const char* file = str3.c_str();
	if (_chdir(directory))
	{
		switch (errno)
		{
		case ENOENT:
			printf("Unable to locate the directory: %s\n", directory);
			break;
		case EINVAL:
			printf("Invalid buffer.\n");
			break;
		default:
			printf("Unknown error.\n");
		}
	}
	else {
	

		System system(file);
		//system.readBooks(file1);
		//system.setAdmin(1);
		//system.setFlag(1);
		//system.booksAll();
	}
	//--https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/reference/chdir-wchdir?view=vs-2019
}
