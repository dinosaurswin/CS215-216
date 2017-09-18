// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// Node class 
class Node {
    string data; 
    Node* next;
   public:
    Node() {}; 
    void SetData(string aData) { data = aData; }; 
    void SetNext(Node* aNext) { next = aNext; }; 
    string Data() { return data; }; 
    Node* Next() { return next; };
};
// List class 
class List { 
    Node *head;//first element in the list 
	int s;//size of the list
  public: 
    List() { head = NULL; s=0;}; 
	//Adding elements
	void push_back(string data); 
	void push_front(string data); 
	//Removing elements
	void pop_front();
	void pop_back();
	//geting variables
	int size();
	Node* front();
};
#endif
