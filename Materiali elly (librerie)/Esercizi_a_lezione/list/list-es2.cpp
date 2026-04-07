//Scrivere una funzione membro della classe Alist per invertire una lista.

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

void Assert(bool val, string s);

// Include the array-based list template code
#include "list-es2-alist.h"

// Generic list test commands
#include "ListTest.h"

// Main routine for array-based list driver class
int main(int argc, char** argv) {

	AList<Item> L1;
	Item temp;

	L1.insert(Item(39));
	L1.insert(Item(2));
	L1.insert(Item(15));
	L1.insert(Item(111));
	L1.insert(Item(10));
	L1.insert(Item(111));
	cout << "L1: "; lprint(L1);

	L1.reverse();
	cout << "L1: "; lprint(L1);

	return 0;
}