// esercizio spese di magazzino

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "es4_ListTest.h"

int find_mese(List<mese>& L, int m) {
	mese it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (m == it.key()) return L.currPos();
	}
	return -1;
}


void bubblesort(List<mese>& L) {
	for (int i = 0; i< (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j> i; j--) {
			L.moveToPos(j);
			mese it_j = L.getValue();
			L.moveToPos(j - 1);
			mese it_jj = L.getValue();
			if (it_jj.getspesa_mensile()<it_j.getspesa_mensile())
			{
				L.moveToPos(j);
				mese removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}


// Main routine 
int main(int argc, char** argv) {

	LList<Item> Lspese;
	LList<mese> Lmesi;
	int mese_iniziale, mese_finale;
	float importo;

	ifstream myfile("spese.txt");

	if (myfile.is_open()) {
		while (myfile >> mese_iniziale >> mese_finale >> importo) {
			Item it(mese_iniziale,mese_finale,importo);
			Lspese.append(it);
		}
		myfile.close();
	}
	cout << "Lspese: "; lprint(Lspese);

	for (Lspese.moveToStart(); Lspese.currPos()<Lspese.length(); Lspese.next()) {
		Item it = Lspese.getValue();
		float contributo_mensile = (float) (it.getimporto() / (it.getmesef() - it.getmesei() + 1));
		cout << "contributo_mensile =" << contributo_mensile << endl;
		for (int j = it.getmesei(); j <= it.getmesef(); j++)
		{
		 int mese_trovato = find_mese(Lmesi, j);
		 if (mese_trovato ==-1)
		 {
			mese m(j);
			m.setspesa_mensile(contributo_mensile);
			Lmesi.append(m);
		 }
		 else
		 {
			 Lmesi.moveToPos(mese_trovato);
			 mese m=Lmesi.getValue();
			 m.setspesa_mensile(m.getspesa_mensile() + contributo_mensile);
			 Lmesi.remove();
			 Lmesi.insert(m);
		 }
	 }
	}

  cout << "Lmesi: "; lprint(Lmesi);
  bubblesort(Lmesi);
  cout << "Lmesi: "; lprint(Lmesi);

  cout << "That is all.\n";

  return 0;
}