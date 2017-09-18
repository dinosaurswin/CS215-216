#include "Booklist.h"
#include <vector>

using namespace std;

Booklist::Booklist(){ 
	count = 0;//starts with no books
	BL;
}
Booklist::~Booklist(){}
void Booklist:: search(string t){
	for(size_t i=0; i<BL.size(); i++)//loops through the vecor
		if(BL[i].title == t){//if you find the title
			BL[i].print();//print out the books info
			return;//stop searching
		}
	cout<<"I'm sorry "<<t<<" is currently out of stock"<<endl;//cant find it
}
void Booklist:: insert(string t, int q, double p){
	count+=q;
	if(BL.size()==0){
		BL.push_back(Book(t,q,p));
		return;
	}
	//sort them when placed
	vector<Book> L;//temp vector 
	bool placed = false;//wheter or not the new book has been placed
	for(size_t i=0; i<BL.size(); i++){
		if(BL[i].title.size()>t.size()&& !placed){//if the new book is shorter
			L.push_back(Book(t,q,p));//place it here
			placed = true;//change the placed value
			L.push_back(BL[i]);//place the BL value
			continue;//move onto the next element
		}
		if(BL[i].title.size()<t.size() || placed){//the new book is longer or already placed
			L.push_back(BL[i]);//place the BL value
			continue;//move onto the next element
		}
		if(BL[i].title==t){//there is already a book in stock
			BL[i].quantity+=q;//add to the quantity
			placed = true;//change the placed value
			L.push_back(BL[i]);//place the BL value
			continue;//get outta here
		}
		//if its here then the sizes are equal
		for(size_t j=0; j<BL[i].title.size(); j++)//go through all the letters
			if(t.at(i)<BL[i].title.at(i)){//if the new book is less
				L.push_back(Book(t,q,p));//place it
				placed=true;//change placed value
				L.push_back(BL[i]);//place the BL value
				break;//gets out of the letters loop
			}
			else {
				L.push_back(BL[i]);//place the BL value
				break;//gets out of letters loop
			}
	}
	BL = L;//set the old vector to the new one
}
void Booklist:: remove(string t){
	vector<Book> L;//temp vector 
	for(size_t i=0; i<BL.size(); i++)//goes through the vector
		if(BL[i].title == t)//find the book
			count-=BL[i].quantity;//take out those from the total
		else//not the book we want
			L.push_back(BL[i]);
	BL=L;//make the old vector equal the temp vector

}
void Booklist:: print(){
	cout<<"-----------"<<count<<" Books in Stock-----------"<<endl;
	for(size_t i=0; i<BL.size(); i++)
		BL[i].print();
	cout<<"------------------------------------------------"<<endl;
}