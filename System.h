#pragma once
#include "User.h"
#include "Book.h"
#include "Vector.h"
#include <fstream>
#include <direct.h>
class System
{

private:
	D_array<User> users;
	D_array<Book> books;

	bool isLogged = false;
	bool isAdmin = false;
	const char* file;
	const char* usersFile;
	//reading names from file 
	//and then  adding them to a d_array and working with them 
	//same thing doing with books 
	//but using function to get to a definite directory
public:
	System();

	System(std::ifstream& booksFile, std::ifstream& usersFile);
	System(const std::string& file);

	System(const char* filename);

	//System(const System& other) = delete;
	//System& operator=(const System& other) = delete;

	void setBooks(D_array<Book>& books);
	void setUsers(D_array<User>& users);
	void setFlag(bool isLogged);
	void setAdmin(bool isLogged);
	D_array<Book> getBooks() const;

	size_t getUsers() const;
	void login(const std::string&, const std::string& password,bool isAdmin);
	void logout();
	
	void booksAll();

	void booksInfo(const std::string& ISBN); 
	//ili size_t no isbn po princip ima i bukvi

	void quickSort(const std::string& option,int first, int last,bool isAsc);
	void quickSort2(const std::string& optrion,int first, int last,bool isAsc);




	Book& bookFind(const std::string& option,const std::string& name);
	
	void booksSort(const std::string& option,bool isAsc);
	//Ascending order true 
	//descending order - false
	void pushUser(std::string name, std::string password);

	void addUser(const User& user);

	void removeUser(const std::string& name);

	void booksRemove(const std::string& name);

	void booksAdd(const Book& book);



	void readUsers(std::ifstream& file);

	void saveUsers(const char* file);



	void saveBooks(const char* file);
	void readBooks(std::ifstream& file1);
	
	const char* getInputFile() const;

	void save();

	void saveas(const char* file);
	
	void openFile();//will use _chdir(directory) 
	
	


	
	void change_directory(const std::string& str);

};


