#include "book.h"
using namespace std;

void requestProcessor(Book bookarray[10], ifstream &input)
{
	int isbn_in, count = 0;
	cout << "Ah, I see you have an ISBN request," << endl
		<< "Let me process that for you!" << endl << endl
		<< "Beep Boop...kkrrggzz...DING!" << endl << endl
		<< "OK here are the results!" << endl << endl;
	while (!input.eof())
	{
		cout << "--------------------------------" << endl;
		input >> isbn_in;
		for (int i = 0; i < 10; i++)
		{
			if (isbn_in == bookarray[i].isbn)
			{
				cout << "For ISBN " << isbn_in
					 << " there was a match!" << endl << endl;
				cout << bookarray[i].author << endl
					 << bookarray[i].title << endl
					 << bookarray[i].isbn << endl;
				cout << endl;
			}
			else			
				count++;					 			
		}		
		if (count == 10)
		{
			cout << "No match found for ISBN "
				<< isbn_in << endl << endl;
		}
		count = 0;
	}
}
int main()
{
	Book book1, book2;
	Book book_shelf[10] = {};
	ifstream input("mp8book.txt");
	ifstream mp8bookarray("mp8bookarray.txt");
	ifstream mp8bookISBN("mp8bookISBN.txt");

	cout << "Testing the book class by Daniel Johnson" << endl << endl;
	cout << "the information for book 1 is" << endl;
	book1.bookPrinter();
	book2.getData(input);
	cout << "the information for book 2 is" << endl;
	book2.bookPrinter();


	cout << endl << endl << endl;

	cout << "Welcome to the MP8 Library!" << endl
		<< "These are the books we currently have in:" << endl << endl
		<< left << setw(21) << "Author"
		<< setw(42) << "Title"
		<< setw(20) << "ISBN" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		book_shelf[i].getData(mp8bookarray);
		book_shelf[i].bookPrinter();
	}
	cout << endl << endl << endl;
	requestProcessor(book_shelf, mp8bookISBN);
}
/* 
	Oputput:

	Testing the book class by Daniel Johnson

the information for book 1 is
No name              Unknown                                  0
the information for book 2 is
Jane Smith           History Of This World                    12349876



Welcome to the MP8 Library!
These are the books we currently have in:

Author               Title                                     ISBN

H. M. Deitel         C++ How to Program                       130895717
Judy Bishop          Java Gently                              201593998
Jeff Salvage         The C++ Coach                            201702894
Thomas Wu            Object-Oriented Programming with Java    256254621
Cay Horstmann        Computing Concepts with C++              471164372
Gary Bronson         Program Development and Design           534371302
Joyce Farrell        Object-Oriented Programming              619033614
D. S. Malik          C++ Programming                          619062134
James Roberge        Introduction to Programming in C++       669347183
Nell Dale            C++ Plus Data Structures                 763714704



Ah, I see you have an ISBN request,
Let me process that for you!

Beep Boop...kkrrggzz...DING!

OK here are the results!

--------------------------------
For ISBN 201593998 there was a match!

Judy Bishop
Java Gently
201593998

--------------------------------
No match found for ISBN 888899999

--------------------------------
For ISBN 763714704 there was a match!

Nell Dale
C++ Plus Data Structures
763714704

--------------------------------
No match found for ISBN 111122222

--------------------------------
For ISBN 256254621 there was a match!

Thomas Wu
Object-Oriented Programming with Java
256254621

--------------------------------
For ISBN 130895717 there was a match!

H. M. Deitel
C++ How to Program
130895717

--------------------------------
No match found for ISBN 488881111

--------------------------------
For ISBN 534371302 there was a match!

Gary Bronson
Program Development and Design
534371302

--------------------------------
For ISBN 619033614 there was a match!

Joyce Farrell
Object-Oriented Programming
619033614


D:\Users\DZilla\source\repos\MP7\Debug\MP8.exe (process 23896) exited with code 0.
Press any key to close this window . . .
*/
