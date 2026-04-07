//Scrivere una funzione che elimini da una lista singolarmente concatenata contenente interi tutti i numeri duplicati. La  lista non è ordinata. 

// First, include all the standard headers that we need
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include doubly linked node implementation
#include "link.h"

// Include doubly linked list implementation
#include "llist.h"

#include "ListTest.h"

// Main routine
int main(int argc, char** argv) {

  LList<Item> L1;

  L1.append(Item(33));
  L1.append(Item(7));
  L1.append(Item(10));
  L1.append(Item(33));
  L1.append(Item(21));
  L1.append(Item(35));
  L1.append(Item(16));
  L1.append(Item(7));
  L1.append(Item(33));
  L1.append(Item(11));
  L1.append(Item(28));
  L1.append(Item(33));
  L1.moveToStart();
  cout << "L1: "; lprint(L1);
 
  int position = 0;
  while (L1.currPos()<L1.length()) {
	  Item curvalue = L1.getValue();
	  L1.next();
	  while (L1.currPos()<L1.length()) {
		  if (curvalue.key() == L1.getValue().key())
			  L1.remove();
		  else
			  L1.next();
	  }
	  L1.moveToPos(position);
	  L1.next();
	  position += 1;
  }
  cout << "L1: "; lprint(L1);
  return 0;
}