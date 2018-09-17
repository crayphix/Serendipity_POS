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

#ifndef _MAINMENU_
#define _MAINMENU_
#include <string>

extern int main();

//Constants
const int SIZE = 20; //Size of arrays


//Data file name
extern const char MYFILE[];


extern bool menuVerify(char, int);
extern bool isNumber(std::string);
extern void strUpper(char*);


#endif

