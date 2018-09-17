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
#include "cashier.h"
#include "bookinfo.h"
#include "invmenu.h"
#include "reports.h"
#include "mainmenu.h"
#include <string>
#include <time.h>
#include <cctype>
#include "bookdata.h"
#include <fstream>


using namespace std;

//function prototypes
bool menuVerify(char, int);
bool isNumber(string);
void strUpper(char*);


//Data file name
const char MYFILE[] = "Inventory.dat";

//fstream object
fstream invData;

//Declare Array of book objects 
extern class InventoryBook book[SIZE];

int main() {
	/*Data stored at end of program session using .dat file. 
	Sync happens at main menu screen*/
	
	//Open file object
	invData.open(MYFILE, ios:: in | ios:: binary); // input to binary mode

	//Initialize records if file does not exist
	if(!invData){
		fstream invData(MYFILE, ios::out | ios::binary); //create file
	
														 
		//write blank inventory files
		for (int i = 0; i < SIZE; i++) {
			invData.write(reinterpret_cast<char *>(&book[0]), sizeof(book[0]));
		}
		

		invData.close(); //close file
		invData.clear();

		//prompt user to add inventory
		cout << "\n\n********Inventory Data File initialized. Please add Books.\n\n\n******** If you reached this in error contact your administrator.\n";
		invmenu();
	}
	
	//sync file with InventoryBook structure book
	else{
		for (int i = 0; i < SIZE; i++) {
			invData.seekg(i * sizeof(book), ios::beg); // seek next & write
			invData.read(reinterpret_cast<char*>(&book), sizeof(book)); // read data into book structures
			book[i];
		}
		invData.close(); // close file
		invData.clear();
	}


	// ********************** DRIVER ***********************
	cout << "************* This program is in development *********\n";
	cout << "************* Test data had been initialized *********\n";
	cout << "********************** V 0.4 - 6/17/18 ***************\n\n";
	

	char selection;
	do {
		//Output menu options
		cout << "_____________________________________________________________\n\n\n";
		cout << setw(30) << "Serendipity Booksellers\n";
		cout << setw(22) << "Main Menu\n\n";
		cout << setw(23) << "1. Cashier Module\n";
		cout << setw(34) << "2. Inventory Database Module\n";
		cout << setw(22) << "3. Report Module\n";
		cout << setw(14) << "4. Exit\n\n";
		cout << setw(24) << "Enter Your Choice: ";
		
		//Get menu option and validate
		cin >> selection;
		while (menuVerify(selection, 4) == false) {
			cout << "Please enter a number in the range 1 - 4: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> selection;
		}
		//execute selection
		switch (selection) {
		case '1': cashier();
			break;
		case '2': invmenu();
			break;
		case '3': reports();
			break;
		case '4': cout << "\nYou selected Exit\n\n";
		}
	} while (selection != '4');
	return 0;
}

/*function that accepts string and verifies it to be a valid number that
* falls within range
*/
bool menuVerify(char input, int range) {
	int x = input - '0';
	if (x > 0 && x <= range) {
		return true;
	}
	else
		return false;}

//Function that traverses a string to confirm it is a number
bool isNumber(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}


//converts each character in the char string to an uppercase letter.
void strUpper(char* str){
	while (*str != 0)
	{
		*str = toupper(*str);
		str++;
	}
}
