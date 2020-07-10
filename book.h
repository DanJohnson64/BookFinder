#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class Book
{
public:
	string author;
	string title;
	int isbn;	
		Book();	
   void bookPrinter()const;
   void getData(ifstream &input);
    int getISBN()const;
};