#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

#include "item.h"
#include "bst.h"

#include "llist.h"
#include "ListTest.h"

void bubblesort(List<Item>& L) {
	for (int i = 0; i< (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j> i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.key()<=it_j.key())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
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

int main(int argc, char** argv) {
	  LList<Item> Lprodotti;
	  BST<Item, string> Aprodotti;
	  ifstream myfile("prodotti.txt");
	  string nome;
	  int categoria;
	  int numero;
	  if (myfile.is_open()) {
		  while (myfile >> nome >> categoria >> numero) {
			  Item temp(nome, categoria, numero);
			  int trovato = find(Lprodotti, temp);
			  if (trovato!=-1)
			  {
				  Lprodotti.moveToPos(trovato);
				  Item old = Lprodotti.getValue();
				  old.setnumero(old.getnumero() + numero);
				  Lprodotti.remove();
				  Lprodotti.insert(old);
			  }
			  else
				  Lprodotti.insert(temp);
		  }
	  }
	  else
	  {
		  cout << "Errore di apertura del file" << endl;
		  return -1;
	  }
	  myfile.close();

	  bubblesort(Lprodotti);
	  cout << endl << "stampa lista prodotti ordinata" << endl;
	  lprint(Lprodotti);

	  Item it;
	  for (Lprodotti.moveToStart(); Lprodotti.currPos()<Lprodotti.length(); Lprodotti.next()) {
		  it = Lprodotti.getValue();
		  Aprodotti.insert(it);
	  }
	  Aprodotti.balance();
	  cout << endl << "stampa albero prodotti (post-order)" << endl;
	  Aprodotti.show(cout);
	  cout << endl << endl;
	
	  Lprodotti.moveToStart();
	  while (Lprodotti.currPos()<Lprodotti.length()) {
		  it = Lprodotti.getValue();
		  if (it.getcategoria() <= 3)
		  {
			  int currpos = Lprodotti.currPos();
			  Lprodotti.moveToStart();
			  Lprodotti.insert(it);
			  Lprodotti.moveToPos(currpos + 1);
			  Lprodotti.remove();
		  }
		  else
			  Lprodotti.next();
	  }

	  cout << endl << "stampa lista prodotti ri-organizzata" << endl;
	  lprint(Lprodotti);

	  cout << endl << "foglie dell'albero con meno di 25 pezzi: ";
	  int numfoglie = Aprodotti.contafoglie();
	  cout << " (totale="<< numfoglie << ")";

	  return 0;
  }