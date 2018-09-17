/*
* Class: CMSC226 CRN 44374
* Instructor: Grigoriy Grinberg
* Description: 7/22 update on rolling Bookstore project
* Due Date: 7/22
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Bryan Speelman
*/


#include <iostream>
#include <iomanip>
#include <string>
#include "bookinfo.h"
#include "mainmenu.h"
#include "bookdata.h"
using namespace std;

 //Display All Book information
int bookinfo(char bookTitle[51], char isbn[14], char author[31],
	char publisher[31], char dateAdded[11], int qtyOnHand, double wholesale, double retail) {
	cout << "*************************************************************\n\n";
	cout << setw(30) << "Serendipity Booksellers\n";
	cout << setw(28) << "Book Information\n\n";
	cout << "   Title: " << bookTitle << endl;
	cout << "   ISBN: " << isbn << endl;
	cout << "   Author: " << author << endl;
	cout << "   Publisher: " << publisher << endl;
	cout << "   Date Added: " << dateAdded << endl;
	cout << "   Quantity-On-Hand: " << qtyOnHand << endl;
	cout << "   Wholesale Cost: " << wholesale << endl;
	cout << "   Retail Price: " << retail << endl << endl;
	cout << "\n\n*************************************************************\n\n\n";
	return 0;
}


//Display title, ISBN number, quantity on hand, and wholesale cost.
int bookinfo(char bookTitle[51], char isbn[14], int qtyOnHand, double wholesale) {
	cout << "*************************************************************\n\n";
	cout << setw(30) << "Serendipity Booksellers\n";
	cout << setw(28) << "Book Information\n\n";
	cout << "   Title: " << bookTitle << endl;
	cout << "   ISBN: " << isbn << endl;
	cout << "   Quantity-On-Hand: " << qtyOnHand << endl;
	cout << "   Wholesale Cost: " << wholesale << endl;
	cout << "\n\n*************************************************************\n\n\n";
	return 0;
}

//Display title, ISBN number, quantity on hand, and retail cost.
int bookinfo(char bookTitle[51], char isbn[14], double retail, int qtyOnHand) {
	cout << "*************************************************************\n\n";
	cout << setw(30) << "Serendipity Booksellers\n";
	cout << setw(28) << "Book Information\n\n";
	cout << "   Title: " << bookTitle << endl;
	cout << "   ISBN: " << isbn << endl;
	cout << "   Quantity-On-Hand: " << qtyOnHand << endl;
	cout << "   Retail Price: " << retail << endl << endl;
	cout << "\n\n*************************************************************\n\n\n";
	return 0;
}

//Display Titel isbn and qty on hand
int bookinfo(char bookTitle[51], char isbn[14], int qtyOnHand) {
	cout << "*************************************************************\n\n";
	cout << setw(30) << "Serendipity Booksellers\n";
	cout << setw(28) << "Book Information\n\n";
	cout << "   Title: " << bookTitle << endl;
	cout << "   ISBN: " << isbn << endl;
	cout << "   Quantity-On-Hand: " << qtyOnHand << endl;
	cout << "\n\n*************************************************************\n\n\n";
	return 0;
}

//Display title, ISBN number, quantity on hand, and wholesale cost and date added
int bookinfo(char bookTitle[51], char isbn[14], char dateAdded[11], int qtyOnHand, double wholesale) {
	cout << "*************************************************************\n\n";
	cout << setw(30) << "Serendipity Booksellers\n";
	cout << setw(28) << "Book Information\n\n";
	cout << "   Title: " << bookTitle << endl;
	cout << "   ISBN: " << isbn << endl;
	cout << "   Date Added: " << dateAdded << endl;
	cout << "   Quantity-On-Hand: " << qtyOnHand << endl;
	cout << "   Wholesale Cost: " << wholesale << endl;
	cout << "\n\n*************************************************************\n\n\n";
	return 0;
}