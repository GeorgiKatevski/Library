#pragma once
#include <iostream>
#include <string>
#include <fstream>


class User
{

public:
	User(const std::string& _name,const std::string& _password, bool _isAdmin);
	
	User() = default;
/*	{
		setName("Default");
		setPassword("Default");
		isAdmin = 1;
	}*/
	void saveUser(const char* file);
	void  readUser(std::ifstream& file);

	void setName(const std::string& _name);
	void setPassword(const std::string& _password);
	void setAdmin(bool isAdmin);


	const std::string& getName() const;
	const std::string& getPassword() const;
	bool getisAdmin() const;
private:
	std::string name;
	std::string password;
	bool isAdmin = false;

};


