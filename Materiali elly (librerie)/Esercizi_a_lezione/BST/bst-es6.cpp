#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "item-es3.h"
#include "bst-es6.h"
#include <time.h>  // Used by timing functions

int main(int argc, char *argv[])
  { 
    BST<Item, Key> bst;
	Item it;
	int key;
	float val;
	ifstream myfile("LUT_cos.txt");
	if (myfile.is_open()) {
		while (myfile >> key >> val) {
			it.setkey(key);
			it.setinfo(val);
			bst.insert(it);
		}
		myfile.close();
	}

	bst.balance();
	cout << endl;  bst.show(cout); cout << endl;
	
	cout << "insert a key" << endl;
	cin >> key; //353
	Item found=bst.search(key);
	if (!found.null())
	{
	 cout << "found element: ";
	 found.show(cout);
    }
	else
	{
		Item prev, next;
		bst.findPS(key, prev, next);
		if ((!prev.null()) && (!next.null()))
		{
		 float interpolation = prev.getinfo()+ ((float)(key-prev.key())/ (float)(next.key()-prev.key()))*(next.getinfo()-prev.getinfo());
		 cout << "interpolated value: " << interpolation;
		}
		else
			cout << "NULL" << endl;
	}
  }