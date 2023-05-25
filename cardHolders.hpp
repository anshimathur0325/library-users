#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

//declarations
class cardHolders{
	int age;
	int books;
	std::string name;
	std::string pass;

	public:
		cardHolders(int booksout, int ages, std::string new_name, std::string password);
		int return_age();
		int return_books();
		void add_books(int num);
		void remove_books(int num);

};