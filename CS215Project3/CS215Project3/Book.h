#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string> 
#include <iostream>

using namespace std;

class Book{
public:
	//Book();
	Book(string t, int q, double p);
	void print();
	string title;
	int quantity;
	double price;
};

#endif /*BOOK_H*/