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

#ifndef _BOOKINFO_H
#define _BOOKINFO_H
#include <string>

extern int bookinfo(char bookTitle[51], char isbn[14], char author[31],
	char publisher[31], char dateAdded[11], int qtyOnHand, double wholesale, double retail);

extern int bookinfo(char bookTitle[51], char isbn[14], int qtyOnHand, double wholesale);

extern int bookinfo(char bookTitle[51], char isbn[14], double retail, int qtyOnHand);

extern int bookinfo(char bookTitle[51], char isbn[14], int qtyOnHand);

extern int bookinfo(char bookTitle[51], char isbn[14], char dateAdded[11], int qtyOnHand, double wholesale);

#endif

