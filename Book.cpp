#pragma once
#include "Book.h"
Book::Book()
{
		setGenre("Action");
		setRating(3.0);
		setDescription("Nohing");	
}

Book::Book(const std::string& _title="",const std::string& _author="",const std::string& _genre="",const std::string& _ISBN="", double _rating=2.0,
	size_t _year = 1, const std::string& _description = "", std::string _keyWords[15] = {}) :year(_year), title(_title),author( _author)
{
	setRating(_rating);
	setGenre(_genre);
	setDescription(_description);
	setISBN(_ISBN);
	setKeyWords(_keyWords);
}

void Book::setGenre(const std::string& _genre)
{

	if (_genre == "Action"	||_genre=="Adventure" || 
		_genre=="Biography" ||_genre =="Romance"  ||
		_genre=="War"       ||_genre=="Mystery"   ||
		_genre=="Horror"    || _genre=="History"  ||
		_genre=="Sport"     || _genre=="Sci-Fi"   )
	{
		genre = _genre;
	}
	else
	{
		genre = "Wrong genre";
	}
}

void Book::setRating(double _rating)
{
	assert(rate > 0.0);
	assert(rate < 10.0);
		rate = _rating;
		
}


void Book::setDescription(const std::string& _description)
{
	int len = _description.length();
	if (len >= 256)
	{
		description = "";
	}
	else
	{
		description = _description;
	}

}

void Book::setKeyWords(std::string _words[15])
{
	for (size_t i = 0; i < 15; i++)
	{
		keyWords[i] = _words[i];
	}
}

void Book::setISBN(const std::string& _ISBN)
{
	if (!_ISBN.empty())
	{
		ISBN = _ISBN;
	}
	else
	{
		ISBN = "Dedault_ISBN";
	}


}


void Book::printBook() const
{
	std::cout << "Title: "  << title << "  Author: " <<author<<  " Genre: " <<
		genre <<"  Year: "    << year  << "  Rating: " << rate << "  "<<ISBN << std::endl;
	std::cout << "Desc ";
	std::cout << description << std::endl;

	//keyWords->size() vmesto 15
	for (size_t i = 0; i < 15; i++)
	{
		std::cout << keyWords[i] << " ";
	}
	std::cout << std::endl;

}

const char Book::getFirstLetter(const std::string& option) const
{
	std::string s;
	if (option == "title")
	{
		s = getTitle();
	}
	else
	{
		s = getAuthor();
	}
	const int n = 15;
	// declaring character array 
	char char_array[n];

	// copying the contents of the 
	// string to char array 
	strcpy(char_array, s.c_str());

	return char_array[0];

}


 double Book::getRating() const
{
	return rate;
}

const std::string& Book::getTitle() const
{
	return title;
}
const std::string& Book::getAuthor() const
{
	return author;
}
const std::string& Book::getISBN() const
{
	return ISBN;
}
const std::string& Book::getGenre() const
{
	return genre;
}

void Book::readBook(std::ifstream& file1)
{
	
	if (!file1)
	{
		std::cout << "Cannot open the file"<<std::endl;
		return;
	}
	
	std::string strToRead;


	file1 >> strToRead;
	int count = 0;


	while (!file1.eof())
	{
		if (strToRead == "Book:")
		{

			if (count != 0)
			{
				break;
			}
			else
			{
				count++;
				std::string secondfNameOfAuthor;
				file1 >> title >> author >> secondfNameOfAuthor >> genre >> year >> rate >> ISBN;
				author += " ";
				author += secondfNameOfAuthor;

			}
		}
		else
		{
			count++;
			title = strToRead;
			std::string secondfNameOfAuthor;
			file1 >> author >> secondfNameOfAuthor >> genre >> year >> rate >> ISBN;
			author += " ";
			author += secondfNameOfAuthor;

		}
		setDescription("");
		while (strToRead != "KeyWords:")
		{

			file1 >> strToRead;
			if (strToRead == "KeyWords:")
			{
				break;
			}
			if (strToRead!="Description:")
			{
				description += strToRead;
				description += " ";
			}
			else
			{
				file1 >> strToRead;
			}

		}
		size_t index = 0;
		while (strToRead != "Book:")
		{
			file1 >> strToRead;
			if (strToRead != "Book:")
			{
				if (index <= 14)
				{
					keyWords[index] = strToRead;
					index++;
				}
				else
				{
					break;
				}
				}
			
			if (file1.eof())
			{
				break;
			}
			
		}


		

	}



}

void Book::saveBook(const char* file)
{
	std::ofstream file1(file ,std::ios::out | std::ios::app);
	if (!file1)
	{
		std::cout << "Cannot open the file" << std::endl;
		return;
	}

	file1 <<"Book:"<<" "<< title << " " << author << " " << genre << " " << year << " "
		<< rate << " " << ISBN << " "<<"Description:"<<" "<<description <<" "<< "KeyWords:"<<" ";
	for (size_t i = 0; i < 15; i++)
	{
		file1 << keyWords[i]<<" ";
	}

	file1.close();
}



size_t Book::getYear() const
{
	
		return year;
	
}

void Book::getOptionForSorting(const std::string& option) const
{

	if (option == "title")
	{
		std::cout<<getTitle();
	}
	if (option == "author")
	{
	std::	cout<<getAuthor();
	}
	if (option == "year")
	{
		std::cout<<getYear();
	}
	



}



