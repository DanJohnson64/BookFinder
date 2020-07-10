#include "book.h"

using namespace std;
Book::Book()
{
	author = "No name";	
	title = "Unknown";
	isbn = 0;
}
void Book::bookPrinter()const 
{
	cout << left 
		 << setw(20) << author << " "
		 << setw(40) << title << " "
	   	 << setw(20)<< isbn << endl;
}
void Book::getData(ifstream &input)
{		
	string tempisbn;
	getline(input, author);
	getline(input, title);
	getline(input, tempisbn);
	isbn = stoi(tempisbn,nullptr,0);
}
int Book::getISBN()const
{
	return isbn;
}

