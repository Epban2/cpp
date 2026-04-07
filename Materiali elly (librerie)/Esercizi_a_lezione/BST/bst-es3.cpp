#include <iostream>
#include <stdlib.h>
#include "item-es3.h"
#include "bst-es3.h"
#include <time.h>  // Used by timing functions

int main(int argc, char *argv[])
  { 
    BST<Item, Key> bst;
	Item el;
	el.setinfo(1.1);
	el.keyval = 25;
	bst.insert(el);
	el.keyval = 15;
	bst.insert(el);
	el.keyval = 40;
	bst.insert(el);
	el.keyval = 10;
	bst.insert(el);
	el.keyval = 18;
	bst.insert(el);
	el.keyval = 35;
	bst.insert(el);
	el.keyval = 45;
	bst.insert(el);
	el.keyval = 5;
	bst.insert(el);
	el.keyval = 17;
	bst.insert(el);
	el.keyval = 20;
	bst.insert(el);
	el.keyval = 44;
	bst.insert(el);
	el.keyval = 49;
	bst.insert(el);
  
	cout << endl;  bst.show(cout); cout << endl;

	Key x=102;
	//Key x=20;
	bst.findPS(x);
  }
