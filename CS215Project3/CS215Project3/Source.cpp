/* Jacob Richardson
CS 215 sec 003
11/15/14
The purpose of this programming assignment is
• to design your own class, from which you create your objects
*/

#include <iostream>
#include <string>
#include <vector>
#include "Booklist.h"
#include "Book.h"

using namespace std;

int main(){
	Booklist B = Booklist();//the universities booklist
	cout<<"This	application	stores a list of books in stock	for	UK bookstore."<<endl;
	while(true){//repeat indefineitly
		int choice =0;//what option they choose
		//list out options
		cin.clear();
		cout<<"Select from:"<<endl<<"1. Insert a book record"<<endl<<"2. Delete a book record"<<endl<<"3. Print the book list"<<endl<<"4. Search the book list"<<endl<<"5. Quit"<<endl;
		cin>>choice;//read in what they want
		if(cin.fail()){
			cin.clear();
			cout<<"Please select a valid option"<<endl;
			continue;
		}
		if(choice == 1){//insert book record
			string title="";
			cin.clear();
			cout<<"Please enter the title of the book:";
			cin>>title;//read in the title
			if(cin.fail()){
				cin.clear();
				cout<<"Please enter a valid option"<<endl;
				continue;
			}
			int quant=0;
			cin.clear();
			cout<<"Quantitiy in stock:";
			cin>>quant;//read in quantitiy
			if(cin.fail()){
				cin.clear();
				cout<<"Please enter a valid option"<<endl;
				continue;
			}
			double price=0;
			cout<<"Price:";
			cin>>price;//read in the price
			if(cin.fail()){
				cin.clear();
				cout<<"Please enter a valid option"<<endl;
				continue;
			}
			cout<<title;
			B.insert(title,quant,price);//put the book into the book list
		}
		if(choice == 2){//delete book record
			string title ="";
			cin.clear();
			cout<<"Enter the title of the book you want to delete:";
			cin>>title;//read in the title
			B.remove(title);//get the booklist to remove the book
		}
		if(choice == 3){//print book list
			B.print();
		}
		if(choice == 4){//search booklist
			string title ="";
			cin.clear();
			cout<<"Enter the title of the book you want to search for:";
			cin>>title;//read in the title
			B.search(title);//search
		}
		if(choice == 5)//quit
			break;//breaks out of the infinite loop
	}
	
	system("pause");
	return 0;
}