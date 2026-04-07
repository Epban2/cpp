//Scrivere un programma in grado di fondere due liste singolarmente concatenate di interi L1, L2 (non ordinate) in una singola lista L3 ordinata in modo decrescente.
//Suggerimento: scrivere una funzione “fondiliste” che utilizzi al suo interno la funzione insert_ordered vista a lezione e che accetti come parametri in ingresso i riferimenti alle liste L1, L2, L3.
//Esempio: L1= {5, 1, 3}, L2= {10, 12, 7, 2}, L3= {12, 10, 7, 5, 3, 2, 1}


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"

// Insert "it" at current position
void insert_ordered(List<Item>& L, const Item& it) {
	if (L.length() == 0)
	{
		L.insert(it);
		return;
	}
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		if (it.key() > L.getValue().key()) // ordinamento decrescente
		{
			L.insert(it);
			return;
		}
	}
	L.append(it);
}

// fondiliste
void fondiliste(List<Item>& L1, List<Item>& L2, List<Item>& L3)
{
	Item it;

	for (L1.moveToStart(); L1.currPos()<L1.length(); L1.next()) {
		it = L1.getValue();
		insert_ordered(L3, it);
	}

	for (L2.moveToStart(); L2.currPos()<L2.length(); L2.next()) {
		it = L2.getValue();
		insert_ordered(L3, it);
	}

	L3.moveToStart();
}


// Main routine for linked list driver class
int main(int argc, char** argv) {

  LList<Item> L1;  
  LList<Item> L2; 
  LList<Item> L3; 

  Item temp;

  L1.append(Item(5));
  L1.append(Item(1));
  L1.append(Item(3));
  cout << "L1: "; lprint(L1);

  L2.append(Item(10));
  L2.append(Item(12));
  L2.append(Item(7));
  L2.append(Item(2));
  cout << "L2: "; lprint(L2);

  fondiliste(L1, L2, L3);
  cout << "L3: "; lprint(L3);

  return 0;
}