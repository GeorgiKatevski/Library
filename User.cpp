#include "User.h"

User::User(const std::string& _name,const std::string& _password, bool _isAdmin)
{
	setName(_name);
	setPassword(_password);
	isAdmin = _isAdmin;

}


const std::string& User::getName() const
{
	return name;
}
const std::string& User::getPassword() const
{
	return password;
}
bool User::getisAdmin() const
{
	 return isAdmin;
}
void User::setName(const std::string& _name)
{
	name = _name;
}

void User::setPassword(const std::string& _password)
{
	password = _password;
}

void User::setAdmin(bool _isAdmin)
{
	isAdmin = _isAdmin;

}


void User::readUser(std::ifstream& is)
{

	if (is.is_open())
	{
		std::string _name;
		std::string _password;
		bool _isAdmin = false;
		is >> _name >> _password >> _isAdmin;
		if (!is)
		{
			return;
		}
		setName(_name);
		setPassword(_password);
		isAdmin = _isAdmin;
	}
	else
	{
	std::cout << "Cannot open the file!" <<std::endl;
		return;
	}
}

void User::saveUser(const char* file)
{

	std::ofstream os(file, std::ios::out | std::ios::app);
	if (os.is_open())
	{
		os << name << " " << password <<" "<< isAdmin<<" ";
	}
	else
	{
		std::cout << "Cannot open stream for saving user" << std::endl;
		return;
	}
}