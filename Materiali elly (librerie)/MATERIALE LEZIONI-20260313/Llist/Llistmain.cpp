// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"


// find function for Items.
// Return true if "K" is in list "L", false otherwise
int find(List<Item>& L, int K) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (K == it.key()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

// find function for Items.
// Return true if "item" is in list "L", false otherwise
int find(List<Item>& L, const Item& item_to_search) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.key() == it.key()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

// Insert "it" at current position
void insert_ordered(List<Item>& L, const Item& it) {
	if (L.length() == 0)
	{
		L.insert(it);
		return;
	}
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		if (it.key() <= L.getValue().key())
		{
			L.insert(it);
			return;
		}
	}
	L.append(it);
}

// Main routine for linked list driver class
int main(int argc, char** argv) {

  LList<Item> L1;  
  Item temp;

  L1.insert(Item(39));
  cout << "1) L1: "; lprint(L1);
  L1.next();
  cout << "2) L1: "; lprint(L1);
  L1.insert(Item(9));
  L1.insert(Item(5));
  cout << "3) L1: "; lprint(L1);
  L1.append(Item(4));
  L1.append(Item(3));
  cout << "4) L1: "; lprint(L1);
  L1.insert(Item(2));
  cout << "5) L1: "; lprint(L1);
  L1.next();
  L1.next();
  cout << "6) L1: "; lprint(L1);
  L1.insert(Item(91));
  L1.insert(Item(8));
  cout << "7) L1: "; lprint(L1);
  L1.prev();
  L1.prev();
  L1.prev();
  L1.prev();
  cout << "8) L1: "; lprint(L1);
  L1.insert(Item(43));
  L1.insert(Item(22));
  cout << "9) L1: "; lprint(L1);
  L1.moveToEnd(); 
  cout << "10) L1: "; lprint(L1);
  //L1.remove(); // Errore asserzione
 
  L1.moveToPos(L1.length()-1);
  L1.remove(); // rimuovi in coda
  cout << "11) L1: "; lprint(L1);

  L1.moveToPos(4);
  cout << "12) L1: "; lprint(L1);
  L1.remove();
  Item toins(555);
  L1.insert(toins);
  cout << "13) L1: "; lprint(L1);

  Item  pippo(3);
  cout << pippo.key() << endl;
  L1.insert(pippo);
  cout << "14) L1: "; lprint(L1);
  cout << "15) L1: "; cout << "Size: " << L1.length() << endl;
  L1.clear();


  Item reftemp;
  L1.moveToStart();
  L1.insert(Item(39));
  L1.next();
  L1.insert(Item(9));
  L1.insert(Item(5));
  L1.append(Item(4));
  L1.append(Item(3));
  L1.append(Item(2));
  L1.append(Item(1));
  cout << "16) L1: "; lprint(L1);
  L1.moveToStart();

  int K=3;
  int found;
  Item to_search(3);
  if ((found=find(L1, K))<0)
     cout << "L1: Value " << K << " not found.\n";
  else cout << "L1: Found " << K << " in pos:" << found << endl;
  if ((found = find(L1, to_search))<0)
	  cout << "L1: Value " << to_search.key() << " not found.\n";
  else cout << "L1: Found " << to_search.key() << " in pos:" << found << endl;

  L1.moveToPos(found);
  cout << "17) L1: "; lprint(L1);

  K=33;
   if ((found=find(L1, K))<0)
    cout << "L1: Value " << K << " not found.\n";
  else cout << "L1: Found " << K << " in pos:" << found << endl;

  LList<float> L2;
  L2.moveToStart();
  L2.insert(1.1);
  L2.insert(2.3);
  cout << "18) L2: "; lprint(L2);
  L2.next();
  cout << "19) L2: "; lprint(L2);
  if (L2.currPos()<L2.length()) {
    float value = L2.getValue();
    cout << "L2 curr: " << value << endl;
	L2.remove();
  }
  else
    cout << "L2: Nothing found\n";
  cout << "20) L2: "; lprint(L2);


  L1.clear();
  L1.moveToStart();
  insert_ordered(L1, Item(30));
  insert_ordered(L1, Item(5));
  insert_ordered(L1, Item(14));
  insert_ordered(L1, Item(144));
  insert_ordered(L1, Item(20));
  insert_ordered(L1, Item(1));
  cout << "21) L1: "; lprint(L1);

  L1.reverse();
  cout << "22) L1: "; lprint(L1);
  L1.moveToEnd();
  cout << "23) L1: "; lprint(L1);

  cout << "That is all.\n";

  return 0;
}