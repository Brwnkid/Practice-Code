#include <iostream>
#include "Llist.h"

using namespace std;

int main(){
	Llist<int> a;

	for(int i = 0; i < 10; i++){
		a.push_back(i);
	}

	for(int i = 10; i < 20; i++){
		a.prepend(i);
	}

	for(int i = 0; i < 20; i++){
		cout << a.getAt(i) << endl;
	}
}