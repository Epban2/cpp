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

void bubblesortC(List<Item>& L) {
	for (int i = 0; i< (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j> i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.getcognome()>=it_j.getcognome())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}

void bubblesortD(List<Item>& L) {
	for (int i = 0; i< (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j> i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.getcognome()<it_j.getcognome())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}

int main(int argc, char** argv) {
	  LList<Item> L1;
	  LList<Item> L2;
	  BST<Item, int> Astudenti;
	  ifstream myfile("elenco_studenti.txt");
	  string cognome,citta;
	  int matricola,eta;

	  if (myfile.is_open()) {
		  while (myfile >> cognome >> matricola >> citta >> eta) {
			  Item temp(cognome,matricola,citta,eta);
			  L1.append(temp);
			  L2.append(temp);
		  }
	  }
	  else
	  {
		  cout << "Errore di apertura del file" << endl;
		  return -1;
	  }
	  myfile.close();

	  bubblesortC(L1);
	  bubblesortD(L2);
	  cout << endl << "Q1: stampa lista L1 ordinata in modo crescente" << endl;
	  lprint(L1);
	  cout << endl << "Q1: stampa lista L2 studenti ordinata in modo decrescente" << endl;
	  lprint(L2);

	  Item it;
	  int K = 5;
	 
	  for (L1.moveToStart(); L1.currPos()<L1.length(); L1.next()) {
		  it = L1.getValue();
		  if ((L1.currPos()<K) || (L1.currPos()>=L1.length()-K))
		      Astudenti.insert(it);
		  else
		  {
		   if ((it.getcitta()=="Bologna") && (it.geteta()<23))
			    Astudenti.insert(it);
		  }
	  }

	  Astudenti.balance();
	  cout << endl << "Q2: stampa albero studenti (pre-order)" << endl;
	  Astudenti.show(cout);
	  cout << endl << endl;

	  Item it1,it2,it3;
	  int max_somma = -1;
	  int max_pos = -1;
	  for (L2.moveToStart(); L2.currPos()<=L2.length()-3; L2.next()) {
		  it1 = L2.getValue();
		  L2.next();
		  it2 = L2.getValue();
		  L2.next();
		  it3 = L2.getValue();
		  int somma_eta = it1.geteta() + it2.geteta() + it3.geteta();
		  L2.prev(); L2.prev();
		  if (somma_eta>=max_somma)
		  {
			  max_somma = somma_eta;
			  max_pos = L2.currPos();
		  }
	  }

	  L2.moveToPos(max_pos);
	  for (int i = 0; i < 3; i++)
		  Item removed=L2.remove();

	  cout << endl << "Q3: stampa lista L2 studenti ordinata in modo decrescente" << endl;
	  lprint(L2);
	  
	  cout << endl << "Q4: stampa somma matricole foglie sinistre (";
	  int somma_foglie_sinistre = Astudenti.somma_foglie_sinistre();
	  cout << ") =" << somma_foglie_sinistre << endl;

	  return 0;
  }