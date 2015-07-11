#include <iostream>
#include <string>

using namespace std;

#include "Llist.h"

int main(){
	Llist<int> a;

	for(int i = 0; i < 10; i++){
		a.push_back(i);
	}

	for(int i = 10; i < 20; i++){
		a.prepend(i);
	}

	a.printList();

	Llist<string> b;
	if (b.isEmpty()){
		cout << "list is empty" << endl;
	}
	b.push_back("a");	b.push_back("b");	b.push_back("c");	b.push_back("d");
	b.prepend("e");b.prepend("f");b.prepend("g");b.prepend("h");b.prepend("i");
	if (!b.isEmpty()){
		cout << "list is not empty" << endl;
	}
	b.printList();
}
