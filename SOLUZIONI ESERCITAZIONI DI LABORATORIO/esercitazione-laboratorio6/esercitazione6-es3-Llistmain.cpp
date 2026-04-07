// Linked list class test program

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "esercitazione6-es3-listTest.h"

void insertionsort(List<Item>& L) {
	Item it_temp;
	Item it_curr;
	for (int i = 1; i<L.length(); i++) {
		L.moveToPos(i);
		it_temp = L.getValue();
		for (int j = 0; j<i; j++) {
			L.moveToPos(j);
			it_curr = L.getValue();
			if (it_temp.key() >= it_curr.key())
			{
				L.moveToPos(i);
				L.remove();
				L.moveToPos(j);
				L.insert(it_temp);
				break;
			}
		}
	}
}

// Main routine 
int main(int argc, char** argv) {

  // Declare some sample lists
  LList<Item> L1;  

  L1.insert(Item(5));
  L1.insert(Item(4));
  L1.insert(Item(3));
  L1.insert(Item(2));
  L1.insert(Item(1));
  L1.insert(Item(100));
  L1.insert(Item(91));
  L1.insert(Item(8));
  L1.insert(Item(43));
  L1.insert(Item(22));
  L1.insert(Item(2));
  L1.insert(Item(0));
  L1.insert(Item(60));
  cout << "L1: "; lprint(L1);
  insertionsort(L1);
  cout << "L1: "; lprint(L1);

  cout << "That is all.\n";

  return 0;
}