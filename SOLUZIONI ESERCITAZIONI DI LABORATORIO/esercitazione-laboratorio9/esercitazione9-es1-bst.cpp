#include <iostream>
#include <stdlib.h>
#include "esercitazione9-es1-item.h"
#include "esercitazione9-es1-bst.h"
#include <time.h>  // Used by timing functions
#include <fstream>

int main(int argc, char *argv[])
  { 
	
    BST<Item, int> bst;
	BST<Item, int> bst2;
	string str;
	int k;

	ifstream myfile("info.dat");
	if (myfile.is_open()) {
		while (myfile >> k >> str) {
			Item v(str, k);
			bst.insert(v);
		}
	}
	myfile.close();

	cout << "st Tree" << endl;
	bst.show(cout); cout << endl;

	bst.balance();
	cout << "st Balanced Tree" << endl;
	bst.show(cout); cout << endl;

	cout << "Inserire coppie ID stringa (ID negativo per terminare)" << endl;
	do {
		cin >> k >> str;
		Item v(str,k);
		if (v.key()>=0)
		 bst2.insert(v);
	} while (k >= 0);

	cout << endl << "st2 Tree" << endl;
	bst2.show(cout); cout << endl;

	bst2.balance();
	cout << "st2 Balanced Tree" << endl;
	bst2.show(cout); cout << endl;

	LList<Item> L1;
	bst.merge(bst2,L1);
	cout << "Lista: "; lprint(L1);
  }