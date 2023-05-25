#include "cardHolders.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstdio>

using namespace std;

//cardHolders object
cardHolders::cardHolders(int booksout, int ages, std::string new_name, std::string password){
		age=ages;
		books=booksout;
		name=new_name;
		pass=password;
		ofstream newfile;

		//file where the card holders are stored
		newfile.open("C:\\Anshi\\c++\\Users\\"+name+".txt");
		newfile <<name<<endl;
		newfile <<pass<<endl;
		newfile <<books<<endl;
		newfile.close();
		
	}

int cardHolders::return_age(){
		return age;
	}

int cardHolders::return_books(){
		return books;
	}

//keeps track of people checking out books
void cardHolders::add_books(int num){
	std::string nfile = name+".txt";
	int result = remove(nfile.c_str());
	int new_num=num;
	while((books+new_num)>50){
		std::cout<< "Invalid amount. There is a limit of 50 books. Enter a new amount.\n";
		std::cin>>new_num;
	}
	books+=new_num;
	ofstream newfile;

	//file where the card holders are stored
	newfile.open("C:\\Anshi\\c++\\Users\\"+name+".txt");
	newfile <<name<<endl;
	newfile <<pass<<endl;
	newfile <<books<<endl;
	newfile.close();
}

//keeps track of people returning books
void cardHolders::remove_books(int num){
	std::string nfile = name+".txt";
	int result = remove(nfile.c_str());
	int new_num=num;
	while((books-new_num)<0){
		std::cout<< "Invalid amount. Enter a new one.\n";
		std::cin>>new_num;
	}
	books-=new_num;
	ofstream newfile;

	//file where the card holders are stored
	newfile.open("C:\\Anshi\\c++\\Users\\"+name+".txt");
	newfile <<name<<endl;
	newfile <<pass<<endl;
	newfile <<books<<endl;
	newfile.close();
}

