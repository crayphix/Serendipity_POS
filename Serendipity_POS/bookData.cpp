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
#include <iomanip>
#include "bookData.h"
#include "mainmenu.h"

using namespace std;
//BookData Members

//Default constructor
BookData::BookData(){
	bookTitle[51] = NULL;
	isbn[14] = NULL;
	author[31] = NULL;
	publisher[31] = NULL;
}

////Overload Constructor
BookData::BookData(char newTitle[51], char newISBN[14], char newAuthor[31],
	char newPublisher[31]){

	strcpy_s(bookTitle, newTitle);
	strUpper(bookTitle);

	strcpy_s(isbn, newISBN);
	strUpper(isbn);

	strcpy_s(author, newAuthor);
	strUpper(author);

	strcpy_s(publisher, newPublisher);
	strUpper(publisher);
}

BookData::~BookData(){}


// function that sets title of bookdata object
void BookData::setTitle (char *newTitle) {
	strcpy_s(bookTitle, newTitle);
	strUpper(bookTitle); // set title to uppercase
}


// function that sets ISBN of bookdata class
void BookData::setISBN(char *newISBN) {
	strcpy_s(isbn, newISBN);
	strUpper(isbn); // set isbn to uppercase
}

// function that sets publisher of bookdata class
void BookData::setAuthor(char *newAuthor) {
	strcpy_s(author, newAuthor);
	strUpper(author); // set author to uppercase
}

// function that sets publisher of bookdata class
void BookData::setPub(char *newPublisher) {
	strcpy_s(publisher, newPublisher);
	strUpper(publisher); // set title to uppercase
}

// function that returns title of book
char* BookData::getTitle(){
	return bookTitle;
}

//function that returns isbn
char* BookData::getISBN(){
	return isbn;
}

//function that returns author
char* BookData::getAuthor(){
	return author;
}

//function that returns publisher
char* BookData::getPublisher(){
	return publisher;
}

bool BookData::bookMatch(char* search){
	if(strstr(bookTitle, search))
		return true;
	else
		return false;
}

//InventoryBook Members

//Default Constructor
InventoryBook::InventoryBook() : BookData(){
	dateAdded[11] = NULL;
    qtyOnHand = NULL;
    wholesale = NULL;
    retail = NULL;
}

// Overloaded Constructor for InventoryBook
InventoryBook::InventoryBook(char newTitle[51], char newISBN[14], 
        char newAuthor[31], char newPublisher[31], char newDateAdded[11], 
        int newQtyOnHand, double newWholesale, double newRetail) : 
		BookData (newTitle, newISBN, newAuthor, newPublisher){
			
			strcpy_s(dateAdded, newDateAdded);
			strUpper(dateAdded);

   			qtyOnHand = newQtyOnHand;
   			wholesale = newWholesale;
   			retail = newRetail;
		}
// Destructor
InventoryBook::~InventoryBook() {}

// function that sets date added of InventoryBook class
void InventoryBook::setDateAdded(char *newDateadded) {
	strcpy_s(dateAdded, newDateadded);
	strUpper(dateAdded); // set date added to uppercase{
}

// function that sets quantity of InventoryBook class
void InventoryBook::setQty(int newQty) {
	qtyOnHand = newQty;
}

// function that sets wholesale price of InventoryBook class
void InventoryBook::setWholesale(double newWhole) {
	wholesale = newWhole;
}

// function that sets retail price of InventoryBook class
void InventoryBook::setRetail(double newRetail) {
	retail = newRetail;
}

// bool function that returns 1 if InventoryBook class is empyt 0 if otherwise
bool InventoryBook::isEmpty() {
	if (bookTitle != 0)
		return 1;
	else
		return 0;
}

//function that removes book from inventory
void InventoryBook::removeBook() {
	strcpy_s(bookTitle, "");
	strcpy_s(isbn, "");
}

//function that returns dateAdded
char* InventoryBook::getDateAdded(){
	return dateAdded;
}

//function that returns qtyOnHand
int InventoryBook::getQty(){
	return qtyOnHand;
}

//function that returns wholesale
double InventoryBook::getWholesale(){
	return wholesale;
}

//function that returns retail
double InventoryBook::getRetail(){
	return retail;
}

int* InventoryBook::getQtyPtr(){
	return &qtyOnHand;
}

double* InventoryBook::getWholesalePtr(){
	return &wholesale;
}

char* InventoryBook::getDateAddedPtr(){
	return &dateAdded[0];
}

//Members of SoldBook Class
	//Default Constructor
    SoldBook::SoldBook() : InventoryBook(){
    	qtySold = NULL;
    	subtotal = NULL;
    }

    //Overloaded Constructor
    SoldBook::SoldBook(char newTitle[51], char newISBN[14],
		char newAuthor[31], char newPublisher[31], char newDateAdded[11],
		int newQtyOnHand, double newWholesale, double newRetail, 
		int thisQtySold) : InventoryBook(newTitle, newISBN, newAuthor, newPublisher, newDateAdded,
			newQtyOnHand, newWholesale, newRetail){
    	qtySold = thisQtySold;
    	subtotal = 0;
    }

	//Overloaded Constructor
	SoldBook::SoldBook(char newTitle[51], char newISBN[14],
		char newAuthor[31], char newPublisher[31], char newDateAdded[11],
		int newQtyOnHand, double newWholesale, double newRetail) : InventoryBook(newTitle, newISBN, newAuthor, newPublisher, newDateAdded,
			newQtyOnHand, newWholesale, newRetail) {
		qtySold = 0;
		subtotal = 0;
	}

    //Destructor
    SoldBook::~SoldBook(){}

    //get qty sold
    int SoldBook::getQtySold(){
    	return qtySold;
    }

    //set qty Sold
    void SoldBook::setQtySold(int thisQtySold){
    	qtySold = thisQtySold;
    }

    //tax Calculated as qtySold times retail times taxRate. 
    //retail is inherited from InventoryBook.
    double SoldBook::getTax(){
    	return retail * taxRate();
    }

    //subtotal of the sale of a particular title. The subtotal is
    // calculated as retail times qtySold plus tax.
    double SoldBook::getSubTotal(){
    	return qtySold * getTax();
    }

