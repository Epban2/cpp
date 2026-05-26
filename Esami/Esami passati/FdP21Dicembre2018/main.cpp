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

void merge(LList<Item>& Lm, LList<Item>& La, LList<Item>& Lb) {
	La.moveToStart();
	Lb.moveToStart();
	Item removed;
	int N = La.length();
	int M = Lb.length();
	for (int k = 0; k < N + M; k++)
	{
		if (La.currPos() == La.length())
		{
			removed = Lb.remove();
			Lm.append(removed);
			continue;
		}
		if (Lb.currPos() == Lb.length())
		{
			removed = La.remove();
			Lm.append(removed);
			continue;
		}
		if ((float)(La.getValue().getpasseggeri()) > ((float) Lb.getValue().getpasseggeri()))
			removed = La.remove();
		else
			removed = Lb.remove();
		Lm.append(removed);
	}
}

void mergesort(LList<Item>& Lm)
{
	Lm.moveToStart();
	if (Lm.length() < 2) return;
	LList<Item> La, Lb;
	Item removed;
	int N = Lm.length();
	for (int k = 0; k<N; k++) {
		removed = Lm.remove();
		if (k % 2) La.append(removed);
		else Lb.append(removed);
	}
	mergesort(La);
	mergesort(Lb);
	merge(Lm, La, Lb);
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
	  LList<Item> L1,L2;
	  BST<Item, string> Anavi;
	  ifstream myfile("navi.txt");

	  string nome="";
	  string compagnia = "";
	  int passeggeri;
	  float velocita;

	  if (myfile.is_open()) {
		  while (myfile >> nome >> passeggeri >> velocita >> compagnia) {
			  Item it(nome,passeggeri,velocita,compagnia);
		      L1.append(it);
			  Anavi.insert(it);
		  }
	  }
	  else
	  {
		  cout << "Errore di apertura del file" << endl;
		  return -1;
	  }
	  myfile.close();

	  // 1) caricare elementi da file in una lista L1 (in append) e in un albero Anavi, stampare L1 e Anavi (con visita in-order)
	  cout << "Q1: stampa lista L1" << endl;
	  lprint(L1);
	  cout << endl << "Q1: stampa albero Anavi (in-order)" << endl;
	  Anavi.show(cout);
	  	  
	  // 2) Decrementare di -0.5 tutti i valori di velocità di Anodi
	  Anavi.decrease_speed();
	  cout << endl << endl << "Q2: stampa albero Anavi (in-order)" << endl;
	  Anavi.show(cout);

	  // 3) creare una seconda lista L2 a partire da L1 che contenga un solo elemento per ogni compagnia presente in L1, ogni elemento deve contenere la somma di tutti i passeggeri di tutte le navi di L1 di quella compagnia e "---" nel campo nome, ordinare la lista L2 per numero di passeggeri decrescente, stampare L2
	  for (L1.moveToStart(); L1.currPos()<L1.length(); L1.next())
	  {
		  Item it = L1.getValue();
		  int found = find(L2, it);
		  if (found != -1)
		  {
			  L2.moveToPos(found);
			  Item removed=L2.remove();
			  removed.setpasseggeri(removed.getpasseggeri()+it.getpasseggeri());
			  L2.insert(removed);
		  }
		  else
		  {
			  it.setnome("---");
			  it.setvelocita(-1);
			  L2.insert(it);
		  }
	  }
	  mergesort(L2);
	  cout << endl << endl << "Q3: stampa lista L2" << endl;
	  lprint(L2);

	  // 4) eliminare da Anavi tutti gli elementi che appartengono alla compagnia che ha il numero maggiore di passeggeri in L2
	  L2.moveToStart();
	  Item da_eliminare = L2.getValue();
	  Item found = Anavi.search(da_eliminare.key());
	  while (!found.null())
	  {
		  Anavi.remove(da_eliminare);
		  found = Anavi.search(da_eliminare.key());
	  }
	  cout << endl << "Q4: stampa albero Anavi (in-order)" << endl;
	  Anavi.show(cout);

	  cout << endl;
	  system("pause");
	  return 0;
  }