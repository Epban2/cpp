#include <iostream>
#include <sstream>
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
			if ((it_jj.gettitolo()<it_j.gettitolo()) || (it_jj.gettitolo()==it_j.gettitolo() && it_jj.getcodice()<it_j.getcodice()))
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
int find(List<string>& L, const Item& item_to_search) {
	string it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.geteditore() == it) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

int main(int argc, char** argv) {
	  LList<Item> Llibri;
	  BST<Item, int> Alibri1;
	  BST<Item, int> Alibri2;
	  ifstream myfile("elenco_libri.txt");
	  string titolo,cod,editore,pr;
	  int codice;
	  int prezzo;
	  if (myfile.is_open()) {
		  while (getline(myfile, titolo, '/')) {
			  getline(myfile, cod, '/');
			  istringstream token(cod);
			  token >> codice;
			  getline(myfile, editore, '/');
			  getline(myfile, pr);
			  istringstream token2(pr);
			  token2 >> prezzo;
			  Item temp(titolo, codice, editore, prezzo);
			  if (titolo != "non valido")
				  Llibri.append(temp);
			  else
				  Alibri1.insert(temp);
		  }
	  }
	  else
	  {
		  cout << "Errore di apertura del file" << endl;
		  return -1;
	  }
	  myfile.close();

	  bubblesort(Llibri);
	  cout << endl << "Q1: stampa lista libri ordinata" << endl;
	  lprint(Llibri);
	 
	  Alibri1.balance();
	  cout << endl << "Q2: stampa albero prodotti (in-order)" << endl;
	  Alibri1.show(cout);
	  cout << endl << endl;
	  
	  Item it;
	  LList<string> Llast; // lista di appoggio in cui salvo gli editori già incontrati scorrendo Llibri dalla fine all'inizio 
	  int len=Llibri.length();
	  for (Llibri.moveToPos(len-1); len>0; Llibri.prev()) {
	   it = Llibri.getValue();
	   int ed_found = find(Llast, it);
	   if (ed_found == -1)
		   Llast.append(it.geteditore());
	   else
		   Item removed = Llibri.remove();
	   len--;
	  }
	
	  cout << endl << "Q3 stampa lista libri" << endl;
	  lprint(Llibri);

	  Alibri1.crea_albero_somme_nodi(Alibri2);
	  cout << endl << "Q4: stampa albero Alibri1 (in-order)" << endl;
	  Alibri1.show(cout);
	  cout << endl << "Q4: stampa albero Alibri2 (in-order)" << endl;
	  Alibri2.show(cout);

	  return 0;
  }