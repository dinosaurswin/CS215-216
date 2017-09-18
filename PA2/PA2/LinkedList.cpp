#include "LinkedList.h"
using namespace std;

int List::size(){return s;}
Node* List::front(){return head;}
void List::push_back(string data) {
	// Create a new node to insert
    Node* newNode = new Node();
    newNode->SetData(data); 
    newNode->SetNext(NULL);
    // Create a pointer for insertion
    Node *tmp = head; 
    if ( tmp != NULL ) {//there are some nodes already
		while ( tmp->Next() != NULL ) {//go to the end of the list
            tmp = tmp->Next();
        }
        //Make the old last node point to the new last node
        tmp->SetNext(newNode);
     }
     else {//Its the first node
         head = newNode;
     }
	s++;
}
void List::pop_back(){
	if(head == NULL)//nothing to pop
		return;
    // Create a pointer
    Node *tmp = head; 
	while ( tmp->Next()->Next() != NULL ) {//go to the end of the list -1
            tmp = tmp->Next();
	}
    tmp->SetNext(NULL);//set the second to last node to point at nothing instead of the last node
	s--;
}
void List::push_front(string data) {
	// Create a new node to insert
    Node* newNode = new Node();
    newNode->SetData(data); 
	newNode->SetNext(head);//make the new node point to the old first node
	head = newNode;//make the new node the first node
	s++;
}
void List::pop_front() {
	if(head==NULL)//theres nothing to pop
		return;
    // Create a new node to insert
	Node* temp = head;
	head = head->Next();//make the head the next element
	temp->SetNext(NULL);//set the old head to point at nothing
	s--;
}