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

#define _CRT_SECURE_NO_WARNINGS //to stop exception error for time ctime functions
#include <iostream>
#include <iomanip>
#include "reports.h"
#include "mainmenu.h"
#include "bookinfo.h"
#include "bookData.h"
#include <ctime> //import for time functions

using namespace std;

//Prototype functions
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();
void getCurrentTime();


//Declare Array of book objects *********************** Driver data stored at 0 and 1**************
extern class InventoryBook book[SIZE];

int reports() {
	char selection;
	do {
		//Output menu options
		cout << "_____________________________________________________________\n\n\n";
		cout << setw(30) << "Serendipity Booksellers\n";
		cout << setw(28) << "Reports\n\n";
		cout << setw(23) << "1. Inventory Listing\n";
		cout << setw(31) << "2. Inventory Wholesale Value\n";
		cout << setw(28) << "3. Inventory Retail Value\n";
		cout << setw(25) << "4. Listing by Quantity\n";
		cout << setw(21) << "5. Listing by Cost\n";
		cout << setw(20) << "6. Listing by Age\n";
		cout << setw(30) << "7. Return to the Main Menu\n\n";
		cout << setw(24) << "Enter Your Choice: ";
		//Get menu option and validate
		cin >> selection;
		while (menuVerify(selection, 7) == false) {
			cout << "Please enter a number in the range 1 - 7: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> selection;
		}
		//execute selection
		switch (selection) {
		case '1': repListing();
			break;
		case '2': repWholesale();
			break;
		case '3': repRetail();
			break;
		case '4': repQty();
			break;
		case '5': repCost();
			break;
		case '6': repAge();
			break;
		case '7': cout << "\n You selected main menu\n\n";
		}
	} while (selection != '7');
	return 0;
}
// Display a report listing all the books in the inventory
void repListing(){

	//print report
	cout << "\nInventory listing for "; 
	getCurrentTime(); //display time
	for(int i = 0; i < SIZE; i++){
		if(book[i].getISBN()[0] != NULL){
			bookinfo(book[i].getTitle(), 
				book[i].getISBN(), 
				book[i].getAuthor(), 
				book[i].getPublisher(),
				book[i].getDateAdded(), 
				book[i].getQty(), 
				book[i].getWholesale(), 
				book[i].getRetail());
		}
	}
}

// report that lists the following data on all books in
//the inventory: title, ISBN number, quantity on hand, and wholesale cost.
void repWholesale(){
	double wholeSaleTotal = 0; // totaling variable

	//print report
	cout << "\nWholesale report for ";
	getCurrentTime(); // Print date/time
	for (int i = 0; i < SIZE; i++) {
		if (book[i].getISBN()[0] != NULL) {
			bookinfo(book[i].getTitle(), 
				book[i].getISBN(), 
				book[i].getQty(), 
				book[i].getWholesale());
			
			wholeSaleTotal += (book[i].getWholesale() * (double)book[i].getQty());
		}
	}
	cout << "Your Wholesale inventory value is: $"<< wholeSaleTotal << endl;
}

// This function lists the following data on all books in the
// inventory: title, ISBN number, quantity on hand, and retail price.
void repRetail(){
	double retailSaleTotal = 0; // totaling variable

	//print report
	cout << "\nRetail report for ";
	getCurrentTime(); // Print date/time
	for (int i = 0; i < SIZE; i++) {
		if (book[i].getISBN()[0] != NULL) {
			bookinfo(book[i].getTitle(), 
				book[i].getISBN(), 
				book[i].getRetail(), 
				book[i].getQty());
			
			retailSaleTotal += (book[i].getRetail() * (double)book[i].getQty());
		}
	}
	cout << "Your retail inventory value is: $"<< retailSaleTotal << endl;
}

// This function lists the following data on all books in the
// inventory: title, ISBN number, and quantity on hand.
void repQty() {

	int id[20]; //array to track original subscripts
	int *idptr[20]; //pointer to tracking array
	int *qtyptr[20]; //array of pointers to qtyOnHand array
	
	//sorting variables
	int max;
	int *maxV;
	int *temp;


	//Initialize variables
	for (int i = 0; i < SIZE; i++)
	{
		id[i] = i;
		idptr[i] = &id[i];
		qtyptr[i] = book[i].getQtyPtr();
	}

	//sort index in descending order of qtyOnHand
	for (int i = 0; i < SIZE; i++) {
		max = i;
		maxV = qtyptr[i];
		temp = idptr[i];
		for (int j = i + 1; j < SIZE; j++) {
			if (*(qtyptr[j]) > *maxV) {
				max = j;
				maxV = qtyptr[j];
				temp = idptr[j];
			}
		}
		qtyptr[max] = qtyptr[i];
		idptr[max] = idptr[i];
		qtyptr[i] = maxV;
		idptr[i] = temp;
	}
	
	//print report
	cout << "\nQuantity on hand report for ";
	getCurrentTime(); // Print date/time
	
	for (int i = 0; i < SIZE; i++) {
		if (book[*(idptr[i])].getISBN()[0] != NULL) {
			bookinfo(book[*(idptr[i])].getTitle(), 
				book[*(idptr[i])].getISBN(), 
				book[*(idptr[i])].getQty());
		}
	}
}

// This function lists the following data on all books in the
// inventory: title, ISBN number, quantity on hand, and wholesale cost.
void repCost(){

	int id[20]; //array to track original subscripts
	int *idptr[20]; //pointer to tracking array
	double *wsaleptr[20]; //array of pointers to wholesale array

					 //sorting variables
	int max;
	double *maxV;
	int *temp;


	//Initialize variables
	for (int i = 0; i < SIZE; i++)
	{
		id[i] = i;
		idptr[i] = &id[i];
		wsaleptr[i] = book[i].getWholesalePtr();
	}

	//sort index in descending order of wholesale
	for (int i = 0; i < SIZE; i++) {
		max = i;
		maxV = wsaleptr[i];
		temp = idptr[i];
		for (int j = i + 1; j < SIZE; j++) {
			if (*(wsaleptr[j]) > *maxV) {
				max = j;
				maxV = wsaleptr[j];
				temp = idptr[j];
			}
		}
		wsaleptr[max] = wsaleptr[i];
		idptr[max] = idptr[i];
		wsaleptr[i] = maxV;
		idptr[i] = temp;
	}

	//print report
	cout << "\nWholesale Cost report for ";
	getCurrentTime(); // Print date/time

		for (int i = 0; i < SIZE; i++) {
		if (book[*(idptr[i])].getISBN()[0] != NULL) {
			bookinfo(book[*(idptr[i])].getTitle(), 
				book[*(idptr[i])].getISBN(), 
				book[*(idptr[i])].getQty(), 
				book[*(idptr[i])].getWholesale());
		}
	}
}

// This function lists the following data on all books in the
// inventory: title, ISBN number, quantity on hand, and date added to the inventory.
void repAge(){
	
	int id[20]; //array to track original subscripts
	int *idptr[20]; //pointer to tracking array
	char *ageptr[20]; //array of pointers to wholesale array

						  //sorting variables
	int max;
	char *maxV;
	int *temp;


	//Initialize variables
	for (int i = 0; i < SIZE; i++)
	{
		id[i] = i;
		idptr[i] = &id[i];
		ageptr[i] = book[i].getDateAdded();
	}

	//sort index in descending order of wholesale
	for (int i = 0; i < SIZE; i++) {
		max = i;
		maxV = ageptr[i];
		temp = idptr[i];
		for (int j = i + 1; j < SIZE; j++) {
			if (*(ageptr[j]) > *maxV) {
				max = j;
				maxV = ageptr[j];
				temp = idptr[j];
			}
		}
		ageptr[max] = ageptr[i];
		idptr[max] = idptr[i];
		ageptr[i] = maxV;
		idptr[i] = temp;
	}

	//print report
	cout << "\nAge report for ";
	getCurrentTime(); // Print date/time

	for (int i = 0; i < SIZE; i++) {
		if (book[*(idptr[i])].getISBN()[0] != NULL) {
			bookinfo(book[*(idptr[i])].getTitle(), 
				book[*(idptr[i])].getISBN(),
				book[*(idptr[i])].getDateAdded(), 
				book[*(idptr[i])].getQty(), 
				book[*(idptr[i])].getWholesale());
		}
	}
}

//Function that prints the date/time
void getCurrentTime() {
	struct tm *newTime;
	time_t szClock;

	time(&szClock);
	newTime = localtime(&szClock);
	cout << asctime(newTime) << endl;
}
