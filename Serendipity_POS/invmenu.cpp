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
#include "invmenu.h"
#include "mainmenu.h"
#include "bookinfo.h"
#include <string>
#include <cctype>
#include "bookData.h"
#include <fstream>
using namespace std;

//Prototype functions
void lookUpBook();
void addBook();
void editBook();
void deleteBook();

//Declare Array of book objects *********************** Driver data stored at 0 and 1**************
InventoryBook book[SIZE];

int invmenu() {
	char selection;
	do {
		//Output menu options
		cout << "_____________________________________________________________\n\n\n";
		cout << setw(30) << "Serendipity Booksellers\n";
		cout << setw(28) << "Inventory Database\n\n";
		cout << setw(23) << "1. Look Up a Book\n";
		cout << setw(19) << "2. Add a Book\n";
		cout << setw(27) << "3. Edit a Book Record\n";
		cout << setw(22) << "4. Delete a Book\n";
		cout << setw(33) << "5. Return to the Main Menu\n\n";
		cout << setw(24) << "Enter Your Choice: ";
		//Get menu option and validate
		cin >> selection;
		while (menuVerify(selection, 5) == false) {
			cout << "Please enter a number in the range 1 - 5: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> selection;
		}
		//execute selection
		switch (selection) {
		case '1': lookUpBook();
			break;
		case '2': addBook();
			break;
		case '3': editBook();
			break;
		case '4': deleteBook();
			break;
		case '5': cout << "\n You selected main menu\n\n";
		}
	} while (selection != '5');
	return 0;
}

/*

*/

//function add book to inventory
void addBook(){
	//Hold variables for input
	char temp[51] = "";
	int tempInt = NULL;
	double tempDouble = NULL;
	
	for(int i = 0; i < SIZE; i++){
		if(book[i].isEmpty()){
			cout << "Please enter the title: ";
			cin.ignore();
			cin.getline(temp, 51);
			book[i].setTitle(temp);

			cout << "Please enter the ISBN #: ";
			cin.getline(temp, 14);
			book[i].setISBN(temp);

			cout << "Please enter the Author's name: ";
			cin.getline(temp, 31);
			book[i].setAuthor(temp);

			cout << "Please enter the publisher: ";
			cin.getline(temp, 31);
			book[i].setPub(temp);

			cout << "Please enter the date (MM-DD-YYYY): ";
			cin.getline(temp, 11);
			book[i].setDateAdded(temp);

			cout << "Please enter the qty: ";
			cin >> tempInt;
			book[i].setQty(tempInt);

			cout << "Please enter the wholesale price: ";
			cin >> tempDouble;
			book[i].setWholesale(tempDouble);

			cout << "Please enter the price: ";
			cin >> tempDouble;
			book[i].setRetail(tempDouble);

			cout << endl;
			
			//Open file object to append
			fstream invData(MYFILE, ios::in | ios::binary); // input to binary mode

			// open file to Append file to next available inventory location
			try{
                 if (invData) {
			     	fstream invData(MYFILE, ios::out | ios::binary |ios::app);

			     	//write inventory file
			     	invData.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));

			     	//Close file
			     	invData.close();
			     	invData.clear();
			     break;
                 }
				//Throw error message if file does not exist
                else 
					throw 0;
             }
             // catch and display error message
             catch(int x){
                cout << "Inventory file does not exist! Error Code: " << x << endl;
				exit(1);
             }
		}
		else if(i == SIZE)
			cout << "Inventory is full";
	}
}


//function edit book 
void editBook(){
	char search[51];//char variable for searching title
	char selectionYN;
	char selectionCS; 
	strUpper(search);

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Please enter the title: ";
	cin.getline(search, 51);
	strUpper(search);

	//Look up book
	for(int i = 0; i < SIZE; i++){
		if(book[i].bookMatch(search)){ //find match
		
			//validate match
			cout << "Is this your book? " << book[i].getTitle() << "  Y/N: ";
			selectionYN = getchar();

			//validate user validation
			while (selectionYN != 'Y' && selectionYN != 'y' && selectionYN != 'N' &&
				selectionYN != 'n'){
				cin >> selectionYN;
			}
			if(toupper(selectionYN) == 'Y'){
				bookinfo(book[i].getTitle(), book[i].getISBN(), book[i].getAuthor(), book[i].getPublisher(), 
					book[i].getDateAdded(), book[i].getQty(), book[i].getWholesale(), book[i].getRetail());
					//Output edit options
					cout << "_____________________________________________________________\n\n\n";
					cout << setw(30) << "Serendipity Booksellers\n";
					cout << setw(28) << "Inventory Edit\n";
					cout << endl << setw(19) << "1. Edit title\n";
					cout << setw(19) << "2. Edit isbn \n";
					cout << setw(20) << "3. Edit author\n";
					cout << setw(23) << "4. Edit publisher\n";
					cout << setw(24) << "5. Edit date added\n";
					cout << setw(30) << "6. Edit quantity on hand\n";
					cout << setw(29) << "7. Edit wholesale price\n";
					cout << setw(26) << "8. Edit retail price\n";
					cout << setw(31) << "9. Cancel request to edit\n";
					cout << endl 		<< setw(22) << "Enter Your Choice: ";
					
					//Get menu option and validate
					cin >> selectionCS;
					while (menuVerify(selectionCS, 9) == false) {
						cout << "Please enter a number in the range 1 - 9: ";
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin >> selectionCS;
					}
					
					//Hold variables for input
					char temp[51] = "";
					int tempInt = NULL;
					double tempDouble = NULL;
					
					//execute selectionCS
					switch (selectionCS) {
					case '1': cout << "Enter new title: ";
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin.getline(temp, 51);
						book[i].setTitle(temp);
						break;

					case '2': cout << "Enter new isbn: ";
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin.getline(temp, 14);
						book[i].setISBN(temp);
						break;

					case '3': cout << "Enter new author: ";
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin.getline(temp, 31);
						book[i].setAuthor(temp);
						break;

					case '4': cout << "Enter new publisher: ";
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin.getline(temp, 31);
						book[i].setPub(temp);
						break;

					case '5': cout << "Enter new date added: ";
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin.getline(temp, 11);
						book[i].setDateAdded(temp);
						
						break;

					case '6': cout << "Enter new quantity on hand: ";
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin >> tempInt;
						book[i].setQty(tempInt);
						break;

					case '7': cout << "Enter new wholesale price: ";
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin >> tempDouble;
						book[i].setWholesale(tempDouble);
						break;

					case '8': cout << "Enter new retail price: ";
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin >> tempDouble;
						book[i].setRetail(tempDouble);
						
						break;

					case '9': cout << "\n Edit request canceled\n\n";
						
						break;
					}
				//Open file object to append
				fstream invData(MYFILE, ios::in | ios::binary); // input to binary mode
				
				// open file to Append file to next available inventory location
				try{
            	     if (invData) {
				     	fstream invData(MYFILE, ios::out | ios::binary |ios::app);
				     	//write inventory file
				     	invData.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
				     	//Close file
				     	invData.close();
				     	invData.clear();
				     break;
            	     }
					//Throw error message if file does not exist
					 else
						 throw 0;

            	 } 
				catch (int x) { // catch and display error message
					cout << "Inventory file does not exsist! Error Code: " << x << endl;
					exit(1);
				}
			}
			else if (toupper(selectionYN) == 'N' && i == SIZE - 1) {
				break;
			}

		}
		else if (i == SIZE - 1 && book[i].bookMatch(search) == false) {
			cout << "\nBook is not in inventory\n\n";
			break;
		}
	}
}


//function to look up book
void lookUpBook() {
	char search[51];//char variable for searching title
	char selection;
	strUpper(search);

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Please enter the title: ";
	cin.getline(search, 51);
	strUpper(search);

	// Look up book
	for (int i = 0; i < SIZE; i++) {
		if (book[i].bookMatch(search)) { //find match

			//validate match
			cout << "Is this your book? " << book[i].getTitle() << "  Y/N: ";
			selection = getchar();
			cin.ignore();

			//validate user validation
			while (selection != 'Y' && selection != 'y' && selection != 'N' &&
				selection != 'n') {
				cout << "Enter Y or N";
				cin >> selection;
			}
			
			//output book info
			if (toupper(selection) == 'Y') {
				bookinfo(book[i].getTitle(), book[i].getISBN(), book[i].getAuthor(), book[i].getPublisher(), 
					book[i].getDateAdded(), book[i].getQty(), book[i].getWholesale(), book[i].getRetail());
				break;
			}
		}
		else if (i == SIZE - 1 && book[i].bookMatch(search) == false) {
			cout << "\nBook is not in inventory\n\n";
			
		}
	}
}



//function to delete book object
void deleteBook(){
	char search[51];//char variable for searching title
	char selection;
	strUpper(search);

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Please enter the title: ";
	cin.getline(search, 51);
	strUpper(search);


	for (int i = 0; i < SIZE; i++) {
		if(book[i].bookMatch(search)){ //find match
			
			//validate match
			cout << "Is this your book? " << book[i].getTitle() << "  Y/N: ";
			selection = getchar();

			//validate user validation
			while (selection != 'Y' && selection != 'y' && selection != 'N' &&
				selection != 'n'){
				cin >> selection;
			}
			if(toupper(selection) == 'Y'){
				bookinfo(book[i].getTitle(), book[i].getISBN(), book[i].getAuthor(), book[i].getPublisher(), 
					book[i].getDateAdded(), book[i].getQty(), book[i].getWholesale(), book[i].getRetail());
			
				//Output delete options
				cout << "Delete Book? (Y/N): ";
				selection = getchar();
				while (selection != 'Y' && selection != 'y' && selection != 'N' &&
					selection != 'n'){
					cin >> selection;
				}
				if (selection == 'Y' || selection == 'y') {
					book[i].removeBook();
					cout << "\nBook has been deleted.\n\n";
					
					//Open file object to append
					fstream invData(MYFILE, ios::in | ios::binary); // input to binary mode

					// open file to Append file to next available inventory location
					try{
            		     if (invData) {
					     	fstream invData(MYFILE, ios::out | ios::binary |ios::app);
					     	//write inventory file
					     	invData.write(reinterpret_cast<char *>(&book[i]), sizeof(book[i]));
					     	//Close file
					     	invData.close();
					     	invData.clear();
					     break;
            		     }
						//Throw error message if file does not exist
            		    else if(!invData)
            		        throw 0;
            		 }
            		 
					// catch and display error message
					catch (int x) {
						cout << "Inventory file does not exsist! Error Code: " << x << endl;
						exit(1);
					}
				}
				else {
					cout << "\nDeletion canceled\n\n";
					break;
				}
			}
		}
		else if (i == SIZE - 1 && book[i].bookMatch(search) == false) {
			cout << "\nBook not in inventory.\n\n";
		}
	}
}	
