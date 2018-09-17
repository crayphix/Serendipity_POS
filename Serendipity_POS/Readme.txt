______________________________________________
*****************Debugging Log****************
______________________________________________

6/20/18
- Worked on cleaning up Char validation and input

** The following functions still need to be debugged **
-editBook
-deleteBook
-addBook 
    Use lookUpBook as reference
_____________________________________________________________

6/22/18

-editBook, deleteBook, addBook debugged. Loop breaks needed to be fixed.

-Stubs for project 11 have been added to program

***finish proj 11 and 12 asignments****


_____________________________________________________________

7/1/18

**********Reports*******
DEBUGGED-reports do not terminate output when object not present



********Inventory******
-Delete froze system. possible error in visual studio did not occur second time
ONGOING -bug in lookUpBook stack overrunerror.


Week 5 Notes: 
	-Program runs properly. 
	-I am concerned I have been a little sloppy with my memory management. 
	-Unsure if global array solution is best for project. 

________________________________________________________________

7/7/18

******BookData*****
ADDED MEMBER FUNCTION
  bool bookMatch(char*);
        // The function accepts a string as its argument and return true if the string is found in
        // the book title. If the string is not found in the book title, bookMatch should
        // return false.

*******invmenu********
CHANGED lookUpBook & editBook
search title fragments with bookMatch

*******Reports*********
Updated Last week

___________________________________________________________________

7/24/18

clean up file syncing.

-Make syncFile class
	-open file
	-sync file
	-look up book in file
	-replace book in file 
	-delete book in file
	-delete all books in file

-Make validation Class
	-Validate is Y or N
	-Validate is Number
	-Validate is Char
	-Is number within range

_____________________________________________________________________

