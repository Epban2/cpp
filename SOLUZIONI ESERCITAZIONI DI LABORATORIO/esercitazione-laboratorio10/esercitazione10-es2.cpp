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
#include "esercitazione10-es2-listTest.h"

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
  LList<list<Item> >  lista_di_liste;
  list<Item> L1,L2,L3;

  L1.push_back(Item(8));
  L1.push_back(Item(35));
  L1.push_back(Item(18));
  L1.push_back(Item(17));
  L1.push_back(Item(2));
  cout << "L1: "; printList(L1);

  L2.push_back(Item(1));
  L2.push_back(Item(25));
  L2.push_back(Item(11));
  cout << endl << "L2: "; printList(L2);

  L3.push_back(Item(80));
  L3.push_back(Item(3));
  cout << endl <<"L3: "; printList(L3);
  cout << endl;

  lista_di_liste.append(L1);
  lista_di_liste.append(L2);
  lista_di_liste.append(L3);

  lista_di_liste.moveToStart();
  int max = lista_di_liste.getValue().front().key();
  for (lista_di_liste.moveToStart(); lista_di_liste.currPos() < lista_di_liste.length(); lista_di_liste.next()) {
	  list<Item> ls = lista_di_liste.getValue();
	  for (list<Item>::iterator it = ls.begin(); it != ls.end(); it++) {
		  if ((*it).key() > max)
			  max = (*it).key();
	  };

  }

  cout << "numero massimo: " << max;
  
  return 0;
}