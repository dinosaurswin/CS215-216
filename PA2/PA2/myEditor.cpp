//course: CS216-004
//Project: Programming Assignment 2
//Date: 03/1/2015
//Purpose: to make a simple line editor
//Author: Jacob Richardson

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(int argc, char* argv[]){	
	// Check whether the user types the command correctly
	if (argc != 2){
		cout << "Invalid command!" << endl;
		cout << "Usage: " << argv[0] << " filename" << endl;
		return 1;
	}

	// Read the original file content if the file exists
	fstream inData;
	inData.open(argv[1], ios::in);// open the specified file for reading. 
	
	List lines = List();
	//list<string> lines;
	if (!inData.fail()){
		string str="";
		while(!inData.eof()){//goes until the end of the file
			getline(inData, str);
			lines.push_back(str);
			cout<<lines.size()<<"> "<<str<<endl;
		}
	}

	while(true){
		cout<<">  ";
		string input;
		int n;
		cin>>input;
		List temp = List();
		//list<string> temp;//temp list for inserting/deleting/printing
		int s=lines.size();//the # of lines

		if(input=="I"||input=="D"){//if there is a # to read in too
			cin>>n;
			if(input=="I"){//insert line n
				string text;//the text for the inserted line
				cout<<n<<"> ";
				cin.ignore();
				getline(cin,text);
				if(n<=lines.size()){
					for(int i=1; i<s+1; i++){//
						if(i==n)//at the insertion point
							temp.push_back(text);
						temp.push_back(lines.front()->Data());
						lines.pop_front();
					}
					lines = temp;
					//lines.swap(temp);
				}
				else{
					for(int i=lines.size(); i<n-1;i++)
						lines.push_back("");
					lines.push_back(text);
				}
				continue;
			}
			if(input=="D"){//delete the text at line n
				if(n>lines.size()){
					cout<<"Sorry, unable to delete a nonexistent line."<<endl;
					continue;
				}
				for(int i=1; i<s+1; i++){//
					if(i!=n)//at the insertion point skip the element
						temp.push_back(lines.front()->Data());
					lines.pop_front();
				}
				lines= temp;
				//lines.swap(temp);
				continue;
			}
		}
		if(input=="L"){
			for (int i = 1; i <s+1; i++){
				cout<<i<<"> "<<lines.front()->Data()<<endl;
				temp.push_back(lines.front()->Data());
				lines.pop_front();
			}
			lines = temp;
			//lines.swap(temp);
			continue;
		}
		if(input == "Q")
			break;
	}

	inData.close();
	// Clear the original content of the file by using ios::out mode
	// and save new content into the file
	fstream outData;
	outData.open(argv[1], ios::out);	// open the specified file for writing
	int s=lines.size();
	for (int i=0; i < s; i++){
		outData << lines.front()->Data() << endl;
		lines.pop_front();
	}
	outData.close();
	cout<<"Thank you for using myEditor"<<endl;
	return 0;
}