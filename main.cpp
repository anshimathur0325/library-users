#include <iostream>
#include "cardHolders.hpp"
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;


int main(){
	string un, pass1, books; 
	std::string reg;
	int num;
	int x=1;

	//check age
	std::cout<<"Hello, how old are you?"<<"\n";
	std::cin>>num;
	if(num>15){
		std::cout<<"Welcome to the library user system.\n";
	}else{
		std::cout<<"you're too young kid"<<"\n";
		x=0;
	}

	while(x==1){
		//question user about their action
		std::cout<<"Do you want to register for a library card?(1)\n";
		std::cout<<"Do you have an account already?(2)\n";
		std::cout<<"Do you want to end the program?(3)\n";

		std::cin>>reg;

		//if they need to register
		if(reg=="3"){
			std::cout<<"Goodbye.";
			exit(0);
		}else if(reg=="1"){
			
			std::string name;
			std::cout<<"Enter a username.\n";
			std::cin>>name;
			std::string pass2;
			std::cout<<"Enter a password.\n";
			std::cin>>pass2;
			cardHolders a(0,num,name,pass2);

			std::cout<<"Do you want to check out more books?(y/n)\n";
			std::cin>>reg;
			if(reg=="y"){
				std::cout<<"How many?\n";
				int num_books;
				std::cin>>num_books;
				a.add_books(num_books);
			}

		}
		//if they already have an account
		else{
			std::string name;
			std::cout<<"What is your username?\n";
			std::cin>>name;
			std::string pass;
			std::cout<<"What is your password.\n";
			std::cin>>pass;
			ifstream read("C:\\Anshi\\c++\\Users\\"+name+".txt");
			getline(read, un);
			getline(read, pass1);
			getline(read, books);

			if (un==name&&pass1==pass){
				cardHolders a(stoi(books),num,name, pass1);

				//check out more books
				std::cout<<"Do you want to check out more books?(y/n)\n";
				std::cin>>reg;
				if(reg=="y"){
					std::cout<<"How many?\n";
					int num_books;
					std::cin>>num_books;
					a.add_books(num_books);
				}

				//return some books
				string ret;
				std::cout<<"Do you want to return books?(y/n)\n";
				std::cin>>ret;
				if(ret=="y"){
					std::cout<<"How many?\n";
					int num_books;
					std::cin>>num_books;
					a.remove_books(num_books);
				}

			std::cout<<"You have "<<a.return_books()<<" books.\n";
			}else{
				std::cout<<"Wrong user.";
			}
			
		}
	

		//repeats program if wanted 
		string cont;
		std::cout << "Do you want to continue?(y/n)\n";
		std::cin>>cont;
		if(cont=="y"){
			x=1;
		}else{
			std::cout<<"Goodbye";
			x=0;
		}
	}

}