#pragma once
#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <string>
#include <vector>
#include <iostream>
#include "Book.h"

class Booklist{
 public:
	 // Constructor
	 Booklist();
	 // Destructor
	 ~Booklist();
	 /* Search for the book with the given title t
	 If the book is found, print its title,
	 quantity in stock and price; otherwise report
	 the book is not in the stock.*/
	 void search(string t);
	 /* Insert a new book record into the array.
	 The book has title t, number of copies in stock
	 is q, and price is p.
	 Note that the vector of books should be maintained
	 in the lexicographical order of the book titles.
	 If the book title already exists in the list,
	 then upgrade the record with q and p.*/
	 void insert(string t, int q, double p);
	 /* Delete a book record, whose book title is t,
	 If the book is not in the list, do nothing.*/
	 void remove(string t);
	 /* Print the book records in the vector in the
	 lexicographical order of book titles*/
	 void print();
private:
	vector<Book> BL; // vector of book records
	int count; // total number of books in stock
};

#endif /*BOOKLIST_H*/