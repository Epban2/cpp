//Definire una  lista  concatenata composta  da oggetti Item che contengono ciascuno due stringhe: una stringa abbreviata di due lettere (ad  esempio  TO,  MI,  PR)  e un stringa che contiene la parola estesa (ad esempio “Torino”, “Milano”) corrispondente. Scrivere una funzione che ricevendo come parametri un riferimento alla lista, una abbreviazione e la corrispondente parola estesa cerchi l’abbreviazione nella lista e
//a) restituisca 0 se esiste un elemento che possiede la parola estesa e l’abbreviazione 
//b) restituisca 1 se non esiste un elemento che possiede la parola estesa e l’abbreviazione e inserisca un nuovo Item in coda alla lista che contenga la parola estesa e l’abbreviazione
//c) restituisca 2 se l‘abbreviazione è presente ma ad essa corrisponde una parola differente.  La parola estesa dell’elemento della lista deve  essere sostituita da quella passata come parametro.  

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "esercitazione4-es2-ListTest.h"

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

// findabbr
int findabbr(List<Item>& L1, Item abbr_it)
{
	int pos = find(L1, abbr_it);
	if (pos == -1)
	{
		L1.append(abbr_it);
		return 1;
	}
	else
	{
		Item it;
		L1.moveToPos(pos);
		it = L1.getValue();
		if (it.get_parola() != abbr_it.get_parola())
		{
			L1.remove();
			it.set_parola(abbr_it.get_parola());
			L1.insert(it);
			return 2;
		}
		else
		{
			return 0;
		}
	}
}


// Main routine for linked list driver class
int main(int argc, char** argv) {

  LList<Item> L1;  

  L1.append(Item("MI","Milano"));
  L1.append(Item("TO","Torino"));
  L1.append(Item("PR","Verona"));
  cout << "L1: "; lprint(L1);

  Item temp("TO", "Torino");
  int ret = findabbr(L1, temp);
  cout << ret << endl;
  cout << "L1: "; lprint(L1);

  Item temp2("GE", "Genova");
  ret = findabbr(L1, temp2);
  cout << ret << endl;
  cout << "L1: "; lprint(L1);

  Item temp3("PR", "Parma");
  ret = findabbr(L1, temp3);
  cout << ret << endl;
  cout << "L1: "; lprint(L1);

  return 0;
}