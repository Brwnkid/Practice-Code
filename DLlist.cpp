#include <iostream>
#include <string>

using namespace std;

#include "DLlist.h"

int main(){
	DLlist<int> a;

	for(int i = 0; i < 10; i++){
		a.push_back(i);
	}

	for(int i = 10; i < 20; i++){
		a.prepend(i);
	}

	a.printList();

	DLlist<string> b;
	if (b.isEmpty()){
		cout << "list is empty" << endl;
	}
	string name = "Mitesh";
	string code = "What!?";
	b.push_back(name);
	b.prepend(code);
	cout << "Number of items in list: " << b.size() << endl;
	b.printList();
}
