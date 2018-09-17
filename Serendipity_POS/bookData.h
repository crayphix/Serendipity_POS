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

#ifndef _BOOKDATA_H
#define _BOOKDATA_H

class BookData {
protected: 
    //Member Variables
	char bookTitle[51];
	char isbn[14];
	char author[31];
	char publisher[31];
   
public:
    //Default constructor
    BookData();
	
	//Overloaded constructor
	BookData(char newTitle[51], char newISBN[14], char newAuthor[31], char newPublisher[31]);

    // Destructor
    ~BookData();

    // Mutator Functions
    void setTitle(char*);
        //set book title

    void setISBN(char*);
        //set book ISBN

    void setAuthor(char*);
        //set book Author
        
    void setPub(char*);
        //Set publisher
	
	char* getTitle();
        // Returns Title
    
    char* getISBN();
        // Returns ISBN
    
    char* getAuthor();
        // Returns Author

    char* getPublisher();
        // Returns Publisher
    
    bool bookMatch(char*);
        // The function accepts a string as its argument and return true if the string is found in
        // the book title. If the string is not found in the book title, bookMatch should
        // return false.
};

class InventoryBook : public BookData {
protected:
    char dateAdded[11];
    int qtyOnHand;
    double wholesale;
    double retail;

public:
     //Default constructor
    InventoryBook();
    
    //Overloaded constructor
    InventoryBook(char newTitle[51], char newISBN[14], 
        char newAuthor[31], char newPublisher[31], char newDateAdded[11], 
        int newQtyOnHand, double newWholesale, double newRetail);

    // Destructor
    ~InventoryBook();

    void setDateAdded(char*);
        //Set date Added
    
    void setQty(int);
        //Set inv qty
    
    void setWholesale(double);
        // set book Wholesale price
        
    void setRetail(double);
        // Set book retail price
     
     bool isEmpty();
        // Determines if book is empty
    
    void removeBook();
    
    char* getDateAdded();
        // Returns DateAdded
        
    int getQty();
        // Returns Qty
     
    double getWholesale();
        // Returns Wholesale
     
    double getRetail();
        // Returns Retail
    
    int* getQtyPtr();
        // Return pointer to quantity location
    
    double* getWholesalePtr();
        // Return pointer to wholesale location
    
    char* getDateAddedPtr();
        // Return pointer to date Added
};

class SoldBook: public InventoryBook {
private:
     int qtySold;
     double subtotal;
     static double total;
 public:
	
    //Default Constructor
    SoldBook();

    //Overloaded Constructor
    SoldBook(char newTitle[51], char newISBN[14],
		char newAuthor[31], char newPublisher[31], char newDateAdded[11],
		int newQtyOnHand, double newWholesale, double newRetail, int thisQtySold);

	//Overloaded Constructor qty sold initilized to 0
	SoldBook(char newTitle[51], char newISBN[14],
		char newAuthor[31], char newPublisher[31], char newDateAdded[11],
		int newQtyOnHand, double newWholesale, double newRetail);

    //Destructor
    ~SoldBook();

    //get qty sold
    int getQtySold();

    //set qty Sold
    void setQtySold(int);

    //tax Calculated as qtySold times retail times taxRate. 
    //retail is inherited from InventoryBook.
    double getTax();

    //subtotal of the sale of a particular title. The subtotal is
    // calculated as retail times qtySold plus tax.
    double getSubTotal();

     //TaxRate Accessor
	 static const double taxRate() {
		 return 0.6;
	 }

};

#endif