#include <string>
#include "Book.h"

using namespace std;

/*Book::Book(){ 
	title="";
	quantity=1;
	price=0;
}*/
Book::Book(string t, int q, double p){ 
	title=t;
	quantity=q;
	price=p;
}
void Book:: print(){
	cout<<"Title:"<<title<<" # avaliable:"<<quantity<<" price: $"<<price<<endl;
}
