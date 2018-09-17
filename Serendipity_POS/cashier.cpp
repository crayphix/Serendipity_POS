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
#include "cashier.h"
#include "mainmenu.h"
#include <cctype>
#include "bookData.h"
#include <new>
#include <vector>
#include <fstream>
using namespace std;

	//Declare Array of book objects 
	extern class InventoryBook book[SIZE];

int cashier() {
	//Declare outer loop variables
	int hold; // variable to hold choice to loop sales system
	char goAgain = NULL; // variable to hold choice to go again

	//Prompt user for sales input
	do
	{
		//*****inner Loop variables*******
		string date;
		char isbnIn[14];
		
		//variable to hold qty to sell. Is a string to verify input selection
		string qty; 

		//sale total variables
		double tax = 0;
		double total = 0;
		double subtotal = 0;

		//Create array to hold index
		int *indexptr = nullptr;
		indexptr = new int[100];

		//Define SoldBook pointer 
		SoldBook *SoldBookPtr = nullptr;

		//Define vector to hold multiple SoldBook Objects
		vector<SoldBook> soldBookVect;

		// loop count to iterate for each item added to cart
		int loopCt = 0; 

		//Get date for transaction	
		cout << "\nPlease enter the date: "; 
		cin.ignore(); // Get date of sale
		getline(cin, date);

		//prompt input of books to sell
		do {
			cout << "\nPlease enter the ISBN #: ";
			cin.getline(isbnIn, 14); // Get ISBN #
			strUpper(isbnIn);
			
			//Look up ISBN number prompt re-entry if invalid
			int count = 0; //counter for verification loop
			do {
				for (int i = 0; i < SIZE; i++) {
					if (strcmp(isbnIn, book[i].getISBN()) == 0) {
						indexptr[loopCt] = i; // book match location
						break;
					}

					else if (i == SIZE - 1 && isbnIn != book[i].getISBN()) {
						cout << "\nISBN does not exist. Please try again (enter 0 to exit): ";
						cin.getline(isbnIn, 14);
						if (strcmp(isbnIn, "0") == 0)
							return 0;
					}
				} break;
			} while (strcmp(isbnIn, book[loopCt].getISBN()) != 0);


			//Prompt user for amount to sell 
			cout << "How many copies?: ";
			getline(cin, qty);
			while(!isNumber(qty)){ //verify input is a number 
				cout << "\nInvalid input! Please enter a quantity: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input
				cin >> qty;
			}

			//Confirm inventory and let user know if out of bounds
			while(atoi(qty.c_str()) > book[indexptr[loopCt]].getQty() || !isNumber(qty) ){
				cout << "\nNot enough copies available! Please enter a quantity up to " << book[indexptr[loopCt]].getQty() << ": ";
				getline(cin, qty);
			}

			//Dynamically allocate a InventoryBook object into SoldBook array with qtySold initilized 
			// throw exception if out of memory
			try {
				//allocate inventoryBook item into sold book array with qtySold 
				SoldBookPtr = new SoldBook(book[indexptr[loopCt]].getTitle(), book[indexptr[loopCt]].getISBN(), book[indexptr[loopCt]].getAuthor(),
					book[indexptr[loopCt]].getPublisher(), book[indexptr[loopCt]].getDateAdded(), book[indexptr[loopCt]].getQty(), 
					book[indexptr[loopCt]].getWholesale(), book[indexptr[loopCt]].getRetail(), atoi(qty.c_str()));
			
				//Add soldbook item to vector
				soldBookVect.push_back(*SoldBookPtr);
			}
			// catch exception if out of memory
			catch (bad_alloc& ex) {
				cout << sizeof(SoldBook) * loopCt << " bytes : Out of memory!";
				cin.get();
				exit(1);
			}

			// prompt user to input more books
			cout << "\nDo you have more books to add? (Y/N): ";
			cin >> goAgain;
			//
			while (toupper(goAgain) != 'Y' && toupper(goAgain) != 'N') { //loop goAgain choice
				cout << "\nPlease enter Y or N: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input
				cin >> goAgain;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input

			// iterate loopCt
			loopCt++; 
		} while (toupper(goAgain) != 'N');


			/*Output Sales Slip
			
			********Example of formating******* 
			_________________________________________________________
			Serendipity Booksellers

			Date: 11-12-1982

			Qty   ISBN             Title                  Price      Total
			_____________________________________________________________


			1     1-1-1            THIS IS ONE            $ 5.40     $ 5.40

			1     2-2-2            THIS IS TWO            $ 45.55    $ 45.55

						Subtotal                                     $ 50.95
						Tax                                          $ 3.06
						Total                                        $ 54.01

			Thank You for Shopping at Serendipity!

			_____________________________________________________________
			*/
		cout << "\n\n_____________________________________________________________";
		cout << "\nSerendipity Booksellers\n\n";
		cout << "Date: " << date << "\n\n";
		cout << "Qty" << setw(7) << "ISBN" << setw(18) << "Title" << setw(23) << "Price" << setw(12) << "Total\n";
		cout << "_____________________________________________________________\n\n\n";
		cout << left << setprecision(2) << fixed;

		//Loop through vector and output books to be sold 
		for(int i = 0; i < loopCt; i++ ){
			cout << setw(6) << soldBookVect[i].getQtySold() << setw(17) << soldBookVect[i].getISBN() << setw(23) << soldBookVect[i].getTitle() << "$ "
			<< setw(9) << soldBookVect[i].getRetail() << "$ " << soldBookVect[i].getRetail() * soldBookVect[i].getQtySold() << endl << endl;
			
			// Accumulate totals
			subtotal += (soldBookVect[i].getRetail() * soldBookVect[i].getQtySold());

			// Update inventory
 			book[indexptr[i]].setQty(soldBookVect[i].getQty() - soldBookVect[i].getQtySold());
		}
			//finish total calculations
			tax = subtotal * .06;
			total = subtotal + tax;	

		//Output accumulated totals
		cout << right << setw(20) << "Subtotal" << setw(39) << "$ " << subtotal << endl; 
		cout << right << setw(15) << "Tax" << setw(44) << "$ " << tax << endl;
		cout << right << setw(17) << "Total" << setw(42) << "$ " << total << endl << endl;
		cout << "Thank You for Shopping at Serendipity!\n\n";
		cout << "_____________________________________________________________\n\n\n";
		cout << "Enter 1 to enter another sale, Enter 2 to exit: ";
		cin >> hold;
		cin.ignore();

	//Delete memory and reinitialize pointers to null
	delete [] indexptr;
	indexptr = nullptr; 

	delete SoldBookPtr;

	//Open file object to append
	fstream invData(MYFILE, ios::in | ios::binary); // input to binary mode

	// open file to Append file to next available inventory location
	try {
		if (invData) {
			fstream invData(MYFILE, ios::out | ios::binary | ios::app);

			//write inventory file
			for (int i = 0; i < SIZE; i++) {
				invData.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
			}

			//Close file
			invData.close();
			invData.clear();
		}
		//Throw error message if file does not exist
		else
			throw 0;
	}
	// catch and display error message
	catch (int x) {
		cout << "Inventory file does not exist! Error Code: " << x << endl;
		exit(1);
	}

	} while (hold == 1);
	return 0;
}
