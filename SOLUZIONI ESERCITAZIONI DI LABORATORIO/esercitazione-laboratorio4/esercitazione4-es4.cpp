//Scrivere un programma che crei una lista contenente oggetti Item con valori interi. 
//Si scriva una funzione che ricevendo in ingresso un riferimento alla lista la modifichi, memorizzando nell’ultimo nodo il prodotto del penultimo ed ultimo nodo, nel penultimo il prodotto del terzultimo e del penultimo e così via. 
//Il primo elemento della lista non deve essere modificato. Ad esempio, una lista contenente la sequenza di interi 4 6 2 3 9 verrà modificata dalla funzione nella lista 4 24 12 6 27.
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

const int N = 3;


// compute_products
void compute_products(List<Item>& L) {
	Item it, it_prev;
	for (L.moveToPos(L.length() - 1); L.currPos()>0; L.prev()) {
		L.prev();
		it_prev = L.getValue();
		L.next();
		it = L.getValue();
		L.remove();
		Item prod(it.key()*it_prev.key());
		L.insert(prod);
	}
}


// Main routine for linked list driver class
int main(int argc, char** argv) {

  LList<Item> L1;  
  Item it;

  L1.append(Item(4));
  L1.append(Item(6));
  L1.append(Item(2));
  L1.append(Item(3));
  L1.append(Item(9));
  cout << "L1: "; lprint(L1);

  compute_products(L1);
  cout << "L1: "; lprint(L1);

  return 0;
}