#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include <list>

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "STL-es2-listTest.h"

void printList(list<Item>& listRef)
{
	if (listRef.empty())
		cout << "La list e' vuota";
	else {
		for (list<Item>::iterator it = listRef.begin(); it != listRef.end(); it++) {
			cout << *it << " ";
		}
	}
}

int main() {

  LList<Item> L1; 
  list<Item>  stl_list;

  L1.append(Item(8));
  L1.append(Item(35));
  L1.append(Item(18));
  L1.append(Item(17));
  L1.append(Item(2));
  cout << "L1: "; lprint(L1);

  for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next()) {
	  stl_list.push_back(L1.getValue());
  }

  cout << "stl_list: "; printList(stl_list);
  
  list<Item>::iterator it = stl_list.begin();
  while (it != stl_list.end()) {
	  if ((*it).key() > 16) {
		  it = stl_list.erase(it); // elimina e it punta al successivo elemento
	  }
	  else {
		  ++it;  // it punta al successivo elemento
	  }
  }

  cout << endl << "stl_list: "; printList(stl_list);

  L1.clear();
  for (list<Item>::iterator it = stl_list.begin(); it != stl_list.end(); it++) {
	  L1.append(*it);
  };

  cout << endl << "L1: "; lprint(L1);

  return 0;
}