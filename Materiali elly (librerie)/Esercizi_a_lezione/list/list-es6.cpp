//Scrivere un algoritmo per invertire una lista singolarmente concatenata che utilizzi i metodi moveToPos e remove

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "listTest.h"

// Main routine for linked list driver class
int main(int argc, char** argv) {

	LList<Item> L1;

	L1.append(Item(35));
	L1.append(Item(118));
	L1.append(Item(1));
	L1.append(Item(17));
	L1.append(Item(13));
	L1.append(Item(8));
	L1.append(Item(2));
	L1.append(Item(220));
	cout << "L1: "; lprint(L1);

	Item it1, it2;
	for (int i=0; i<L1.length()/2; i++) {
		L1.moveToPos(i);
		it1 = L1.getValue();

		L1.moveToPos(L1.length()-i-1);
		it2 = L1.getValue();

		L1.moveToPos(i);
		L1.remove();
		L1.insert(it2);

		L1.moveToPos(L1.length() - i - 1);
		L1.remove();
		L1.insert(it1);
	}
	L1.moveToStart();
	cout << "L1: "; lprint(L1);

	return 0;
}