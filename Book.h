#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#pragma warning(disable:4996)
class Book
{
public:
	
	Book();
	
	Book(const std::string& title,const std::string& _author,
				const std::string& genre,const std::string& _ISBN,double _rating,size_t _year,
				   	const std::string& _desrciption,std::string keyWords[15]);

	void setGenre(const std::string& _genre);
	void setRating(double _rating);
	void setDescription(const std::string& _description);
	void setKeyWords(std::string _words[15]);
	void setISBN(const std::string& _ISBN);

	 double getRating() const;
	const std::string& getTitle() const;
	const std::string& getAuthor() const;
	const std::string& getISBN() const;
	const std::string& getGenre() const;

	void readBook(std::ifstream& file1);
	void saveBook(const char* file);

	


	size_t getYear() const;

	void getOptionForSorting(const std::string& option) const;


	void printBook() const;
	//this function is for sorting the titles 
	const char getFirstLetter(const std::string& option) const;

	


private:
	std::string author="sadsd";
	std::string title="";
	std::string genre="";
	size_t year=0;
	std::string description="";
	//std::string keyWords=""; // masiv?
	std::string keyWords[15];
	double rate=2.0;
	std::string ISBN="";


};

